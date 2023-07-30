#include<iostream>
#include "Base.h"

Base::Base(): x{0},y{0}, a{new int[10]} {/// 
            std::cout<<"Base Constructor callled\n";
        }

Base::Base(int x):Base(){ //calls the non overloaed constrcutor inside
            this->x=x;
            std::cout<<"Base Overloaded constructor callled\n";
        }
Base::Base(int x, int y):x{x},y{y}{
            std::cout<<"Base Overloaded constructor callled\n";
        }


Base::Base(const Base& rhs){// copy constructor
    x=rhs.x;
    y=rhs.y;
   
    a=new int[10];
    
 
    for(size_t i=0; i<10;i++){// can use memcpy here
        
          a[i]=rhs.a[i];

    }
     std::cout<<"Base COPY constructor callled\n";

}

Base& Base::operator=(const Base& rhs){// copy assignment operator
 std::cout<<"Base copy assignement callled\n";
    if(this==&rhs){
        return *this;
    }

    else{// do the same in the copy constrcutor BUT DELETE PREVIOUS HEAP MEMORY
         x=rhs.x;
        y=rhs.y;
        delete[] a;// FIRST DELETE THE PREVIOUSLY CREATED MEMORY
        a=new int[10];
        for(size_t i=0; i<10;i++){// can use memcpy here
            a[i]=rhs.a[i];

        }
        return *this;
    }
}

  Base::Base( Base&& source ){ //NO CONST HERE. move constructors are used to transfer ownership. steal the resources. the initial objject wont point to the same resource anymore , the ownershhip is transferred.
//double ampersand && rvlaue refference
      
    x=source.x;// assign the vlaues from source to the object
    y=source.y;
    a=new int[10];
     for(size_t i=0; i<10;i++){// can use memcpy here
            a[i]=source.a[i];

        }
    
//THEN ASSIGN EMPTY,0, NULL OR NULLPTR TO the values of the source. ownership of source is taken away by assigning null. 
    source.x=0;
    source.y=0;
    delete[] source.a;// OR ELSE IT WOJNT BE DELETED IF ASSIGNED TO NULLPTR?????
    source.a=nullptr;//DELETINg NULLPTR IS OKAY
    std::cout<<"Base move constructor callled\n";

   }  

Base& Base::operator=(Base&& source)// move assignment operator
   { std::cout<<"Base move assignement callled\n";

     // same as move assignment operator but check if assigneedd to itslf and return the *this
  

      if(this==&source)// if its moved to isself
      {
         return *this;
      }
      else{
          x=source.x;// assign the vlaues from source to the object
          y=source.y;
        delete[] a;// FIRST DELETE THE PREVIOUSLY CREATED MEMORY
          a=new int[10];
        for(size_t i=0; i<10;i++){// can use memcpy here
            a[i]=source.a[i];

        }
    
//THEN ASSIGN EMPTY,0, NULL OR NULLPTR TO the values of the source. ownership of source is taken away by assigning null. 
    source.x=0;
    source.y=0;
    delete[] source.a;// OR ELSE IT WOJNT BE DELETED IF ASSIGNED TO NULLPTR?????
    source.a=nullptr;//DELETINF NULLPTR IS OKAY
         
         return *this;
      }
     }
void Base::set(const int& x,const int& y){

            this->x=x;
            this->y=y;

        }

void Base::print() const{// cant change the member variables inside unnless defined as mutable

            std::cout<<x<<'\t'<<y<<std::endl;

        }


Base::~Base(){

            std::cout<<"Base Destructor callled\n";
            delete[] a;
        }