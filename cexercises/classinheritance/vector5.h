#ifndef VECTOR5_H
#define VECTOR5_H
#include"vector3.h"
#include"vector4.h"
class vector5: public vector3, public vector4 {

  
        
    public:
        vector5();
        vector5(int,int,int, int);
        void PrintVector();
        void ADD(vector5 , vector5 );
        void SUB(vector5 , vector5 );
        void SetVector(double , double , double, double );
       
};


#endif