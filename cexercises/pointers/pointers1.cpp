#include<iostream>
#include<conio.h>

using namespace std;

int *retarr();
int main()
{
   int a;
   int *ptr;
   ptr=&a;
   *ptr=40;
   cout<<a<<*ptr<<endl;
   int *ptrr;
   ptrr=retarr();
   for(int i=0;i<5;i++){
        cout<<*(ptrr+i)<<endl;
   }

    _getch;
    return 0;
}

int *retarr(){

    static int arr[5];
    for(int i=0;i<5;i++){
        arr[i]=i+1;
    }
    return arr; //its scoped? isnt that dangling?????
}