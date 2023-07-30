#include<iostream>
#include<conio.h>

using namespace std;


int main()
{

   int *ptr;
   ptr= new int;
   *ptr=40;
   cout<<*ptr<<endl;
   delete ptr;
   ptr= nullptr;


    _getch;
    return 0;
}

