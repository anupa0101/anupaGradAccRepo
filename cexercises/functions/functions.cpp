#include<iostream>
#include<conio.h>

using namespace std;

void passbyref(int &, int &);
float area(int ); //circle - function overloading
float area(int ,int);//rectangle- function overloading
float area(int ,int , int); //trapezium- function overloading
void arrymodify(int [], int);
void arryNOmodify(const int [], int); //prevents Array change


//Templates
template<typename t1,typename t2, typename t3>
t1 templateFun( t2, t3);



int main()
{

    int a,b;
    passbyref(a,b);
    cout<<a<<b<<endl;

    cout<<area(1)<<endl;
    cout<<area(1,2)<<endl;
    cout<<area(1,3,4)<<endl;
    

    int ary[3];
    arrymodify( ary, 3);
    for(int i=0;i<3;i++)
    {
        cout<<ary[i]<<" ";
    }
     cout<<endl;
     arryNOmodify( ary, 3);

    //template
    cout<<templateFun<bool,int,float>( 2, 3.5);

    getch();
    return 0;
}


void passbyref(int &a, int &b){
    a=3;
    b=4;
}


float area(int r)//circle
{
    return r*r*3.14; 
}
float area(int r,int q)//rectangle
{
    return (r*q); 
}
float area(int r,int q, int z) //trapezium
{
    return (r*q*z); 
}

void arrymodify(int ary[], int siz)//arry passsed by refference 
{
    for(int i=0;i<siz;i++)
    {
        ary[i]=i;
    }
}
void arryNOmodify(const int ary[], int siz) //cant modify arry will give error
{
   for(int i=0;i<3;i++)
    {
        cout<<ary[i]<<" ";
    }
     cout<<endl;

}


//template 
template<typename t1,typename t2, typename t3>
t1 templateFun( t2 a, t3 b){
    return (a>b)?true:false;

}
