#include "vector.h"
#include<iostream>
#include<conio.h>


using namespace std;

vector3d::vector3d()
{
    x=y=z=0;
}
vector3d::vector3d(int a,int b,int c)
{
    x=a;
    y=b;
    z=c;
}

void vector3d::printVector(){
    cout<<x<<","<<y<<","<<z<<endl;
}



void vector3d::setVect(int a,int b,int c)
{
    x=a;
    y=b;
    z=c;
}

vector3d vector3d::addV( vector3d a,vector3d b){ //need to be assigned to a vector3d object
    
 vector3d r;
 r.x=a.x+b.x;
 r.y=a.y+b.y;
 r.z=a.z+b.z;
 return r;

}
void vector3d::subV(vector3d a,vector3d b){
    
    x=a.x-b.x;
    y=a.y-b.y;
    z=a.z-b.z;
       

}