cmake_minimum_required( VERSION 3.0 )
project( TP5_OPENGL )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra" )
set( CMAKE_BUILD_TYPE Debug )

include_directories("/usr/include/GL")

add_executable( tp5_opengl.out src/main.c
  src/graphique.c
  src/touches.c)
target_link_libraries( tp5_opengl.out -lglut -lGLU -lGL -lm )
