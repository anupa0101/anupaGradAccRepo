#include <iostream>
#include<conio.h>
#include<queue>
//ENQUEUE IS LIKE Q1.PUSH() 
//DEQUEUE IS LIKE Q1.FRONT AND Q1.POP() 


template <typename T>
void prints(std::queue<T> s){ //since its passed by value. queue isnt cleared off
    while(!s.empty()){ //print the queue while deleting all but its passed by value
        std::cout<<s.front()<<'\t';
        s.pop();

    }
    std::cout<<std::endl;
}


int main(){


    std::queue<int> q1;
    std::queue<int> q2;
    std::queue<char> q3;

    q1.push(2);
    prints<int>(q1);
    q1.push(3);
    prints<int>(q1);
    q1.push(4);
    q1.pop();
    prints<int>(q1);
    q1.push(5);
    prints<int>(q1);
   
    q2.push(8);
    prints<int>(q2);

    q2.swap(q1);// swaps q1 an q2
prints<int>(q1);
prints<int>(q2);
    std::cout<<"size: "<<q1.size()<<std::endl;

    prints<int>(q2);
    while(!q2.empty()){ //print the queue while deleting all
        std::cout<<q2.front()<<std::endl;
        q2.pop();

    }

    q3.push('a');
    q3.push('g');
    q3.push('y');
    prints<char>(q3);

    std::cout<<q2.front()<<std::endl<<q2.back();

    return 0;
}
