cmake_minimum_required(VERSION 3.19)

project(interview)

include_directories(".")

file(GLOB SOURCES "*.cpp")

add_executable(interview ${SOURCES})

set_property(TARGET interview PROPERTY CXX_STANDARD 17)
