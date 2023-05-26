#include <iostream>
#include<conio.h>


// NO DYNAMC MEMROY ALLOCATIONS HERE
//HEAD NODE =====NULL NODE//CAN STORE DIFFERENT DATA TYPES

//ADV:EASY TO INSERT AND DELETE, DYNAMIC SIZE easily


//lets say {1,3,4,5} in an array to add 2 , have to move 3,4,5 right side. 
//in linked list its easier... same for deleting


//DISADV: RANDOM ACCESS NOT ALLOWED. SEQUENTIALY HAVE TO ACCESS FROM 1ST NODE
   //in array can just arr[5] but here have to go from each and check each node till meeting.
   
    //EXTRA MEMEORY FOR A POINTER
      //ELMENTS NOT IN CONTIGUOUS LOCATIONS SO NOT CACHE FRIENDLY



//////////if alot of adding and deleting and dynamic size needed use linked list
///if alot of random access like arfr[5] and save emory space then arrays
template<typename T>
class Node{

    public:
    int key; //unique key
    T data;
    Node<T> *next;  //  a pointer to an object of node class

    Node(){
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k, T d){
        key=k;
        data=d;
        next=NULL;

     
    }


};
template<typename T>// should i put it here or somewher else??? check
class SinglyLinkedList{
    public:
        Node<T> *head;


        SinglyLinkedList(){
            head=NULL;

        }
        SinglyLinkedList(Node<T>* n){
            head=n;
            
        }

        //1 check if node with key value exists and returns its ptr. if not retursns null
        Node<T>* nodeExists(int k){ 
            Node<T> *temp=NULL; //store the ptr to the node with k key
            Node<T> *ptr= head; //start from head node

            while(ptr!=NULL){ //traverse the LL to the NULL node

                if(ptr->key==k){   // if node found with k ket=y
                    temp=ptr;
                    break;
                }
                ptr=ptr->next; //move to next node
            }
            return temp;

        }

        //2. append node. 
        void appendNode(Node<T> *n){
            if((nodeExists(n->key))!=NULL){   //see if the node to be appended already exists
                std::cout<<"Node already exists with key value "<<n->key<<std::endl;
            }
            else{  //if theres no node with the same key
                if(head==NULL) //no nodes. this is first node
                {
                    head=n;
                    std::cout<<"1st node appended"<<std::endl;
                }
                else{ //when this is not the first node
                        Node<T> *ptr=head; //starting from head
                        while(ptr->next!=NULL){ //till the last node- null node is reached

                            ptr=ptr->next;
                        }
                        ptr->next=n;//linking to the node
                        std::cout<<"node appended"<<std::endl;
                }


                }

            }

            //3. prepend node. 
        void prependNode(Node<T> *n){

            if(nodeExists(n->key)!=NULL){ //see if the node to be appended already exists
                std::cout<<"Node already exists with key value "<<n->key<<std::endl;

            }

            else{     //if theres no node with the same key
                if(head==NULL) //no nodes. this is first node
                    {
                        head=n;
                        std::cout<<"1st node appended"<<std::endl;
                    }
                else{  //when this is not the first node

                        
                        n->next=head;
                        head=n;
                        std::cout<<"node prepended"<<std::endl;

                }

            }

        }

        //4. Insert node after a particular node with key k
        //first link to the next node
        //then link to the previous node or youll forget the pointr to the next node
        void insertNodeAfter(int k, Node<T> *n){

            Node<T> *ptr=nodeExists(k); //traverse to the node with key=k
            if(ptr==NULL){//if no node with key k exists
                std::cout<<"No node exists with key value "<<k<<std::endl;
            }
            else{ 
                //check if the node to be inserted has a unique key value
                if(nodeExists(n->key)!=NULL){ //see if the node to be inserted already exists
                    std::cout<<"Node to be inserted doesnt have a unique key value  "<<n->key<<std::endl;

                }
                else{// the to be inserted node has a unique key value
                    n->next=ptr->next; //1. Linking inserted to the next node
                    ptr->next=n; //1. Linking the previous to the inserted
                    std::cout<<"Node inserted"<<std::endl;
                }
                
            }
            

        }

        //4. delete node  with key k

        void deleteNodeByKey(int k){// 
            
            if(head==NULL){
                std::cout<<"Singlylinked list already empty"<<std::endl;
            }
            else {//when not empty

                if(head->key==k){//if the node to be deleted is the head node
                        head=head->next;
                        std::cout<<"Head node deleted -unlinked"<<std::endl;
                        
                }
                else { //find previous pointer
                    Node<T> *temp=NULL; //is this process easier in doubly linked lists-but still has to traverse so... can ust use nodexists..here cant becasue we need oprev ptr
                    Node<T> *prevptr=head; //need two pointers
                    Node<T> *currentptr=head->next;
                    while(currentptr!=NULL){ //not the last node
                        if(currentptr->key==k){
                            temp=currentptr;
                            currentptr=NULL; // breaksm while loop- use break???
                        }
                        else{
                            prevptr=prevptr->next; //go to next nodes
                            currentptr=currentptr->next;
            
                        }

                    }

                    if(temp!=NULL){ //temp is not  null so key k exist

                        prevptr->next=temp->next; //creating link between the previous and next nodes
                        std::cout<<"Node deleted -unlinked"<<std::endl;
                    }
                    else{
                        std::cout<<"Node with key value doesnt exist"<<std::endl;
                    }


                }
            }
                   
                                    

        }

