cmake_minimum_required( VERSION 2.6 )

project( gomoku )

find_package( SDL2 REQUIRED )


link_libraries (
  SDL2
  SDL2_ttf
)

add_library( graphics graphics.cpp )
add_library(widget widget.cpp)
add_library(num_set num_set.cpp)
add_library(num_select num_select.cpp)
add_library(board board.cpp)
add_executable( test_graphics main.cpp )



target_link_libraries( test_graphics graphics num_set num_select board widget)
