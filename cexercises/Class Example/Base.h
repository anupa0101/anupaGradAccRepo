#ifndef BASE_H
#define BASE_H

class Base{

    protected:
        int x;
        int y;
        int *a;
    public:

        Base();   
    
        explicit Base(int x);

        Base(int x, int y);

Base(const Base& ); //copy constructor- use this for deep copy especially of new createdd heap memeory. avoids the double delete in destructor
        //copy constructor is called when Base bas1= objofbas;
        //new heap memory may require to be created 
        //DONT NEED TO DELETE PREVIOUS HEAP MEMORY- THIS IS FIRST ALLOCATION

        Base& operator=(const Base& );// copy assignment operator called when both objects are previously created ob1=ob2
        //remember syntax - return type is refference &.
        //DELTE PREVIOUSLY CREATED HEAP MEMORY
        //here previously created heap memory on the lhs may require to be delted and then reallocated.
        //rule of 3- in a class if i have to implement atleast one of  destructor, copy constructor and copy assignment operator. chances are
//well have to implement all of these. reason- these are needed when dynamic memory allocation is needed.
//NEED to check if assigned to itself
// copy assignment operator
/*       if(this==&rhs){ //checking for self assginment, then do nothing
         return *this;// this is a pointer
      }
      else{
       //do soemting
      }
      return *this;// return itself */

        Base( Base&& ); // NO CONST HERE move constructors are used to transfer ownership. steal the resources. the initial objject wont point to the same resource anymore , the ownershhip is transferred.
//double ampersand && rvlaue refference
//	assign values from source to the objecct;
	//assign empty, null or nullptr to the member variables of the source.
   //DONT NEED TO DELETE PREVIOUS HEAP MEMORY- THIS IS FIRST ALLOCATION. BUT DELETE THE SOURCE'S HEAP??? OR ELSE WONT BE DELTED INN DESTRCUTOR IF POINTING TOM NULLPTR?????

     Base& operator=(Base&& );// move assignment operator
        //DELTE PREVIOUSLY CREATED HEAP MEMORY
     // same as move assignment operator but check if assigneedd to itslf and return the *this
/* std::move can be used to achieve this.
classname ob1;
classname ob2=std::move(ob1);// no copy constructor. now ob1 will have null, empty, nullptr, 0 values . ownership transferred to ob2.
classname ob3;
ob3=std::move(ob1)// same as above; */
     

        virtual ~Base();// mark the destructor of the base class as VIRTUAL. or else derivedd class destructor isnt called when pted by a base class ptr

        virtual void set(const int& x,const int& y);

        virtual void print() const;


     


};


#endif