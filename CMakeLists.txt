cmake_minimum_required(VERSION 3.19)

project(lru LANGUAGES CXX)

# require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(".")

file(GLOB SOURCES "*.cpp")

add_executable(lru ${SOURCES})

# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME skip_list_test
  COMMAND $<TARGET_FILE:lru>
  )
