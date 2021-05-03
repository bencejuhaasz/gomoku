#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED
#include "graphics.hpp"
#include <vector>

using namespace std;

class board: public widget {
private:
  int size;
  std::vector<std::vector<int>> * fields;
public:
  void place(int,int);
  void clear;

};

#endif
