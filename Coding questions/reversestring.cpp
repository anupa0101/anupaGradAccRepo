#include<iostream>
#include<conio.h>
#include<string>
#include<algorithm>


int main(){

    std::string rs, s="anupa satharasinghe";
    std::cout<<s<<std::endl;

    for(int i=s.length()-1,j=0;i>=0;i--,j++){
       //rs[j]=s[i];  //   
       rs.push_back(s[i]);

    }
        

    std::cout<<rs<<std::endl;
    reverse(s.begin(), s.end());// need include algorithm
    std::cout<<s<<std::endl;
    return 0;
}