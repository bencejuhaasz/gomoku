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
    int prev = 0;
    int cnt = 0;
    for (int i = 0; i < fields.size()-1; i++) {
      for (size_t j = 0; j < fields.size(); j++) {
        while (fields[i+1][j]->get()==fields[i][j]->get()) {
          /* code */
        }
      }
    }
    if (cnt==5) {
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
