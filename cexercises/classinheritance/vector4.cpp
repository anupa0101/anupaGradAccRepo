#include <iostream>
#include <vector>
#include <string>
#include "vector4.h"
using namespace std;  

void vector4::ADD(vector4 v1, vector4 v2) 
{  x = v1.x + v2.x;  y = v1.y + v2.y;  z = v1.z + v2.z; v = v1.v + v2.v;}  
void vector4::SUB(vector4 v1, vector4 v2) 
{  x = v1.x - v2.x;  y = v1.y - v2.y;  z = v1.z - v2.z; v = v1.v- v2.v;}  
void vector4::PrintVector() {  cout<<x <<"\t" <<y <<"\t" <<z <<"\t" <<v <<endl; }  
void vector4::SetVector(double a, double b, double c, double e) 
{  x = a;  
y = b;  
z = c;
v=e; } 
vector4::vector4(){
    x=y=z=v=0;
 }
 vector4::vector4(int a, int b, int c, int d){
    x=a;
    y=b;
    z=c;
    v=d;
 }