        //6. update node by key
        void updateNodeByKey(int k, T d){

            Node<T> *ptr=nodeExists(k);// returns null if it doesnt exist
            if(ptr!=NULL){
                ptr->data=d;
                std::cout<<"Data updated"<<std::endl;
            }
            else{
                    std::cout<<"Node with key value doesnt exist"<<std::endl;
            }

        }

        //7. Print the result
        void printList(){
            

            if(head==NULL){
                std::cout<<"No nodes on the singly LL"<<std::endl;
            }
            else{
                Node<T> *n=head;
                while(n!=NULL){ //as soon as the last node NULL is reached looop breaks
                    std::cout<<"key :"<<n->key<<"\tData: "<<n->data<<std::endl;
                    n=n->next;
                }
            }
        }
        //8. reverse a list


        void reverseList(){// reverse the list
            if(head==NULL){
                std::cout<<"No nodes on the singly LL"<<std::endl;
            }
            else{
               
                Node<T> *prev=NULL;// pointer ot the previous node
                Node<T> *curr=head;//pointer to the current nodenode
                Node<T> *temp;//pointer to the next node of the current node
                while(curr!=NULL){ //as soon as the last node NULL is reached looop breaks
                    temp=curr->next;//stores the address to the next pointer. or else its lost in the next step
                    curr->next=prev;//point to the previous to reverse
                    prev=curr;//prev->next is WRONGGGG. As prev->next is now reffering back
                    curr=temp;//advance to the next node                      
                }
                //head->next=NULL;//no need now- make head the last node. assign null to the next 
                head=prev;//assign the new head
                std::cout<<"Reversed"<<std::endl;
            }

        }


    Node<T>* reverseListRecursivey(Node<T> *n){// reverse the list
            if(n==NULL ){ //base case. terminate immediateely if input is null o
                return n;
               
            }
            if(n->next==NULL){//exit condition  additonal base case. if n->next is null. means end of list. so assign head to the curretn node
                head=n;//make the new head 
                return n; //first trasverse to the last node and make it head
            }

            Node<T> *temp=reverseListRecursivey(n->next);//essentially returns the input node (next node here) (also sets new head at the last node)
            temp->next=n;// make the next of the (next node) point to current node. REVERSING
            n->next=NULL;//this will be called several times and overwritten. untill last time where the first node's next will be assigned null
            return n;

        }
    void selectionsort(){//hard to use buuble sort because we need to keep track of the nodes to reduce the sorted. 
            for(Node<T> *i=head; i->next!=NULL;i=i->next){//stops at the one before the last
                //THIS IS NOT CORECT SELECTION SORT- find minmum on the right hand side and swap is selection sort- change this?
                for(Node<T> *j=i; j!=NULL;j=j->next){//stops at the last
                    if((i->data)>(j->data)){//swap values
                        T temp=i->data;
                        i->data=j->data;
                        j->data=temp;
                    }
                }          
            }
        }

        Node<T> *mergeTwoSortedLL(Node<T> *A, Node<T> *B){//at the end will return  the head node of the new merged list(smallest of the two nodes)
            if(A==NULL){ //base cases- if A is empty return B
                return B;
            }
            if(B==NULL){ //base cases- if B is empty return A
                return A;
            }

            if((A->data)<(B->data)){
                A->next=mergeTwoSortedLL(A->next,B);//makinng problem space smaller
                return A;//returns the smaller one

            }
            else{
                B->next=mergeTwoSortedLL(A,B->next);//makinng problem space smaller
                return B;//returns the smaller one
            }

        }




};

int main(){

    SinglyLinkedList<int> s;
    int k, d;
    Node<int> n1(11,22), n2(45,89), n3(12,54),n4(456,89);
     s.deleteNodeByKey(11);
    //append
    s.appendNode(&n1);  //pass the address of n1;
    s.printList();

    //or create a ptr and pass it
    Node<int> *ptrn2;
    ptrn2=&n2;
    s.appendNode(&n2); 
    s.printList();

//prepend
    s.prependNode(&n3);  //pass the address of n1;
    s.printList();

//delete node
     s.deleteNodeByKey(11);
        s.printList();
//insert node
        s.insertNodeAfter(12,&n4);
        s.printList();
//
        s.updateNodeByKey(45,0);
        s.printList();




    for (int i=0; i<2;i++){
        Node<int> *nd= new Node<int>(); // IF JUST ADDED LIKE NODE N... ATEACH ITERATION N WILL BE DESTORYED. 
        //WE DONT WANT IT TO BE DESTROYED 
        //HERE WE CREATE MEM0RY ON THE HEAP AND WILL STAY TILL DELETED
        std::cout<<"key value: "<<std::endl;
        std::cin>>k;
        std::cout<<"data value: "<<std::endl;
        std::cin>>d;
        nd->data=d;
        nd->key=k;

        s.appendNode(nd);



    }

    s.printList();

    s.reverseList();
    s.printList();
    std::cout<<"reverse again"<<std::endl;
     s.reverseListRecursivey(s.head);
    s.printList();
     std::cout<<"sorted"<<std::endl;
    s.selectionsort();

     s.printList();






    
    return 0;
}
