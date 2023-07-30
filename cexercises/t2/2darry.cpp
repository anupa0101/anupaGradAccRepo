#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int main(){
    
    int arry[3][2];
    for(int i=0; i<3;i++)
    {
            for(int j=0; j<2;j++)
        {
            cin>>arry[i][j];
            cout<<endl;
        }
    }

   int arrayLengthi =sizeof(arry)/sizeof(arry[0]);//sizeof return the size of a data type in bytes, so divide by size of a single element. 
    //use different method to get size of dynamic arrays
   int arrayLengthj =sizeof(arry[0])/sizeof(arry[0][0]);//sizeof return the size of a data type in bytes, so divide by size of a single element. 
    //use different method to get size of dynamic arrays


    for(int i=0; i<arrayLengthi;i++)
    {
            for(int j=0; j<arrayLengthj;j++)
        {
            cout<<arry[i][j]<<" ";
        
            
        }
        cout<<endl;
    }


    getch();
    return 0;
}