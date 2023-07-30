#include <iostream> 

class Base{
    private: 
        int x, y;
    public:
 
    Base():x{0},y{0}{
        
    }       
        virtual void Print(Base& b){
            std::cout<<"Base function"<<std::endl;

        }

};

class Derived: public Base
{
    private: 
        int x, y;
    public:

    explicit Derived():x{0},y{0}{
        
    }    
        void Print(Base& b) override{
            std::cout<<"Derived function"<<std::endl;

        }
};


        void func(Base obj){
            obj.Print(obj);
             std::cout<<"Base obj function"<<std::endl;           
        }
 int main(){

    Derived derivedObj;
    Base baseObj;

    func(derivedObj);
    Base* basePtr=&derivedObj;
    Base& baseRef=derivedObj;

    Derived* derivedPtr=&derivedObj;
    Derived& derivedRef= derivedObj;

    baseRef.Print(derivedObj);
    basePtr->Print(*basePtr);

    derivedRef.Print(derivedObj);
    derivedPtr->Print(*derivedPtr);

    return 0;
 }