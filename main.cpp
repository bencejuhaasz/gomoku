#include <iostream>
#include <vector>
#include "widget.hpp"
#include "graphics.hpp"
#include "num_select.hpp"
#include "num_set.hpp"
#include "board.hpp"

using namespace genv;

class GameMaster {
  std::vector<std::vector<int>> fields;
  board * game_board = new board(50,50,15);
  int step = false;
public:
  GameMaster() {
    gout.open(600,600);
    game_board->draw();
    gout << refresh;
  }

  void event_loop() {
    event ev;
    while (gin >> ev) {
      /* code */
    }
  }

};

int main() {

  GameMaster * gm = new GameMaster();
  gm->event_loop();
  return 0;
}
