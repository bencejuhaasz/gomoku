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

  GameMaster() {
    gout.open(600,600);
    game_board.draw();
  }

};

int main() {
  board gb = new board(50,50,15);
  gout.open(600,600);
  game_board.draw();
  gout << refresh;
  event ev;
  while (gin >> ev) {
    /* code */
  }
  return 0;
}
