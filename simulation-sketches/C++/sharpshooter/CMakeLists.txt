cmake_minimum_required(VERSION 3.17)

project(sharpshooter)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 14)

add_compile_options("$<$<CONFIG:RELEASE>:-Ofast>")

add_executable(
  sharpshooter
  main.cpp
  )
