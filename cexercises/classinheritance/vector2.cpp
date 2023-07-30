#include <iostream>
#include <vector>
#include <string>
#include "vector2.h"
using namespace std;  

void vector2::ADD(vector2 v1, vector2 v2) 
{  x = v1.x + v2.x;  y = v1.y + v2.y;  }  
void vector2::SUB(vector2 v1, vector2 v2) 
{  x = v1.x - v2.x;  y = v1.y - v2.y;   } 

void vector2::PrintVector() {  cout<<x <<"\t" <<y<<endl; }  
void vector2::SetVector(double a, double b) 
{  x = a;  
y = b;  
 } 
vector2::vector2(){
    x=y=0;
 }
 vector2::vector2(int a, int b) {
    x=a;
    y=b;
 }
  vector2::vector2(const vector2& rhs){// COPY CONSTRUCTOR USE CONST AND &.
    x=rhs.x;
    y=rhs.y;
  }

  vector2& vector2::operator=(const vector2& rhs){// copy assignment operator
      if(this==&rhs){ //checking for self assginment, then do nothing
         return *this;// this is a pointer
      }
      else{
       x=rhs.x;
       y=rhs.y;
      }
      return *this;// return itself
  }

   vector2::vector2( vector2&& source ){ //NO CONST HERE. move constructors are used to transfer ownership. steal the resources. the initial objject wont point to the same resource anymore , the ownershhip is transferred.
//double ampersand && rvlaue refference
      
    x=source.x;// assign the vlaues from source to the object
    y=source.y;
//THEN ASSIGN EMPTY,0, NULL OR NULLPTR TO the values of the source. ownership of source is taken away by assigning null.

   }  

vector2& vector2::operator=(vector2&& source)// move assignment operator
     // same as move assignment operator but check if assigneedd to itslf and return the *this
     {

      if(this==&source)// if its moved to isself
      {
         return *this;
      }
      else{
          x=source.x;// assign the vlaues from source to the object
          y=source.y;
//THEN ASSIGN EMPTY,0, NULL OR NULLPTR TO the values of the source. ownership of source is taken away by assigning null.
         return *this;
      }
     }
  vector2::~vector2(){
   //do nothing
 }