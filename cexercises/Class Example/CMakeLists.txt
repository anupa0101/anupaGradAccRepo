cmake_minimum_required(VERSION 3.0.0)
project(class_example VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(class_example main.cpp Base.cpp Derived.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
