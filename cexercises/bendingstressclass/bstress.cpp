#include<iostream>
#include<conio.h>
#include<cmath>
#include "bstress.h"

using namespace std;


void bstress::Intertia(double b, double h)
{
    I=b*pow(h,3)/12;
} 
bstress::bstress(){
    E=200;
    y= M= b=h= I=0;
} 
bool bstress::CheckDimension(double y, double b, double h)
{
    if((y<0)||(b<0)||(h<0)){
        return false;
    }
    else{
        return true;
    }
}   
void bstress::SetVal(double q, double w, double r, double t, double u)
{
    E=q;
    y=w;
    M=r;
    h=t;
    b=u;
    Intertia(b, h);
} 
double bstress::GetStress()
{
    return  M*y / I; 
}
double bstress::GetRadius(){
    return  I*E/M;
    
}

