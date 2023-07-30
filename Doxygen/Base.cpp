#include<iostream>
#include "Base.h"

int Base::get() const{
            return x;
        }

void Base::set(const int& x=0,const int& y=0, const int& z=0){
            this->x=x;
            this->y=y;
            this->z=z;
}