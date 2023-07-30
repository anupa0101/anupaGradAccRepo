#include<iostream>
#include "Base.h"
#include"Derived.h"

Derived::Derived():Base(){/// calls the base class cosntructor AUTOMATICALL BUT CAN BE EXPLICIT
      
            z=0;
            char* s= new char[5];
            std::cout<<" Derived Constructor callled\n";
        }

Derived::Derived(int z):Base(0,0){ //IMPORTANT genrelly call the base(), but here specified
//THIS ESPECIALLY BECOMES AN ISSSUE WHEN THERES NO DEFAULT CONSTRUCTOR. ONLY OVERLOADED IN BOTH, dont know which to call
            this->z=z;
            std::cout<<"Derived Overloaded constructor callled\n";
        }
Derived::Derived(int x, int y, int z):Derived(){// calls the derived constrcutor
            this->z=z;
            this->x=x;
            this->y=y;

            std::cout<<"Derived Overloaded constructor callled\n";
        }

void Derived::set(const int& x,const int& y){

            this->x=x;
            this->y=y;
            this->z=z;

        }

void Derived::print() const{// cant change the member variables inside unnless defined as mutable

            std::cout<<x<<'\t'<<y<<'\t'<<z<<std::endl;

        }
Derived::~Derived(){

            std::cout<<" Derived Destructor callled\n";
            delete[] s;
        }