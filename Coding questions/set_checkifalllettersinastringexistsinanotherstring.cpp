

#include<iostream>
#include<conio.h>
#include<unordered_set>
#include<iterator>
#include<string>
//see if all letterss in a string is also present in another string
//use hash set. unordered set
//add all charcters in string 1 to hash set
//iterte through string 2 and find and erase from hash set
//if empty at the end. all charcters in string 1 is also in string 2


int main(){
    std::unordered_set<char> letters; //stores the unique letters
    std::string st1="aunpzaun";
    std::string st2="anupais amzng";


    for(int i=0;i<st1.size();i++){//create the unique set of letters in st1
        char c=st1[i];
        letters.insert(c);
    }
    for(int i=0;i<st1.size();i++){//create iterate througgh st2, delete from set if found
            letters.erase(st1[i]);//no need to check if it exists. can just delete
        /* if(letters.find(st1[i])!=letters.end()){//if found in the set
            letters.erase(st1[i]);
        } */
    
    }
    if(letters.size()==0){//if set empty that means confirmed
        std::cout<<"confirmed"<<std::endl;
    }
   
return 0;
}