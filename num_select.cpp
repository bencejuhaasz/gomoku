#ifndef NUM_SELECT_INCLUDED
#define NUM_SELECT_INCLUDED
#include <vector>
class num_select: public widget {
private:
  std::string num_;
  bool menu_=false;
  int menu_size_;
  int menu_begin_=0;
  std::vector<std::string> content_;
public:
  num_select(int,int,int,int,int,std::vector<std::string>);
  virtual void draw();
  virtual void handle(genv::event ev);
  virtual std::string get();
};

#endif
