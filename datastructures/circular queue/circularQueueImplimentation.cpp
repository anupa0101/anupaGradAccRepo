#include<iostream>
#include<conio.h>

//  ONLY DIFFERENCE IS INSTEAD OF REAR++ IN ENQUEUE >>> USE REAR=(REAR+1)%SIZE; >>generates indexes between 0 and size
//INSTEAD OF FRONT++ IN DEQUEUE >>> USE FRONT=(FRONT+1)%SIZE; >>generates indexes between 0 and size
//AND IN FULL()  INSTEAD OF rear==(SIZE-1)   CHECHK (REAR+1)%SIZE==FRONT  >>>chekn if rear and left circularly adjacent
template< typename T> 
class Queue{

    private:
        
        T *arr;
        int front; // like an index. -1 at begining. 
        int rear; // like an index. -1 at begining. 

        int SIZE;

    public:
        Queue(); //rear=-1, size is default 5
        Queue(int siz); // pointer array size
        ~Queue();// to delete memeory allocated 
        void enqueue(T ); /// rear++ , arr[rear]
        T dequeue();  // arr[rear], to--
        bool empty(); //rear=-1
        bool full(); //when rear =4
        
        int size(); // rear+1
        void display();//rear to bottom order



};

int main(){

        Queue<char> q1(3);
    q1.display();
    q1.enqueue('a');
    q1.enqueue('b');
    q1.enqueue('c');
    q1.enqueue('d');

    q1.display();
   q1.dequeue(); 
     q1.display();

     std::cout<<q1.size()<<std::endl;
    

    Queue<int> q2(3);

    q2.display();
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);

    q2.display();
   q2.dequeue(); 
   q2.display();
   q2.enqueue(1);
     q2.display();

  
 
 
    



    return 0;
}
template< typename T>
Queue<T>::Queue(){
    SIZE=5;

    arr=new T[SIZE];
    front=rear=-1;
    for(int i=0;i<SIZE;i++){
        arr[i]=0;
    }
}
template< typename T>
Queue<T>::Queue(int siz){
    SIZE=siz;
    arr=new T[SIZE];
    front=rear=-1;
    for(int i=0;i<SIZE;i++){
        arr[i]=0;
    }
}
template <typename T> 
Queue<T>::~Queue(){
    delete []arr;
    arr=nullptr;
    
}
template <typename T> 
void Queue<T>::enqueue(T val){

    if(full()){
        std::cout<<"Overflow"<<std::endl;
        return;
    }
    else if(empty()){//start by making all zero
        rear=front=0;
        arr[rear]=val;
    }
    else{
        rear=(rear+1)%SIZE;// #####################
        arr[rear]=val;
        
    }
    

}
template <typename T> 
T Queue<T>::dequeue(){

    T x;
    if(empty()){
        std::cout<<"underflow"<<std::endl;
        return 0;
    }

    else if(front==rear){ // if all others are removed and an element remains in the middle of the queue
        x=arr[front];
        front=rear=-1;// reset the front and rear to begining
        return x;

    }
    else{
        x=arr[front];
        arr[front]=0;// makes it zero(removes it)
        front=(front+1)%SIZE;//################# takes the front forward
        return x;
    }
}
template <typename T> 
bool Queue<T>::empty(){
    return ((rear==-1)&&(front==-1))?true:false;
}



template <typename T> 
bool Queue<T>::full(){
    return (((rear+1)%SIZE)==(front));//###### chekn if rear and left circularly adjacent
}
template <typename T> 
void Queue<T>::display(){

    for(int i=0;(i<SIZE);i++){
        std::cout<<arr[i]<<'\t';
    }
    std::cout<<"\n front: "<<front<<"\t rear:"<<rear<<"\ndone"<<std::endl;
}