#ifndef NUM_SET_INCLUDED
#define NUM_SET_INCLUDED
#include "graphics.hpp"

class num_set: public widget {
private:
  int num_;
  int min_;
  int max_;
public:
  num_set(int,int,int,int,int,int);
  virtual void draw();
  virtual void handle(genv::event ev);
  void inc();
  void dec();
  virtual std::string get();
};

#endif
