#include<iostream>
#include<conio.h>
#include<list>
#include<iterator>


//INBUILT DOUBLY LINKED LISTS???

//TRAVERSAL IS SLOW BUT ADDING AND REMOVING IS FAST

void printList(const std::list<int>& ls){// USE CONST_ITERATOR WHEN PASSED IN AS CONST
    for(std::list<int>::const_iterator i=ls.begin();i!=ls.end();i++){
        std::cout<<*i<<"\t";

    }
}

void printlist( std::list<int>& ls){  //IMPORTANT, HOW TO TRAVERSE THE LIST 
    std::list<int>::iterator i; 
    for(i=ls.begin();i!=ls.end();i++){// BEGIN AND END RETURNS AN ITERATOR TO THE FIRST AND LAST NODE
        std::cout<<*i<<"\t";
    }
    std::cout<<std::endl;
}

int main(){

    std::list<int> l1,l2{1,2,3,4};

//PUSH BACK AND FRONT 
    l1.push_back(1);
    l1.push_back(2);
    l1.push_front(3);
    l1.push_front(4);
    printList(l1);


  l2.push_back(11);
    l2.push_back(211);
    l2.push_front(31);
    l2.push_front(1);  
    printlist(l2);

 
//print first node and last node
        std::cout<<*l1.begin()<<"\t";
 std::cout<<*l1.end()<<"\t";



    //pop functions

    l1.pop_back();
    l1.pop_back();
    l1.pop_front();
    printlist(l2);

    //SORT FUNCTION
    l2.sort();
    std::cout<<"sorted\n";
    printlist(l2);

    //REVERSE FUNCTION
    l2.reverse();
    std::cout<<"reversed\n";
    printlist(l2);

//SWAP FUNCTIONS
    l1.swap(l2);
    printlist(l2);

    std::cout<<l1.size()<<" is the size\n";

    //REMOVE A VALUE
    std::cout<<" after removing\n";

    l1.remove(1); //ENTER THE DATA TO BE REMOVED
    printlist(l1);
    //CLEAR THE LSIT
    std::cout<<" after clearing\n";
    l1.clear();

    printlist(l1);




    





    return 0;
}

