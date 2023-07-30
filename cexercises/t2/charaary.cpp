#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int main(){
    
    char arry[20];
    cin.getline(arry,20);
    

    int arrayLength =sizeof(arry)/sizeof(arry[0]);//sizeof return the size of a data type in bytes, so divide by size of a single element. 
    //use different method to get size of dynamic arrays
    cout<<arrayLength<<endl;
    for(int i=0;i<arrayLength;i++)
    {
        cout<<arry[i];
    
    }

    getch();
    return 0;
}