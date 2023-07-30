#include<iostream>
#include<memory>//NEED THIS HEADER FILE

//raw pointers allow sharing- can be advantageous also can be dangerous if theres multiple deletions. ALso can forget to delte
//also doesnt offer ownership
//smart pointers fixes these
//unique-scopedd pointer- CANT HAVE TWO POINTERS POINTING AT THE SAME MEMORY LOCATION- ESTABLISHES OWNERSHIP. AUTO DELETES
//Shared,- REFFFERNCE COUNTED SMART POINTER. AUTO DELETED AFETER ALL GO OUT OF SCOPE
//Weak- NON OWNING SMART PTR-

// objects should be assigned to smart pointers as soon as they are created. or else we might make mistakes like creating two seperate shsred pointers to the same object, not copying one shared poitner to the other.
// try to avoid using shared_ptrs with raw pointers because if we delte it the shared pointner will double delete when it goes out of scope
class UDT{
    public:
    UDT(){
        std::cout<<"UDT created"<<std::endl;
    }
    UDT(int x){
        std::cout<<"UDT created x"<<std::endl;
    }  
    UDT(int x,int y){
        std::cout<<"UDT created x y"<<std::endl;
    }  
    ~UDT(){
        std::cout<<"UDT destroyed"<<std::endl;
    }

};
int main(){


    //############### UNIQUE POINTER- lightweight than shared-preffered######################
    UDT* RAWudtPtr= new UDT;// will only create this wont destroy it
    std::unique_ptr<UDT> uniqUDTptr= std::make_unique<UDT>();//DEFAULT CONSTRUCTOR CALLED will create and destroy after going out of scope. no need to manuallly delete.
    // also cant assign to another ptr. This is a SCOPED POINTER. 
        UDT* RAWudtPtr1= new UDT(1);// will only create this wont destroy it-1st overloaded constructor
     std::unique_ptr<UDT> uniqUDTptr1= std::make_unique<UDT>(1);//1ST OVERLOADED CONSTRUCTOR CALLED will create and destroy after going out of scope. no need to manuallly delete.
    // also cant assign to another ptr. This is a SCOPED POINTER.

    UDT* RAWudtPtr2= new UDT(3,4);// will only create this wont destroy it-2nd overloaded constructor
     std::unique_ptr<UDT> uniqUDTptr2= std::make_unique<UDT>(3,4);//2ND OVERLOADED CONSTRUCTOR CALLED will create and destroy after going out of scope. no need to manuallly delete.
    // also cant assign to another ptr. This is a SCOPED POINTER. 
//FOR ARRAYS USE [] IN UNIQUE PTR

    UDT *arrayRawUDTptr= new UDT[10];//creates only(HAPPENS 10 TIMES) need delete[] arrayRawUDTptr to aovid mem leak
    std::unique_ptr<UDT[]> arrayUniqUDTptr= std::make_unique<UDT[]>(10);//???????creates array of udt objects. DEFAULT CONSTRUCTOR CALLEDD. creates and destroys 10  TIMES. scoped pointer

    //std::unique_ptr<UDT> uniqUDTptr3= uniqUDTptr2; ILLEGAL- cant copy AS IT MUST BE UNIQUE
    //HOWEVER WE CAN STD::MOVE
    std::unique_ptr<UDT> uniqUDTptr3= std::move(uniqUDTptr2);// moves the resource to uniqptr3 and uniqptr2 becomes null. if a function accepts a unique_ptr we will have to func(std::move(uniqPtr)) because we cant copy it to another

     //using uniqUDTptr3= nullptr or uniqUDTptr3.reset() will delete the obj 
    // using UDT* ptr= uniqUDTptr3.release();//here uniqUDTptr3 will give up ownership to the raw ptr. now uniqUDTptr3 is nullptr.
//##################### SHARED POINTER#######################################
// two pointers pointing to the same memory location. specially used in heap allocation.
// in smart pointers. refference counter is thread safe- protected in data races. shared pointes themselves arent thread safe. reffernce count is ATOMICally updated(in a single clock tik ( threads can write and update to it)
//data race= when two or more threads try to acess the shared resource. and atleast one is trying to modify it.
   // IF A SHARED POINTER STARTS POINTING AT ANOTHER OBJECT IN THE MIDDLE, THE ORIGINAL OBJECT IS DELTED IF THE REFFERENCE COUNT IS NOW ZERO. OR IF WE MAKE IT =NULLPTR ITS DELETED. ALSO .RESET() WILL DELETE IT
   
    std::shared_ptr<UDT> sharedUDTptr=std::make_shared<UDT>();// or mae_shared<UDT>(1,2) or make_shared<UDT[]>(10)
    std::shared_ptr<UDT> sharedUDTptr2;// same memeory location pointed by multiple pointers
    sharedUDTptr2=sharedUDTptr;// can copy to it as its a shared pointer. untill all go out of scope resource wont be deleted
    {
        std::shared_ptr<UDT> sharedUDTptr3= sharedUDTptr;// even when this goes out of scope. memory allocation wont be deleted till all the pointing ptrs go out of scope.
        std::cout<<sharedUDTptr3.use_count()<<std::endl;// this will print the refference count. function is . operator not ->
    }
//########################## weak pointer###########################
//non owninng ptr, doesnt increase reference count. usedd with shared ptr.
  //CAN BE USED TO BREAK CYCLES. AVOID CYCLIC POINTING. 
  //use in loops to avoid ref count increasing???
  
    std::weak_ptr<UDT> weakUDTptr;// nothing called make weak. weak is to assign to a shared ptr
    weakUDTptr=sharedUDTptr; //wont increment the reffernce count
    

    // WE CANNOT JUST DEREFFERENCE A WEAK POINTER WITH -> AND *. BECAUSE IT MIGHT NOT BE VALID AND ALSO MIGHT GET DELETED WHILE ACCESSING
    // so use .lock() will prevent deleting while being accessed and also will check if its still valid(will throw an exeption if invalid). USE weakUDTptr.expired() to check if expired then derefferencing is a good practice
   // *(weakUDTptr.lock()) and (weakUDTptr.lock())-> will work
    return 0;
}

