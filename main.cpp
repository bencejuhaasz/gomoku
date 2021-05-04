#include <iostream>
#include <vector>
#include "widget.hpp"
#include "graphics.hpp"
#include "num_select.hpp"
#include "num_set.hpp"
#include "field.hpp"

using namespace genv;

class GameMaster {
  std::vector<widget*> v;
  std::vector<std::vector<int>> fields;
  field * f = new field(100,100,50);
public:
  GameMaster() {
    gout.open(800,800);
    v.push_back(f);
    f->draw();
    gout << refresh;
  }

  void event_loop() {
    event ev;
    while (gin >> ev) {
      if (ev.type==ev_mouse&&ev.button==btn_left) {
        std::cout << ev.pos_x << " " << ev.pos_y << '\n';
      }
      if (ev.type==ev_mouse&&ev.button==btn_right) {
        f->set(2);
      }
      if (ev.type==ev_mouse&&ev.button==btn_middle) {
        f->set(0);
      }
      for (size_t i = 0; i < v.size(); i++) {
        v[i]->draw();
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
