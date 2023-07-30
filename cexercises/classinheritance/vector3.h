#ifndef VECTOR3_H
#define VECTOR3_H
#include"vector2.h" // includethe base class header
class vector3: public virtual vector2{

    protected:
        float z;
    public:
        vector3();
        vector3(int,int,int);
        vector3(const vector3& ); //copy constructor- use this for deep copy especially of new createdd heap memeory. avoids the double delete in destructor
         //copy constructor is called when vector3 vec3= objofVec3; 
         //new heap memory may require to be created 
    vector3& operator=(const vector3& );// copy assignment operator called when both objects are previously created ob1=ob2
        //remember syntax - return type is refference &.
        //here previously created heap memory on the lhs may require to be delted and then reallocated.

        ~vector3() override;// override keyword can be use to mark base class VIRTUAL methods that are overriden
       // void PrintVector() ;
        void ADD(vector3 , vector3 );
        void SUB(vector3 , vector3 );
        void SetVector(double , double , double );
       
};


#endif