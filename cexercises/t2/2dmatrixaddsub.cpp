#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int main(){
    
    int arry1[2][3];
    for(int i=0; i<2;i++)
    {
            for(int j=0; j<3;j++)
        {
            cin>>arry1[i][j];
            cout<<endl;
        }
    }

   int arrayLengthi =sizeof(arry1)/sizeof(arry1[0]);//sizeof return the size of a data type in bytes, so divide by size of a single element. 
    //use different method to get size of dynamic arrays
   int arrayLengthj =sizeof(arry1[0])/sizeof(arry1[0][0]);//sizeof return the size of a data type in bytes, so divide by size of a single element. 
    //use different method to get size of dynamic arrays


    

    int arry2[2][3];
    for(int i=0; i<2;i++)
    {
            for(int j=0; j<3;j++)
        {
            cin>>arry2[i][j];
            cout<<endl;
        }
    }


    for(int i=0; i<arrayLengthi;i++)
    {
            for(int j=0; j<arrayLengthj;j++)
        {
            cout<<arry1[i][j]<<" ";
        
            
        }
        cout<<endl;
    }
    cout<<endl;


    for(int i=0; i<arrayLengthi;i++)
    {
            for(int j=0; j<arrayLengthj;j++)
        {
            cout<<arry2[i][j]<<" ";
        
            
        }
        cout<<endl;
    }
    cout<<endl;
    int arrys[2][3];
    int arrya[2][3];
    for(int i=0; i<arrayLengthi;i++)
    {
            for(int j=0; j<arrayLengthj;j++)
        {
            arrya[i][j]=arry1[i][j]+arry2[i][j];
            arrys[i][j]=arry1[i][j]-arry2[i][j];
        
            
        }
        cout<<endl;
    }
    cout<<endl;

     for(int i=0; i<arrayLengthi;i++)
    {
            for(int j=0; j<arrayLengthj;j++)
        {
            cout<<arrys[i][j]<<" ";
        
            
        }
        cout<<endl;
    }
    cout<<endl;
     for(int i=0; i<arrayLengthi;i++)
    {
            for(int j=0; j<arrayLengthj;j++)
        {
            cout<<arrya[i][j]<<" ";
        
            
        }
        cout<<endl;
    }
    cout<<endl;


    getch();
    return 0;
}