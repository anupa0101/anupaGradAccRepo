#include<iostream>
#include<conio.h>

using namespace std;


int main()
{

   int **ptr,row,col;
    cout<<"enter row: ";
    cin>>row;
    cout<<"enter col: ";
    cin>>col;
    ptr=new int*[row];
    for(int i=0;i<row;i++){
        ptr[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        cout<<" enter "<<i<< "col "<< j<< "value :";
       cin>>ptr[i][j];
    }
    }
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        
        cout<<ptr[i][j];
    }
    }  
     for(int i=0;i<row;i++){
        delete []ptr[i];
    }  
   delete []ptr;
   ptr=nullptr;



    _getch;
    return 0;
}

