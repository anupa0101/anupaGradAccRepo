#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>


std::string dectobin(int val){
    if(val==0){//base cases and instantly stop conditions
        return "0";
    }
    if(val==1){
        return "1";
    }

    return  dectobin(val/2)+ std::to_string(val%2) ; //shrink problem space
    

}

int dectobinInt(int val){
    if(val==0){//base cases and indtantly stop conditions
        return 0;
    }
    if(val==1){
        return 1;
    }

    return   10*dectobinInt(val/2) + (val%2) ; //shrink problem space
    

}






int main(){
    int s=123;
    std::string result=dectobin(s);
    std::cout<<result<<std::endl;
    std::cout<<dectobinInt(123)<<std::endl;
    return 0;
}