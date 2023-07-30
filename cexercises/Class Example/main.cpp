#include<iostream>
#include"Base.h"
#include"Derived.h"

int main(){
    
   Base b1;
    Base b2(2,4);
    Base b3(6);
   
   Base b4=b1;// copy constructor
   b3=b1;// copy assignment
   Base b=std::move(b1);// move constructor
    b1=std::move(b3);// move assignment
    Base& b9=b3; 

    

    //b1.print();
    //b2.print();

    //Derived d1;
   // Derived d2(3);
   // Derived d3(1,2,3);
   // d3.print();

  Base* Bptr1=new Derived(1,1,1);
  delete Bptr1;


    return 0;
}