#include<iostream>
//functions have pointers too- memory addreses
//assigns a funtion to variable
//FUNCTION POINTER SYNTAX: returnType/void(*nameOfPointer)(paramter types list)
//USE FUNCTION POINTERS TO PASS IN FUNCTIONS AS PARAMTERS TO OTHER FUCNTIONS

char ret(){
    return 'a';
}
void none(){

}
int add(int x, int y){

    return x+y;
}
int mul(int x, int y){

    return x*y;
}
 void mulnPrint( int x, int y, void(*PF)(int)){// takes in a pointer to a function as input paramter

    PF(x*y);// calls the function by the pointer
 }

void printx(int x){
    std::cout<<x<<std::endl;
}
void printNothn(int x){
    std::cout<<"Nothing"<<std::endl;
}

void forEach(const std::vector<int>& vec, void(*funcPtr)(int)){// performs the function on each of the elements of the passed in vector
    for(const int& v: vec){
        funcPtr(v);
    }
}

int main(){ 

    int(*PFadd)(int,int);// return type followed by the * pointer name folloed by the parameter list
    PFadd=add; //& is optional, its implicit
    auto PFmul=mul;//auto can also be used but preffer explicit
    char(*PFret)()=ret;
    void(*PFnone)()=none;// for void return type use void
    std::cout<<PFadd(2,3)<<std::endl;
    std::cout<<PFmul(2,3)<<std::endl;
    std::cout<<ret()<<std::endl;

    void(*PFprintx)(int)=printx;
    void(*PFPrintNothing)(int)=printNothn;

    mulnPrint(2,3,PFprintx);// can use the specially defined function pointer or just use the function name
    mulnPrint(2,3,printNothn);// just using the function name

    int ip=0;
    void(*PFfun)(int);
    //auto PFfun; wont work because we need to  initialize auto at declaration
    std::cout<<"Enter function";
    std::cin>>ip;

    if(ip==1){
        PFfun=printx;
      //  mulnPrint(2,3,printx);

    }
    else if(ip==2){
        PFfun=printNothn;
        //  mulnPrint(2,3,printNothn);
    }

    mulnPrint(2,3,PFfun);// decides which function to call based on user input
    std::vector<int> vec= {1,2,3,4};
    forEach(vec, PFprintx);// passing function pointers
    forEach(vec,[](int value){//passing a lambda
        std::cout<<value<<std::endl;
    })







    return 0;
}