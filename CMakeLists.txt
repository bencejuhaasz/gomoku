cmake_minimum_required( VERSION 2.6 )

project( gomoku )

find_package( SDL2 REQUIRED )


link_libraries (
  SDL2
  SDL2_ttf
)

add_library( graphics graphics.cpp )
add_library(widget widget.cpp)
add_library(field field.cpp)
add_executable( test_graphics main.cpp )



target_link_libraries( test_graphics graphics field widget)
