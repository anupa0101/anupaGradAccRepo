#include<iostream>
#include<conio.h>
#include"vectx.h"

using namespace std;

vectx::vectx(): x(0),y(0){ // use member initilalizer list instead of assignment, itsm more efficient.  especially for large objects

}
vectx::vectx(float a,float b):x(a),y(b){// use member initilalizer list instead of assignment, itsm more efficient

}
void vectx::show(){
    cout<<x<<"\t"<<y<<endl;
};
vectx vectx::operator+(const vectx& va) const{ // const outside the paremter is to make sure the calling obeject is not changed
    vectx v;
    v.x=x+va.x;
    v.y=y+va.y;
    return v;
}
void vectx::operator+=(const vectx& va) {
    
    
    x=x+va.x;
    y=y+va.y;
    
}
vectx operator-(const vectx& va,const vectx& vb){
    vectx v;
    v.x=va.x-vb.x;
    v.y=va.y-vb.y;
    return v;
    
}
vectx operator*(float m,const vectx& va){
    
    vectx v;
    v.x=m*va.x;
    v.y=m*va.y;
    return v;
}
vectx operator*(const vectx& va ,float m){
     vectx v;
    v.x=m*va.x;
    v.y=m*va.y;
    return v;
}
std::ostream& operator<<(std::ostream& os, const vectx& obj)// need to make it a friend fucntion to access the private vairables
 {
    os<<obj.x<<'t'<<obj.y;
    return os;
 }
 std::istream& operator>>(std::istream& is,  vectx& obj){
    is>>obj.x;
    is>>obj.y;
    return is;
 }