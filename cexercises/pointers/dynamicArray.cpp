#include<iostream>
#include<conio.h>

using namespace std;


int main()
{

   int *ptr,size;
   cout<<"enter size: ";
   cin>>size;
   ptr=new int[size];
   for(int i=0;i<size;i++){
    cin>>ptr[i]; //also same as *(ptr+i)
   }
   for(int i=0;i<size;i++){
    cout<<ptr[i]; //also same as *(ptr+i)
   }
   delete []ptr;
   ptr=NULL;



    _getch;
    return 0;
}

