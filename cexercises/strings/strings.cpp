#include<iostream>
#include<conio.h>
#include<string>

int main(){



    std::string str1,str2;
    std::cout<<"enter string 1: ";
    getline(std::cin,str1);
    std::cout<<"enter string 2: ";
    getline(std::cin,str2);

    std::cout<<str1.length()<<std::endl;

    std::cout<<str1+str2<<std::endl;//string concatenation
    str1.append(str2); //=  str1+=str2;
    std::cout<<str1<<std::endl;//string concatenation


    str1.insert(4,"abc"); //insert abc starting at 4th index
    std::cout<<str1<<std::endl;
    str1.erase(4,3); //delete 3 characters starting from 4th index.
    std::cout<<str1<<std::endl;
    //string.erase(3) will erase all from 3


//to erase the last character
    str1.erase(str1.length()-1); 
    std::cout<<str1<<std::endl;
    str1.pop_back(); //same
    std::cout<<str1<<std::endl;


    //replace
    //str.replace(start,number of elmentd to replace,"what to replace with");
    str1.replace(2,2,"njend");
    std::cout<<str1<<std::endl;


    //search and remove "hell" from a string

    std::string str3="what the hell bro", str4="hell";

    str3.replace(str3.find(str4),str4.length(),"****");
       
    std::cout<<str3<<std::endl;

    //find first of //use to find the first vowel
    std::cout<<str1.find_first_of("aeiou")<<std::endl;// returns the index of the first character in the string

    //IF NOT FOUND. Then returns -1 or a large unsigned number(npos)
   if(str1.find_first_of("!")==-1) std::cout<<"not found"<<std::endl;


    //to get a substring
    std::cout<<str1.substr(3,4)<<std::endl;// start index and number of indexes


    

    getch();
    return 0;
}