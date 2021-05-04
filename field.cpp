#include "graphics.hpp"
#include "field.hpp"
#include "widget.hpp"

using namespace genv;

field::field(int x, int y, int s):widget(x,y,s,s) {
  state_=0;
}

void field::set(int state) {
  //avoiding possible future errors here
  if (state==0||state==1||state==2) {
    state_=state;
  }
}

void field::draw() {
  if (state_==0) {
    gout << move_to(x_,y_);
    gout << move(3,3);
    gout << color(255,255,255);
    gout << box(size_x_,size_y_);
  }

  if (state_==1) {
    gout << move_to(x_,y_);
    gout << move(3,3);
    gout << color(255,255,255);
    gout << box(size_x_,size_y_);
    gout << color(0,0,255);
    gout << move_to(x_+3,y_+size_y_-3);
    gout << line_to(x_+size_x_-3,y_+3);
    gout << move_to(x_+3,y_+3);
    gout << line_to(x_+size_x_-3,y_+size_y_-3);
  }

  if (state_==2) {
    gout << move_to(x_,y_);
    int r = size_x_/2-4;
    int x = x_+size_x_/2+2;
    int y = y_+size_x_/2+2;
    for (int i = x-r; i <= x+r; i++) {
      for (int j = y-r; j <= y+r; j++) {
        if ((i-x)*(i-x)+(j-y)*(j-y)<r*r) {
          gout << move_to(i,j);
            if (abs((i-x)*(i-x)+(j-y)*(j-y)-r*r)<60) {
              gout << color(255,0,0);
            }
            else {
              gout << color(255,255,255);
            }
          }
          gout << dot;
        }
      }
}
}

void field::handle(genv::event ev) {

}
