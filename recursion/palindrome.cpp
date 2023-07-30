#include<iostream>
#include<conio.h>
#include<string>

bool isPalindrome(std::string s,int l, int r){
    if(l<r){//// base case- condition to stop/conditon to stop immediately if l crosses r , or l=r , means string is exhasuted. return true
            if(s.at(l)!=s.at(r)){ //additional base case- to handle non palindormes
                return false;
            }
            return isPalindrome(s,l+1,r-1);//shrink problem space
    }
    else{//base case- condition to stop/conditon to stop immediately if l crosses r , or l=r , means string is exhasuted. return true
        return true; 
    }

}

bool isPalindromeAnother(std::string s){
    if(s.length()==0||s.length()==1){// base case- condition to stop/conditon to stop immediately
        return true;
    }
    else{
        if(s.front()!=s.back()){ //additional base case to handle non palindormes
                return false;
            }
        return isPalindromeAnother(s.substr(1,s.length()-2));//shrink problem space
    }
   
}




int main(){

    std::string s="anuunka";
    bool result=isPalindrome(s,0,s.size()-1);
    bool res=isPalindromeAnother(s);
    std::cout<<result<<std::endl;
    std::cout<<res<<std::endl;
    
    return 0;
}