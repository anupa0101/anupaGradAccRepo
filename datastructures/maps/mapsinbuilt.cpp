#include<iostream>
#include<conio.h>
#include<map>
#include<unordered_map>
#include<iterator>

//ordered set has time complxity of logn
//unordered has average time complxeitiy of o(1) and worst casse o(n)

//ordered maps is a type of self balcning binary search tree called red black tree
// unordered maps are hash maps- they are genrally faster. inserting and accessing is o(1)
//maps use a key value pair . key can be any datatype. even an object of custom data type(but then have to created a hash function)
//USING ORDERED MAPSWILL ARRANGE THE KEY VALUE PAIRS IN ASCENDING ORDER OR ALPHABETICALLY- MIOGHT BE USEFULL AT TIMES

//USE ORDERD MAPS WHEN U NEED IT SORTEDDDDDDDDD

//USEEMPLACE IN MAPS.

int main(){
    //DEFINING MAPS
    std::map<int, std::string> mp_intkey={{1,"anipa"},{4,"rhfvr"},{3,"hiurh"},{9,"huerkdc"}};
    std::unordered_map<char,int> mp_charkey={{'a',12},{'q',54},{'o',654}};

    //INSERTING VALUES TO THE MAP
    //can use insert function and pairs to do it- key value as a pair

    std::pair<char,int> p1={'f',74};
    mp_charkey.insert(p1);
    mp_charkey.insert(std::pair<char,int>('r',90)); 
    mp_charkey.insert({'x',54});//THIS ALSO WORKS THOUGH- USE {} ALWAYS
    mp_charkey.emplace('z',321);//DONT USE {} IN EMPLACE
    mp_charkey['l']=234;//IMPORTSNT. CREATES AND ADDS

    //ACCESSING VALUES USING KEY 
    std::cout<<mp_charkey.at('a')<<std::endl;
    //always use .at(). if the key doesnt exist then will return out of range
    std::cout<<mp_charkey['w']<<std::endl;//THIS WILL ACTUALLY add w to the map and returnthe defult value(0 here), deafult constructor is its an object. So dont use it for accessing
    

    //UPDATE VALUES USING KEY
    mp_charkey.at('q')=10;//WILL GIVE OUT OF RANGE IS IT DOESNT EXIST
    mp_charkey['l']=23;//WILL CREATE AND ADD IS ABSENT


    //DELETING VALUES USING KEY
    mp_charkey.erase('a');//just add the key to delete

    //FIND USING KEY- RETURNS AN ITERATOR
    auto itr= mp_charkey.find('x');
    if(mp_charkey.find('x')==mp_charkey.end()){
            //IF IT DOESNT EXIST, IT WILL POINT TO the end mp_charkey.end()
            std::cout<<"Doesnt exist"<<std::endl;
    }
    else{
        std::cout<<itr->first<<'\t'<<itr->second<<std::endl;
    }
   
    

    //check if emmpty 
    bool Ismepty= mp_charkey.empty();//will return true is empty
    //clear map
    //mp_charkey.clear();

    //SIZE OF THE MAP
    int size= mp_charkey.size(); //returns the size of the array
    std::cout<<"size::"<<size<<std::endl;
    //ITERATING THROUGH THE MAPS   
        std::cout<<"Print map"<<std::endl;
     std::unordered_map<char,int>::iterator it;
     for(it=mp_charkey.begin();it!=mp_charkey.end();it++){
            char key=it->first; //this is the key
            int value= it->second;//this is the value
            std::cout<<it->first<<'\t'<<it->second<<std::endl;
     } 
        std::cout<<"Print map"<<std::endl;       
     for(auto it=mp_charkey.begin();it!=mp_charkey.end();it++){
            //using dereferncing * and then .first and .second
            //because iterators are objects. also they are kind of like pointers
            char key=(*it).first; //this is the key
            int value= (*it).second;//this is the value
            std::cout<<key<<'\t'<<value<<std::endl;
     } 
        std::cout<<"Print map"<<std::endl;

      for(auto kv_pair : mp_charkey){// range based for looop 
            char key=kv_pair.first; //this is the key
            int value= kv_pair.second;//this is the value
            std::cout<<key<<'\t'<<value<<std::endl;

     }        

     

    return 0;
}