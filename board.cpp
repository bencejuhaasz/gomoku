#include "graphics.hpp"
#include "board.hpp"
#include "widget.hpp"
#include <vector>

using namespace genv;


board::board(int x, int y, int n): widget(x,y,n*30,n*30), size_(n) {

}

void board::draw() {
  gout << color(255,255,255);
  for (size_t i = 0; i < size_; i++) {
    for (size_t j = 0; j < size_; j++) {
      gout << move_to(x_+i*30,y_+j*30);
      gout << move(3,3);
      gout << box(27,27);
    }
  }

}
