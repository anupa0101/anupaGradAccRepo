#include<iostream>
#include<conio.h>
#include<unordered_set>
#include<iterator>

//USE ORDERED SET WHEN NEEDED IN SORtED ORDER
//ordered set has time complxity of logn
//unordered has average time complxeitiy of o(1) and worst casse o(n)


int main(){

    std::unordered_set<char> setChar={'c','c','C','a','d'};

    for(auto it=setChar.begin();it!=setChar.end();it++){
        std::cout<<*it<<'\t';
    }
        std::cout<<std::endl;


    //Inserting elements
    setChar.insert('q');
    setChar.insert('c');//duplicates are ignored

    //Erase elements

    setChar.erase('c');

    //find if exists
    if(setChar.find('q')!=setChar.end()){
        std::cout<<"found"<<std::endl;
    }

     setChar.insert('c');




    
    for(auto it=setChar.begin();it!=setChar.end();it++){
        std::cout<<*it<<'\t';
    }
        std::cout<<std::endl;

    



    return 0;
}