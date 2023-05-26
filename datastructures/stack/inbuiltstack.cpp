#include <iostream>
#include<conio.h>
#include<stack>
template <typename T>
void prints(std::stack<T> s){ //since its passed by value. stack isnt cleared off
    while(!s.empty()){ //print the stack while deleting all but its passed by value
        std::cout<<s.top()<<std::endl;
        s.pop();

    }
}


int main(){


    std::stack<int> s1;
    std::stack<int> s2;
    std::stack<char> s3;

    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s2.push(8);

    s2.swap(s1);// swaps s1 an s2

    std::cout<<"size: "<<s1.size()<<std::endl;

    prints<int>(s2);
    while(!s2.empty()){ //print the stack while deleting all
        std::cout<<s2.top()<<std::endl;
        s2.pop();

    }

    s3.push('a');
    s3.push('g');
    s3.push('y');
    prints<char>(s3);

    return 0;
}
