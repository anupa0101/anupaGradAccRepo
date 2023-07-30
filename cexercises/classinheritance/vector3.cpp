#include <iostream>
#include <vector>
#include <string>
#include "vector3.h"
using namespace std;  

void vector3::ADD(vector3 v1, vector3 v2) 
{  x = v1.x + v2.x;  y = v1.y + v2.y;  z = v1.z + v2.z; }  
void vector3::SUB(vector3 v1, vector3 v2) 
{  x = v1.x - v2.x;  y = v1.y - v2.y;  z = v1.z - v2.z; }  
//void vector3::PrintVector() {  cout<<x <<"\t" <<y <<"\t" <<z <<endl; }  
void vector3::SetVector(double a, double b, double c) 
{  x = a;  
y = b;  
z = c; } 
vector3::vector3(){
    x=y=z=0;
 }
 vector3::vector3(int a, int b, int c){
    x=a;
    y=b;
    z=c;
 }

  vector3::vector3(const vector3& rhs){// COPY CONSTRUCTOR USE CONST AND &.
    x=rhs.x;
    y=rhs.y;
    z=rhs.z;
  }

   vector3& vector3::operator=(const vector3& rhs){// copy assignment operator
 

   if(this==&rhs){ //checking for self assginment, then do nothing
         return *this;// this is a pointer
      }
   else{ // here can delete previously lhs memory and reallocate lhs memory and get values from rhs
      x=rhs.x;
      y=rhs.y;
      z=rhs.z;
    }
      return *this;// return itself
  }
 vector3::~vector3(){
   //do nothn
 }