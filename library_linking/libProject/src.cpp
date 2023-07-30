#include<iostream>
#include "Dependencies64/GLFW/include/GLFW/glfw3.h" // having the lib files in the folder and using relative path here allows anyone to compile This
int main(){

    int a= glfwInit();
    std::cout<<a+8;

    return 0;
}