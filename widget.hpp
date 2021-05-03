#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"

class widget {
protected:
    int x_, y_, size_x_, size_y_;
public:
    widget(int x, int y, int sx, int sy);
    virtual bool isover(int mx, int my);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual std::string get() = 0;
};
#endif // WIDGETS_HPP_INCLUDED
