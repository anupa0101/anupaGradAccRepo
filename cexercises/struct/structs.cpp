#include<iostream>
#include<conio.h>
#include<string>
struct coordinates{

    int x;
    int y;
    char charx;

    void print_char(){
        std::cout<<charx<<std::endl;
    }

    

   

    

};

float area(int x,int y){
    return x*y;
}
float area(coordinates cord){
    return cord.x*cord.y;
}


int main(){

   coordinates c;
    c.x=12;
    c.y=10;
    std::cout<<area(c)<<std::endl;

    coordinates c2={1,2};// IMPORTANT

    std::cout<<area(c2);
    

    coordinates c3={1,2,'h'};// IMPORTANT
    std::cout<<area(c3);

    c3.print_char();    

    

    return 0;
}