#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED
#include "graphics.hpp"
#include "widget.hpp"

using namespace genv;

class field: public widget {
private:
  int state_=0; //0 means empty, 1 is cross, 2 is circle
public:
  field(int,int,int);
  void draw();
  void set(int);
  int get();
  void handle(genv::event);

};

#endif
