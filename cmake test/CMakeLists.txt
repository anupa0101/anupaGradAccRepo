
#cmake is used to generate the makefile and manage the building process. its the industry standard. 
#CMake can generate a native build environment that will compile source code, create libraries, generate wrappers
 #and build executables in arbitrary combinations. 
#Cmake allows to provide cross platform build files that would generate platform specific project/make files for particular compilation/platform.
#A makefile is a text file that contains instructions for how to compile and link (or build) a set of source code files



#>commands- >cmake:quick start - then select library/executable- add the project name- this will create the CMakeLists.txt
#right click and select build this will create the build directory with the exe files and Makefile 

#usually we create an /include directory for the header files. we can keep the source files in he main folder or create a src folder 


#syntax for derefferencing a variable in cmake - ${VARIABLE NAME}

# Almost all CMake files should start with cmake_minimum_required
# You should always specify a range with the newest and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
#cmake_minimum_required(VERSION 3.1...3.25)

cmake_minimum_required(VERSION 3.0.0) #minimum cmake version


# This is your project statement. You should always list languages;
#project(  ModernCMakeExample  VERSION 1.0  LANGUAGES CXX)

project("anupa" VERSION 0.1.0 LANGUAGES CXX) #name of the project followed by keyword VERSION versionNumber followed by LANGUAGES CXX
#this assigns anupa to the PROJECT_NAME variable   ${PROJECT_NAME} is anupa

set(CMAKE_CXX_STANDARD 17)#define the version of minimum c++ rerquired- add this before add_executable
#set(CMAKE_CXX_STANDARD_REQUIRED True) to make the c++ version required

include(CTest)
enable_testing()

add_executable(anupa main.cpp Base.cpp) #(anupa is the target) this will create a anupa.exe file and the source file is main.cpp and Base.cpp file(implementation files). 
#this command requires two arguments. the name of the executable and the source code files required to create the executable
#add_executable(${PROJECT_NAME} main.cpp others.cpp) also is the same
#anupa.exe will be created in the build directory. have the src files seperately and build file in seperate folder

target_include_directories(anupa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include) #this is so that the header files are found in the include folder


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)





###############################another way-creating libraries and linking them
#here lets create a BaseLib.a libarary from Base.cpp and then link the libarary- WORKS


#cmake_minimum_required(VERSION 3.0.0) #minimum cmake version

#project("anupa" VERSION 0.1.0 LANGUAGES CXX) #name of the project followed by keyword VERSION versionNumber followed by LANGUAGES CXX
#this assigns anupa to the PROJECT_NAME variable   ${PROJECT_NAME} is anupa

#set(CMAKE_CXX_STANDARD 17)#define the version of minimum c++ rerquired- add this before add_executable
#set(CMAKE_CXX_STANDARD_REQUIRED True)# to make the c++ version required

#include(CTest)
#enable_testing()

#A static library (or archive) contains code that is linked to users’ programs at compile time. The executable file generated keeps its own copy of the library code.

#A dynamic library (or shared library) contains code designed to be shared by multiple programs. The content in the library is loaded to memory at runtime. 

#IF LIBRARY IS NOT BUILT USE THIS 
#add_library(BaseLib STATIC Base.cpp )# CREATES A static type library called Baselib.a
#target_include_directories(BaseLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)# THIS IS TO FIND THE HEADER FILE OF THE LIBRARY-to find the header file for base.h


#add_executable(anupa main.cpp) #(anupa is the target) this will create a anupa.exe file and the source file is main.cpp 

#AFTER ADDING EXECUTABLE YOU ADD THE LINK LIBRARIES

#target_include_directories(anupa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include) #this is so that the header files are found in the include folder
#target_link_libraries(anupa PUBLIC BaseLib) #after creating the .a or .lib file, it is linked 

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)


################LINKING EXTERNAL LIBRARIES- THIS WORKED BUT THERE MUST BE A BETTER WAY#############

#cmake_minimum_required(VERSION 3.0.0)
#project(libproject VERSION 0.1.0)

#include(CTest)
#enable_testing()



#include_directories(${CMAKE_SOURCE_DIR}/Dependencies64/GLFW/include/GLFW)#where the library.a or .lib files are present
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies64/GLFW/lib-mingw-w64)#where the header files are present

#add_executable(libproject src.cpp)
#target_link_libraries(libproject PRIVATE glfw3)# actual name is libglfw3.a but we need to enter without the prefix lib and suffix .a
#to link the dynamic library link to the libraryNamedll.a file BUT MAKE SURE TO INCLUDE TH .DLL FOLDER IN THE BUILD FILES or else wont work



#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
