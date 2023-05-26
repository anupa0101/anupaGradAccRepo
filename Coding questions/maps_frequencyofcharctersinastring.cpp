#include<iostream>
#include<conio.h>
#include<map>
#include<iterator>
#include<string>
//display the frequency of each character in a string in sorted way
//use map to get sorted output
//HERE JUST USED FREQ[CHAR]++, IF THE CHAR IS UNAVAIABLE IT WILL ADD TO THE MAP AND INCREMENT IT. IF ITSAVAIABLE THEN WILL JUST INCREMENT IT WIHTOUT ADDING A NEW ONE

int main(){

    std::string sname="anupa is the best boy fala lala lala lalaalla";

    std::map<char,int> freq;

     for( char n: sname){
        freq[n]++; //if unavilable it will create(first make value 0) and increment. if already avaiable will increment without adding a duplicate
    }

//same thing but harder way. check if exists, add and incrent
    for(char n: sname){// 
    if(freq.find(n)==freq.end()){// charcter isnt in the map
        freq.insert(std::pair<char,int> (n,1)); // add to map and add 1 to value
    }
    else{
        freq.at(n)+=1;// or freq[n]++ since
    }

    }
        

    for(auto kv: freq){

        std::cout<< kv.first<<'\t'<<kv.second<<std::endl;
    }
    return 0;
}
