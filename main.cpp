#include <iostream>
#include <vector>
#include "widget.hpp"
#include "graphics.hpp"
#include "num_select.hpp"
#include "num_set.hpp"
#include "board.hpp"
#include "circle.hpp"

using namespace genv;

class GameMaster {
  std::vector<widget*> v;
  std::vector<std::vector<int>> fields;
public:
  GameMaster() {
    gout.open(800,800);
    v.push_back(game_board);
    v.push_back(c1);
    game_board->draw();
    c1->draw();
    gout << refresh;
  }

  void event_loop() {
    event ev;
    while (gin >> ev) {
      if (ev.type==ev_mouse&&ev.button==btn_left) {
        std::cout << ev.pos_x << " " << ev.pos_y << '\n';
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
