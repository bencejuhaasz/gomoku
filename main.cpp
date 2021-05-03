#include <iostream>
#include <vector>
#include "widget.hpp"
#include "graphics.hpp"
#include "num_select.hpp"
#include "num_set.hpp"
#include "board.hpp"

using namespace std;
using namespace genv;

class GameMaster {
  std::vector<std::vector<int>> fields;
  board GameBoard = new board(50,50,15);

  GameMaster() {
    gout.open(600,600);
    GameBoard.draw();
  }

};

int main() {
  GameMaster gomoku = new GameMaster();
  return 0;
}