//we can use std::static_pointer_cast, std::dynamic_pointer_cast and std::const_pointer_cast to cast shared pointers
/* example

std::shared_ptr<Derived> sp1= std::make_shared<Derived>();
auto BPtr== std::make_shared<Base>();

 BPtr= std::static_pointer_cast<Base>(sp1); // up the hierachy static cast to base pointer type
 sp1= std::dynanmic_pointer_cast<Derived>(Bptr); // down the hierachy dynamic cast to derived pointer type
 
 
 //CUSTOM DELETE function in shared_ptr. here we define a lambda for custom deletion
 synatx:
    std::shared_ptr<Dog> ptr1(new Dog("an"), [](Dog* p){ std::cout<<"custom delete"<<std::endl; delete p;});
    std::shared_ptr<Dog> ptr1(new Dog[3], [](Dog* p){ std::cout<<"custom delete"<<std::endl; delete[] p;});//C++q7 fixes this- deletes the whole array instead of just the first one, but in c++17 this special lambda is not needed. make_shared handles this
 
//////////CYCLIC REFFERENCE- WHERE TO USE WEAK_PTR
class Dog{
    private:
        std::shared_ptr<Dog> friend;//this causeses circular refference where none of them reach the 0 refference count
        // use weak_ptr to avoid this circular refference- THIS IS LIKE HEY I DON WANT OWNERSHIP OF THIS OBJECT, I ODNT WANT TO BE INVOLVED IN THE DESTRUCTION OF THIS OBJECT
    public:
        void makeFriends(std::shared_ptr<Dog> f){ assigns the input shared pointer to friend member varriable
            friend=f;
        }
};

int main(){

    std::shared_ptr<Dog> dg1= std::make_shared<dog>();
    std::shared_ptr<Dog> dg2=std::make_shared<Dog>();
    dg1->makeFriend(dg2);
    dg2->makeFriend(dg1); // here this causes circular refference. inside dg1 member variable points to dg2 and vise versa.
    //WHEN each object reffers each other(doesnt have to be same class even) -none reach the refference count zero to destroy
//HOW IT WORKS- when the destructor of an object is called it checks if there are any shared refferences , if there are it doesnt destruct
//when the destructor of the next object is called it checks if there are any shared refferences and it wont destruct. so at the end none is destructed
}



// VERY IMPORTANT- 

class Person{
    private:
        std::string* PtrName;// using a shared_ptr here will solve the issue of shallow copy, as the destructor will only be called when all go out of scope

    public:
        Person(std::string name):PtrName{new std::string(name)}{};
        ~Person(){
            delete PtrName;
        }
        void printName(){
            std::cout<<*PtrName<<std::endl;
        }  
}
int main(){
    std::vector<Person> personsVec;
    personsVec.push_back(Person("anupa")); // this will shallow copy the object created and when it goes out of scope it will get deleted.
    personsVec.front().printName(); // CRASH AS we are reffering to deletd memory.
//to avoid this can declare a proper deep copy constructor or use emplace_back  or use shared_ptr as the ptr(will call the destructor when all copies are out of scope)
// or use std::move to move it in.

}

 */