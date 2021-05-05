#include <iostream>
#include <vector>
#include "widget.hpp"
#include "graphics.hpp"
#include "num_select.hpp"
#include "num_set.hpp"
#include "field.hpp"

using namespace genv;

class GameMaster {
  bool turn_cross = true;
  std::vector<std::vector<field*>> fields;
  std::vector<std::vector<widget*>> widgets;
public:
  bool check4win() {
    int cntvert_x = 0;
    int cnthor_x = 0;
    int cntvert_o = 0;
    int cnthor_o = 0;
    int crossl_o = 0;
    int crossl_x = 0;
    int crossr_o = 0;
    int crossr_x = 0;
    for (size_t i = 1; i < 15; i++) {
      for (size_t j = 1; j < 15; j++) {
        //horizontal
        if (fields[i-1][j]->get()==fields[i][j]->get()) {
          if (fields[i][j]->get()==1) {
            cntvert_x++;
          }
          if (fields[i][j]->get()==2) {
            cntvert_o++;
          }
        }
        //vertical
        if (fields[i][j-1]->get()==fields[i][j]->get()) {
          if (fields[i][j]->get()==1) {
            cnthor_x++;
          }
          if (fields[i][j]->get()==2) {
            cnthor_o++;
          }
        }
        //crossl
        if (fields[i-1][j-1]->get()==fields[i][j]->get()) {
          if (fields[i][j]->get()==1) {
            crossl_x++;
          }
          if (fields[i][j]->get()==2) {
            crossl_o++;
          }
        }
        //crossr
        if (fields[i-1][j]->get()==fields[i][j-1]->get()) {
          if (fields[i][j]->get()==1) {
            crossr_x++;
          }
          if (fields[i][j]->get()==2) {
            crossr_o++;
          }
        }
      }
    }
    if (cntvert_o>=4||cntvert_x>=4||cnthor_o>=4||cnthor_x>=4||crossl_o>=3||crossl_x>3||crossr_o>=5||crossr_x>=5) {
      return true;
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
        std::cout << ev.pos_x << " " << ev.pos_y << '\n';
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
