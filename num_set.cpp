#include "widgets.hpp"
#include "graphics.hpp"
#include "num_set.hpp"
#include <iostream>

using namespace genv;
using namespace std;

num_set::num_set(int x, int y, int s, int num,int min, int max): widget(x,y,s,s),num_(num),min_(min),max_(max)
{
}

std::string num_set::get() {
  return std::to_string(num_);
}
void num_set::draw() {
  //white box
  gout << color(255,255,255);
  gout << move_to(x_,y_);
  gout << box(size_x_,size_y_);
  gout << move_to(x_+(size_x_/5),y_+(size_y_/2));
  gout << color(0,0,0);
  gout << text(to_string(num_));


  //grey boxes
  gout << color(200,200,200);
  gout << move_to(x_+size_x_-10,y_);
  gout << box(10,10);
  gout << move_to(x_+size_x_-10,y_+size_y_-10);
  gout << box(10,10);

  //red arrows
  gout << color(255,0,0);
  gout << move_to(x_+(size_x_-10),y_+(size_y_-10));
  gout << line_to(x_+(size_x_),y_+(size_y_-10));
  gout << line_to(x_+(size_x_-5),y_+(size_y_));
  gout << line_to(x_+(size_x_-10),y_+(size_y_-10));

  gout << move_to(x_+(size_x_-10),y_+10);
  gout << line_to(x_+(size_x_),y_+10);
  gout << line_to(x_+(size_x_-5),y_);
  gout << line_to(x_+(size_x_-10),y_+10);


}


void num_set::handle(event ev)
{
  if (ev.type==ev_mouse&&ev.button==btn_left) {
    if (ev.pos_x>(x_+size_x_-10)&&ev.pos_x<(x_+size_x_)) {
      if (ev.pos_y>(y_+size_y_-10)&&ev.pos_y<(y_+size_y_)) {
        if (num_>min_) {
          num_-=1;
        }
      }
    }
    if (ev.pos_x>(x_+size_x_-10)&&ev.pos_x<(x_+size_x_)) {
      if (ev.pos_y>y_&&ev.pos_y<(10+y_)) {
        if (num_<max_) {
          num_+=1;
        }
      }
    }
  }
  if (ev.type==ev_key&&ev.keycode==key_up) {
    if (num_<max_) {
      num_+=1;
    }
  }
  if (ev.type==ev_key&&ev.keycode==key_down) {
    if (num_>min_) {
      num_-=1;
    }
  }
  if (ev.type==ev_key&&ev.keycode==key_pgup) {
    if (num_+9<max_) {
      num_+=10;
    }
  }
  if (ev.type==ev_key&&ev.keycode==key_pgdn) {
    if (num_-9>min_) {
      num_-=10;
    }
  }
}
