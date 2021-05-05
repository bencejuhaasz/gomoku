#include <iostream>
#include <vector>
#include "widget.hpp"
#include "graphics.hpp"
#include "num_select.hpp"
#include "num_set.hpp"
#include "field.hpp"

using namespace genv;

class GameMaster {
  bool turn_cross = true;
  std::vector<std::vector<field*>> fields;
  std::vector<std::vector<widget*>> widgets;
public:
  bool check4win() {
    int o_horizontal = 0;
    int x_horizontal = 0;
    int o_vertical = 0;
    int x_vertical = 0;
    int o_crossl = 0;
    int x_crossl = 0;
    int o_crossr = 0;
    int x_crossr = 0;
    for (size_t i = 1; i < fields.size(); i++) {
      for (size_t j = 1; j < fields.size(); j++) {
        if (fields[i-1][j]->get()==fields[i][j]->get()) {
          if (fields[i][j]->get()==1) {
            x_horizontal++;
          }
          if (fields[i][j]->get()==2) {
            o_horizontal++;
          }
        }
      }
    }
    for (size_t i = 1; i < fields.size(); i++) {
      for (size_t j = 1; j < fields.size(); j++) {
        if (fields[i][j-1]->get()==fields[i][j]->get()) {
          if (fields[i][j]->get()==1) {
            x_vertical++;
          }
          if (fields[i][j]->get()==2) {
            o_vertical++;
          }
        }
      }
    }
    for (size_t i = 1; i < fields.size(); i++) {
      for (size_t j = 1; j < fields.size(); j++) {
        if (fields[i][j-1]->get()==fields[i][j]->get()) {
          if (fields[i][j]->get()==1) {
            x_vertical++;
          }
          if (fields[i][j]->get()==2) {
            o_vertical++;
          }
        }
      }
    }
    for (size_t i = 1; i < fields.size(); i++) {
      for (size_t j = 1; j < fields.size(); j++) {
        if (fields[i-1][j-1]->get()==fields[i][j]->get()) {
          if (fields[i][j]->get()==1) {
            x_crossl++;
          }
          if (fields[i][j]->get()==2) {
            o_crossl++;
          }
        }
      }
    }
    for (size_t i = 1; i < fields.size(); i++) {
      for (size_t j = 1; j < fields.size(); j++) {
        if (fields[i-1][j]->get()==fields[i][j-1]->get()&&(fields[i][j]->get()==1||fields[i][j]->get()==2)) {
          if (fields[i][j]->get()==1) {
            x_crossr++;
          }
          if (fields[i][j]->get()==2) {
            o_crossr++;
          }
        }
      }
    }
    if (o_horizontal>3||x_horizontal>3||o_vertical>3||x_vertical>3||o_crossl>3||x_crossl>3||o_crossr>4||x_crossr>4) {
      return true;
    }
    return false;
  }
  void draw() {
    gout << move_to(0,0);
    gout << color(255,0,0);
    gout << box(899,899);
    gout << move_to(0,0);
    for (size_t i = 0; i < 15; i++) {
      for (size_t j = 0; j < 15; j++) {
        fields[i][j]->draw();
      }
    }
    gout << refresh;
  }
  GameMaster() {
    gout.open(750,750);
    for (size_t i = 0; i < 15; i++) {
      std::vector<field*> line;
      std::vector<widget*> line2;
      for (size_t j = 0; j < 15; j++) {
        field * f = new field(i*50,j*50,50);
        line.push_back(f);
        line2.push_back(f);
      }
      fields.push_back(line);
      widgets.push_back(line2);
    }
    //predraw everything - is this needed ?
    draw();
  }

  void event_loop() {
    event ev;
    while (gin >> ev) {
      if (ev.type==ev_mouse&&ev.button==btn_left) {
        std::cout << ev.pos_x << " " << ev.pos_y << '\n';
        for (size_t i = 0; i < 15; i++) {
          for (size_t j = 0; j < 15; j++) {
            if (widgets[i][j]->isover(ev.pos_x,ev.pos_y)) {
              if (turn_cross&&fields[i][j]->get()==0) {
                fields[i][j]->draw();
                fields[i][j]->set(1);
                turn_cross=false;
              }
              else {
                if (fields[i][j]->get()==0) {
                  fields[i][j]->draw();
                  fields[i][j]->set(2);
                  turn_cross=true;
                }
              }

            }
          }
        }
      }
      draw();
      if (check4win()) {
        std::cout << "error" << '\n';
      }
    }
  }

};

int main() {

  GameMaster * gm = new GameMaster();
  gm->event_loop();
  return 0;
}
