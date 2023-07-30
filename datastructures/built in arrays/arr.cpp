#include<iostream>
#include<conio.h>

#include<array>

//c style arrays decay into a pointer and also does not carry the 
//size 
//std::arrays will have fuctions like size, fill, back ,front,empty etc
//while having the performance advantages of c style arrays
//just like c style arrays it is passed by REFFERENCE???? not by value

void printarr(std::array<int,5> arrr){
    arrr.fill(9);// fill all with 9
    for(const int& val: arrr){
        std::cout<<val;
    }
}
int main(){

    std::array<int,5> arrr={1,2,3,4,5};

    std::cout<<arrr.at(3);// at with bounds checking 
    std::cout<<arrr[1];// without bounds checking
    std::cout<<arrr.front();//front
    std::cout<<arrr.back();//back
    arrr.fill(0);//fill all with 0
    std::cout<<arrr.back();
    std::cout<<arrr.empty();//is empty?
    std::cout<<arrr.size();//size
    printarr(arrr);
  
    



    return 0;
}