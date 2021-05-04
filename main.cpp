#include <iostream>
#include <vector>
#include "widget.hpp"
#include "graphics.hpp"
#include "num_select.hpp"
#include "num_set.hpp"
#include "field.hpp"
#include "board.hpp"

using namespace genv;

class GameMaster {
  std::vector<widget*> v;
  std::vector<std::vector<int>> fields;
  //board * b = new board(10,10,5,10);
  field * f = new field(30,30,50);
  field * f2 = new field(60,60,50);
public:
  GameMaster() {
    gout.open(800,800);
    //v.push_back(b);
    v.push_back(f);
    //b->draw();
    f->draw();
    f2->draw();
    gout << refresh;
  }

  void event_loop() {
    event ev;
    while (gin >> ev) {
      if (ev.type==ev_mouse&&ev.button==btn_left) {
        std::cout << ev.pos_x << " " << ev.pos_y << '\n';
      }
      gout << refresh;
    }
  }

};

int main() {

  GameMaster * gm = new GameMaster();
  gm->event_loop();
  return 0;
}
