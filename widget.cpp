#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;

widget::widget(int x,int y, int sx, int sy) : x_(x), y_(y), size_x_(sx), size_y_(sy)
{
}

bool widget::isover(int mx,int my)
{
  if ( (mx>x_&&mx<x_+size_x_)&&(my>y_&&my<y_+size_y_)) {
    return true;
  }
  else
  {
    return false;
  }
}
