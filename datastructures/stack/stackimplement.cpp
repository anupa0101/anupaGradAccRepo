#include<iostream>
#include<conio.h>


template< typename T> 
class Stack{

    private:
        
        T *arr;
        int top; // like an index. -1 at begining. 
        int SIZE;

    public:
        Stack(); //top=-1, size is default 5
        Stack(int siz); // pointer array size
        ~Stack();// to delete memeory allocated 
        void push(T ); /// top++ , arr[top]
        T pop();  // arr[top], to--
        bool empty(); //top=-1
        bool full(); //when top =4
        int Top();// arr[top]
        int size(); // top+1
        void display();//top to bottom order



};

int main(){

        Stack<char> s1(3);
    s1.display();
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');

    s1.display();
   s1.pop(); 
     s1.display();

     std::cout<<s1.size()<<std::endl;
     std::cout<<s1.Top()<<std::endl;

    Stack<int> s2(3);
    s2.display();
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);

    s2.display();
   s2.pop(); 
     s2.display();

     std::cout<<s2.size()<<std::endl;
     std::cout<<s2.Top()<<std::endl;


    



    return 0;
}
template< typename T>
Stack<T>::Stack(){
    SIZE=5;

    arr=new T[SIZE];
    top=-1;
    for(int i=0;i<SIZE;i++){
        arr[i]=0;
    }
}
template< typename T>
Stack<T>::Stack(int siz){
    SIZE=siz;
    arr=new T[SIZE];
    top=-1;
    for(int i=0;i<SIZE;i++){
        arr[i]=0;
    }
}
template <typename T> 
Stack<T>::~Stack(){
    delete []arr;
    arr=nullptr;
    
}
template <typename T> 
void Stack<T>::push(T val){

    if(full()){
        std::cout<<"stack overflow"<<std::endl;
    }
    else{
        top++;
        arr[top]=val;
    }
    

}
template <typename T> 
T Stack<T>::pop(){
    if(empty()){
        std::cout<<"stack underflow"<<std::endl;
        return 0;
    }
    else{
        int temp=arr[top];
        arr[top]=0;
        top--;
        return temp;
    }
}
template <typename T> 
bool Stack<T>::empty(){
    return (top==-1);
}
template <typename T> 
int Stack<T>::Top(){
    if(empty()){
        std::cout<<"stack empty"<<std::endl;
        return 0;
    }
    else{
         return arr[top];

    }
    

}
template <typename T> 
bool Stack<T>::full(){
    return (top==(SIZE-1));
}
template <typename T> 
int Stack<T>::size(){
    return (top+1);
}
template <typename T> 
void Stack<T>::display(){

    for(int i=top;i>=0;i--){
        std::cout<<arr[i]<<'\t';
    }
    std::cout<<std::endl;
}