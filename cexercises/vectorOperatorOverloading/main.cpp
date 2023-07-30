#include<iostream>
#include<conio.h>
#include "vectx.h"

using namespace std;

int main()
{
    vectx v1(1,1), v2(1,1),add,sub,mult,mulx;
     
     add=v1+v2;
     sub=v1-v2;
     sub+=add;
     mult=v1*2;
     mulx=2*v1;

     add.show();
     sub.show();
     mult.show();
     mulx.show();


    getch();
    return 0;
}