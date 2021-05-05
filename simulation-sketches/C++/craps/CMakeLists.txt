cmake_minimum_required(VERSION 3.17)

project(craps)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)

add_compile_options("$<$<CONFIG:RELEASE>:-Ofast>")

add_executable(
  craps
  main.cpp
  Craps.cpp
  Craps.h
  )
