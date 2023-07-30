#ifndef VECTOR2_H
#define VECTOR2_H
class vector2{

    protected:
        float x,y;
    public:
        vector2();
        vector2(int,int);
        vector2(const vector2& ); //copy constructor- use this for deep copy especially of new createdd heap memeory. avoids the double delete in destructor
        //copy constructor is called when vector2 vec2= objofVec2;
        //new heap memory may require to be created 

        vector2& operator=(const vector2& );// copy assignment operator called when both objects are previously created ob1=ob2
        //remember syntax - return type is refference &.
        //here previously created heap memory on the lhs may require to be delted and then reallocated.
        //rule of 3- in a class if i have to implement atleast one of  destructor, copy constructor and copy assignment operator. chances are
//well have to implement all of these. reason- these are needed when dynamic memory allocation is needed.

        vector2( vector2&& ); // NO CONST HERE move constructors are used to transfer ownership. steal the resources. the initial objject wont point to the same resource anymore , the ownershhip is transferred.
//double ampersand && rvlaue refference
//	assign values from source to the objecct;
	//assign empty, null or nullptr to the member variables of the source.
     vector2& operator=(vector2&& );// move assignment operator
     // same as move assignment operator but check if assigneedd to itslf and return the *this
/* std::move can be used to achieve this.
classname ob1;
classname ob2=std::move(ob1);// no copy constructor. now ob1 will have null, empty, nullptr, 0 values . ownership transferred to ob2.
classname ob3;
ob3=std::move(ob1)// same as above; */
     

        virtual ~vector2();// mark the destructor of the base class as VIRTUAL. or else derivedd class destructor isnt called when pted by a base class ptr
        
       void PrintVector();
        void ADD(vector2 , vector2 );
        void SUB(vector2 , vector2 );
        void SetVector(double , double );
       
};


#endif