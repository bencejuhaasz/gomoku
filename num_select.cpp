#include "widgets.hpp"
#include "graphics.hpp"
#include "num_select.hpp"
#include <iostream>
#include <vector>

using namespace genv;
using namespace std;

num_select::num_select(int x, int y, int sx, int sy,int menu_size,std::vector<string> content): widget(x,y,sx,sy),menu_size_(menu_size),content_(content)
{
  num_=content_[0];
  content_.push_back("");
}

string num_select::get() {
  return num_;
}

void num_select::draw() {
  //white box
  gout << color(255,255,255);
  gout << move_to(x_,y_);
  gout << box(size_x_,size_y_);
  gout << move_to(x_+(size_x_/5),y_+(size_y_/2));
  gout << color(0,0,0);
  gout << text(num_);
  //red arrow
  gout << color(255,0,0);
  gout << move_to(x_+(size_x_-10),y_+(size_y_-10));
  gout << line_to(x_+(size_x_),y_+(size_y_-10));
  gout << line_to(x_+(size_x_-5),y_+(size_y_));
  gout << line_to(x_+(size_x_-10),y_+(size_y_-10));
  //drop-down menu
  if (menu_) {
    gout << move_to(x_,y_+size_y_);
    gout << color(200,200,200);
    gout << box(size_x_,menu_size_);
  }
  else {
    gout << move_to(x_,y_+size_y_);
    gout << color(0,0,0);
    gout << box(size_x_,menu_size_);
  }
  int cnt = menu_size_ / 20;
  gout << color(0,0,0);
  int a = menu_begin_;
  for (size_t i = (y_+size_y_); i <= (menu_size_+y_+size_y_); i+=20) {
    gout << move_to(x_,i+10);
    gout << text(content_[a]);
    a++;
  }
}

void num_select::handle(genv::event ev)
{
  if (ev.type==ev_mouse&&ev.button==btn_left&&isover(ev.pos_x,ev.pos_y)) {
    if (!menu_) {
      menu_=true;
    }
  }
  if (ev.type==ev_mouse&&ev.button==btn_wheelup) {
    if (menu_begin_+1<(content_.size()-(menu_size_/ 20))) {
      menu_begin_++;
    }
  }
  if (ev.type==ev_mouse&&ev.button==btn_wheeldown) {
    if (menu_begin_-1>=0) {
      menu_begin_--;
    }
  }
  if (ev.type==ev_mouse&&ev.button==btn_left) {
    if (ev.pos_x>x_&&ev.pos_y>(y_+size_y_)&&ev.pos_y<(y_+size_y_+menu_size_)) {
      int cnt = (ev.pos_y-(y_+size_y_))/20+menu_begin_;

      num_=content_[cnt];
      menu_=false;

    }
  }
}
