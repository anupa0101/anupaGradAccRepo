#include <iostream>
#include <vector>
#include <string>
#include "vector5.h"
using namespace std;  

void vector5::ADD(vector5 v1, vector5 v2) 
{  x = v1.x + v2.x;  y = v1.y + v2.y;  z = v1.z + v2.z; v = v1.v + v2.v;}  
void vector5::SUB(vector5 v1, vector5 v2) 
{  x = v1.x - v2.x;  y = v1.y - v2.y;  z = v1.z - v2.z; v = v1.v- v2.v;}  
void vector5::PrintVector() {  cout<<x <<"\t" <<y <<"\t" <<z <<"\t" <<v <<endl; }  
void vector5::SetVector(double a, double b, double c, double e) 
{  x = a;  
y = b;  
z = c;
v=e; } 
vector5::vector5(){
    x=y=z=v=0;
 }
 vector5::vector5(int a, int b, int c, int d){
    x=a;
    y=b;
    z=c;
    v=d;
 }