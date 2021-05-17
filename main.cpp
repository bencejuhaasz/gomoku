#include "widget.hpp"
#include "graphics.hpp"
#include "field.hpp"

using namespace genv;

class GameMaster {
  bool turn_cross = true;
  std::vector<std::vector<field*>> fields;
  std::vector<std::vector<widget*>> widgets;
public:
  bool check4win() {
    int state=0;
    int cnt = 0;

    for (size_t i = 0; i < 15; i++) {
      for (size_t j = 0; j < 15; j++) {
        //horizontal, cross
        if (fields[i][j]->get()==1) {
          for (size_t h = 1; h <= 4; h++) {
            if (fields[i+h][j]->get()==1) {
              cnt++;
            }
          }
          if (cnt>=4) {
            return true;
          }
          cnt = 0;
        }
        //horizontal,circle
        if (fields[i][j]->get()==2) {
          for (size_t h = 1; h <= 4; h++) {
            if (fields[i+h][j]->get()==2) {
              cnt++;
            }
          }
          if (cnt>=4) {
            return true;
          }
          cnt = 0;
        }
        //vertical,cross
        if (fields[i][j]->get()==1) {
          for (size_t h = 1; h <= 4; h++) {
            if (fields[i][j+h]->get()==1) {
              cnt++;
            }
          }
          if (cnt>=4) {
            return true;
          }
          cnt = 0;
        }

        //vertical,circle
        if (fields[i][j]->get()==2) {
          for (size_t h = 1; h <= 4; h++) {
            if (fields[i][j+h]->get()==2) {
              cnt++;
            }
          }
          if (cnt>=4) {
            return true;
          }
          cnt = 0;
        }


      }
    }

    return false;
}
  void draw() {
    gout << move_to(0,0);
    gout << color(255,0,0);
    gout << box(899,899);
    gout << move_to(0,0);
    for (size_t i = 0; i < 15; i++) {
      for (size_t j = 0; j < 15; j++) {
        fields[i][j]->draw();
      }
    }
    gout << refresh;
  }
  GameMaster() {
    gout.open(750,750);
    for (size_t i = 0; i < 15; i++) {
      std::vector<field*> line;
      std::vector<widget*> line2;
      for (size_t j = 0; j < 15; j++) {
        field * f = new field(i*50,j*50,50);
        line.push_back(f);
        line2.push_back(f);
      }
      fields.push_back(line);
      widgets.push_back(line2);
    }
    //predraw everything - is this needed ?
    draw();
  }

  void event_loop() {
    event ev;
    while (gin >> ev) {
      if (ev.type==ev_mouse&&ev.button==btn_left) {
        for (size_t i = 0; i < 15; i++) {
          for (size_t j = 0; j < 15; j++) {
            if (widgets[i][j]->isover(ev.pos_x,ev.pos_y)) {
              if (turn_cross&&fields[i][j]->get()==0) {
                fields[i][j]->draw();
                fields[i][j]->set(1);
                turn_cross=false;
              }
              else {
                if (fields[i][j]->get()==0) {
                  fields[i][j]->draw();
                  fields[i][j]->set(2);
                  turn_cross=true;
                }
              }

            }
          }
        }
      }
      draw();
      if (check4win()) {
        break;
      }
    }
  }

};

int main() {

  GameMaster * gm = new GameMaster();
  gm->event_loop();
  return 0;
}
