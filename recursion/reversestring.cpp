#include<iostream>
#include<conio.h>
#include<string>

std::string reveseString(std::string& s){
    if(s.size()==0){ //base case- condition to stop/ condition to stop immeddiately if given
        return "";
    }

    return s.back() +reveseString(s.substr(0,s.size()-1) );//shrink problem space

}

void reveseStringBySwap(std::string &s, int l, int r){
    if(l<r){//base case- condition to stop/ condition to stop immeddiately if given
        char temp=s[l]; //swap the characters
        s[l]=s[r];
        s[r]=temp;
        reveseStringBySwap(s,l+1,r-1);//shrink problem space

    }
    else{//base case- condition to stop/ condition to stop immeddiately if given
        return;
    }
        

    }



int main(){

    std::string result, s="anupa is amazing";
    result=reveseString(s);
    std::cout<<result<<std::endl;
    reveseStringBySwap(s,0,s.size()-1);
     std::cout<<s<<std::endl;
    return 0;
}