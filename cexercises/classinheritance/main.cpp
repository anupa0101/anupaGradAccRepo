#include <iostream>
#include <vector>
#include <conio.h>
#include"vector2.h"
#include"vector3.h"
//#include"vector4.h"
//#include"vector5.h"
// HOW TO COMPILE
// g++ -c main.cpp vector2.cpp vector3.cpp     This will create object files .o type files for each
//g++ main.o vector2.o vector3.o -o prog       This will create a singe executable file called prog.exe


using namespace std;  

int main(){

    vector2 v2_1(1,1), v2_2(1,1), add2,sub2;
    vector3 v3_1(1,1,1), v3_2(1,1,1),add3,sub3;

    v2_1.PrintVector();
    v3_1.PrintVector();
    v3_1.vector2::PrintVector(); //Callling a base class method using derived class object using scope resolution
    add2.ADD(v2_1,v2_2);
    add2.PrintVector();
    sub2.SUB(v2_1,v2_2);
    sub2.PrintVector();

    add3.ADD(v3_1,v3_2);
    add3.PrintVector();
    sub3.SUB(v3_1,v3_2);
    sub3.PrintVector();
    vector3 v5;
    v5.PrintVector();










    return 0;
}
