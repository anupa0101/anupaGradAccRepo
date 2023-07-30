#include <iostream>
#include<conio.h>




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
    Node *next;  //  a pointer to an object of node class
    Node *previous;  //  a pointer to an object of node class

    Node(){
        key=0;
        data=0;
        next=NULL;
        previous=NULL;
    }
    Node(int k, T d){
        key=k;
        data=d;
        next=NULL;
        previous=NULL;

     
    }


};
template<typename T>
class DoublyLinkedList{
    public:
        Node<T> *head;


        DoublyLinkedList(){
            head=NULL;
        }
        DoublyLinkedList(Node<T> *n){
            head=n;
        }

        //1 check if node with key value exists and returns its ptr. if not retursns null
        Node<T> *nodeExists(int k){ 
            Node<T> *temp=NULL; //store the ptr to the node with k key, returns null if not found
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
                        n->previous=ptr;//reverse link
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

                        
                        n->next=head;// forward link
                        head->previous=n;//revserse link
                        head=n; //declare new head
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
                std::cout<<"No node exists with key value "<<n->key<<std::endl;
            }
            else{ 
                //check if the node to be inserted has a unique key value
                if(nodeExists(n->key)!=NULL){ //see if the node to be inserted already exists
                    std::cout<<"Node to be inserted doesnt have a unique key value  "<<n->key<<std::endl;

                }
                else{// the to be inserted node has a unique key value
                    if(ptr->next==NULL){ //if at the last end- null node
                        ptr->next=n; //1. Linking inserted to the last node
                        n->previous=ptr;// reverse link 
                        
                        std::cout<<"Node inserted to the end"<<std::endl;
                    }
                    else{ //if NOT at the last end- null node
                        n->next=ptr->next; //1. Linking inserted to the next node
                        n->previous=ptr;// reverse link 
                        (ptr->next)->previous=n; //2. Linking the previous to the inserted
                        ptr->next=n;//linking prev node to inserted node
                        std::cout<<"Node inserted"<<std::endl;
                    }
                }
                
            }
            

        }

        //4. delete node  with key k

        void deleteNodeByKey(int k){// 
            
            if(head==NULL){
                std::cout<<"Doublylinked list already empty"<<std::endl;
            }
            else {//when not empty

                

                if(head->key==k){//if the node to be deleted is the head node
                        head=head->next;

                        std::cout<<"Head node deleted -unlinked"<<std::endl;
                        
                }
                else { 
                    
                    Node<T> *ptr=nodeExists(k);
                    Node<T> *nextNode=ptr->next; //need two pointers
                    Node<T> *prevNode=ptr->previous;
                     if(nextNode==NULL){//its the last node
                            prevNode->next=NULL;
                            std::cout<<"Node at the end deleted -unlinked"<<std::endl;

                     }
                     else{
                            prevNode->next=nextNode;//(ptr->previous)->next=ptr->next;
                            nextNode->previous=prevNode;//(ptr->next)->previous=ptr->previous;
                        std::cout<<"Node deleted -unlinked"<<std::endl;

                    

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




};

int main(){

    DoublyLinkedList<int> s;
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




    for (int i=0; i<4;i++){
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






    
    return 0;
}
