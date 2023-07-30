#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int main(){
    
    int arry[10];
    for(int i=0; i<10;i++)
    {
        
        {
            cin>>arry[i];
            cout<<endl;
        }
    }

   int arrayLengthi =sizeof(arry)/sizeof(arry[0]);//sizeof return the size of a data type in bytes, so divide by size of a single element. 
    //use different method to get size of dynamic arrays
   


    for(int i=0; i<arrayLengthi;i++)
    {
            
        {
            cout<<arry[i]<<" ";
        
            
        }
        
    }
    cout<<endl;
    for(int i=0; i<arrayLengthi;i++){ //ascending order

        int k=i;
        while((k>0)&&(arry[k-1]>arry[k])){
            int t=arry[k-1];
            arry[k-1]=arry[k];
            arry[k]=t;
            k-=1;

        }
    }
     for(int i=0; i<arrayLengthi;i++)
    {
            
        {
            cout<<arry[i]<<" ";
        
            
        }
        
    }

      cout<<endl;
    for(int i=0; i<arrayLengthi;i++){ //ascending order

        int k=i;
        while((k>0)&&(arry[k-1]<arry[k])){
            int t=arry[k-1];
            arry[k-1]=arry[k];
            arry[k]=t;
            k-=1;

        }
    }
     for(int i=0; i<arrayLengthi;i++)
    {
            
        {
            cout<<arry[i]<<" ";
        
            
        }
        
    }


    getch();
    return 0;
}