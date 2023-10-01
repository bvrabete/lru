cmake_minimum_required(VERSION 3.19)

project(lru)

include_directories(".")

file(GLOB SOURCES "*.cpp")

add_executable(lru ${SOURCES})

set_property(TARGET lru PROPERTY CXX_STANDARD 17)
