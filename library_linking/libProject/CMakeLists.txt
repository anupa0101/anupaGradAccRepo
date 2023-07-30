cmake_minimum_required(VERSION 3.0.0)
project(libproject VERSION 0.1.0)

include(CTest)
enable_testing()



include_directories(${CMAKE_SOURCE_DIR}/Dependencies64/GLFW/include/GLFW)#where the library.a or .lib files are present
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies64/GLFW/lib-mingw-w64)#where the header files are present

add_executable(libproject src.cpp)
target_link_libraries(libproject PRIVATE glfw3)# actual name is libglfw3.a but we need to enter without the prefix lib and suffix .a
#to link the dynamic library link to the libraryNamedll.a file BUT MAKE SURE TO INCLUDE TH .DLL FOLDER IN THE BUILD FILES or else wont work

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
