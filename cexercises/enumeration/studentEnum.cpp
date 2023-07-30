#include<iostream>
#include<conio.h>
using namespace std;
//way to define a set of symbolic constants that can be used in place of integer values. This 
//can make your code more readable and maintainable, as it allows you to use meaningful names instead of integer values in your code.
//can use like a typename
enum grade{A, B,C};
grade returnColor(int );
int main()
{
    const int n=5;
   
   char names[n][20];
   int marks[n]={0};
   grade corespGrads[n];

   for(int i=0;i<n;i++)
   {
    cin.getline(names[i],20);

   }
     for(int i=0;i<n;i++)
   {
    cin>>marks[i];
   }

    for(int i=0;i<n;i++)
   {
     corespGrads[i]=returnColor(marks[i]);
   }

    for(int i=0;i<n;i++)
   {

    int siz=sizeof(names[i])/sizeof(names[i][0]);
    
    cout<<names[i];
    
    cout<<"          ";
    
     switch(corespGrads[i])
     {
        case A:
             cout<<'A'<<endl;
             break;
        case B:
             cout<<'B'<<endl;
             break;
        default:
             cout<<'C'<<endl;
             break;

     }
   }

    return 0;
}

grade returnColor(int a)
{
    grade gradVal;
    if(a>=75)
    {
        gradVal=A;
    }
    else if(a>=50)
    {
        gradVal=B;
    }
    else {
        gradVal=C;
    }
    return gradVal;
}