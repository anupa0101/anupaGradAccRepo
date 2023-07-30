#ifndef VECTOR4_H
#define VECTOR4_H
#include"vector2.h"
class vector4: public virtual vector2{

    protected:
        float z,v;
    public:
        vector4();
        vector4(int,int,int, int);
        void PrintVector();
        void ADD(vector4 , vector4 );
        void SUB(vector4 , vector4 );
        void SetVector(double , double , double, double );
       
};


#endif