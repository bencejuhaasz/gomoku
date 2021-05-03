#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED
#include "graphics.hpp"
#include "widget.hpp"
#include <vector>

using namespace genv;

class board: public widget {
private:
  int size_;
  std::vector<std::vector<int>> * fields;
public:
  void place(int,int);
  void clear;
  void draw();

};

#endif
