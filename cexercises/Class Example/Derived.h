#ifndef DERIVED_H
#define DERIVED_H

#include "Base.h" //INCLUDE THE BASE CLASS HEADER IN THE DERIVED CLASS HEADER FILE


class Derived:public Base{

    protected:
        int z;
        char* s;
     
    public:

        Derived();   
    
        Derived(int x);

        Derived(int x, int y, int z);

      

         void set(const int& x,const int& y) override;

         void print() const override;

        ~Derived();



};

#endif