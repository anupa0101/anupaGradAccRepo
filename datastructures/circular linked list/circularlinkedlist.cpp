#include <iostream>
#include<conio.h>


// CIRCULAR LL ARE GOOD FOR START AND END OPERATIONS
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
template<typename T>
class CircularLinkedList{
    public:
        Node<T> *head;
        CircularLinkedList(){
            head=NULL;

        }
        CircularLinkedList(Node<T> *n){
            head=n;
            
        }

        //1 check if node with key value exists and returns its ptr. if not retursns null
        Node<T> *nodeExists(int k){ 
            Node<T> *temp=NULL; //store the ptr to the node with k key
            Node<T> *ptr= head; //start from head node
            if(ptr==NULL){
                return temp; // returns null if no nodes- head=null
            }
            else{ //traverse the LL to the NULL node

                do//we use do while because of head node. to check if key in head node
                {  if(ptr->key==k){   // if node found with k ket=y
                        temp=ptr;
                        break;
                    }
                    ptr=ptr->next; //move to next node
                }while(ptr!=head); //untill the last node(node with ptr->next pointing to head)
                return temp;
            }

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
                    n->next=head; //the head node when alone points to itself
                    std::cout<<"1st node appended"<<std::endl;
                }
                else{ //when this is not the first node
                        Node<T> *ptr=head; //starting from head
                        while(ptr->next!=head){ //till the last node- pointing to head node is reached

                            ptr=ptr->next;
                        }
                        ptr->next=n;//linking to the node
                        n->next=head; //linking last to the node
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
                        n->next=head;
                        std::cout<<"1st node appended"<<std::endl;
                    }
                else{  //when this is not the first node

                        Node<T> *ptr=head;
                        while(ptr->next!=head){ //goto last node

                            ptr=ptr->next;
                        }
                        ptr->next=n;//point last node next to new node 
                        n->next=head;// point new node next to old head
                        head=n;//make the new node to head
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
                    if(ptr->next==head){ //check if its the last node -pointing to head
                        n->next=head;// point the next of new last node to head
                        ptr->next=n; //point to the new last node
                        std::cout<<"Node inserted to the end"<<std::endl;
                        
                    }
                    else{// in the middle
                        n->next=ptr->next; //1. Linking inserted to the next node
                        ptr->next=n; //1. Linking the previous to the inserted
                        std::cout<<"Node inserted"<<std::endl;
                }
                
                }
                
            }
            

        }

        //4. delete node  with key k

        void deleteNodeByKey(int k){// 
            
            
            if(head==NULL){
                std::cout<<"circularly linked list already empty"<<std::endl;
            }
            else {//when not empty
                Node<T>* ptr=nodeExists(k);

                if(ptr==NULL){
                    std::cout<<"No node exists with key value "<<ptr->key<<std::endl;
                }
                else{

                    if(ptr==head){// if the one to be deleted is the head node

                        if(head->next==head){ //if the LL has only one node- head node only 
                                head=NULL;
                                std::cout<<"Head node deleted -unlinked. CLL empty"<<std::endl;

                        }
                        else{// k is head node and when more than one node is there in the linked list 
                          Node<T>* ptrx=head;
                          while(ptrx->next!=head){
                            ptrx=ptrx->next;

                          }
                            ptrx->next=head->next; //modfying the last nodes next
                            head=head->next;
                            std::cout<<"Head node deleted -unlinked"<<std::endl;
                        }
                    }
                    else{// if the one to be deleted is NOT the head node
//WORKS FOR THE END NODE TOO33###################################
                        Node<T> *temp=NULL;
                        Node<T> *pvrptr=head;
                        Node<T> *currentptr=head->next;
                        while(currentptr!=NULL){
                            if(currentptr->key==k){
                                temp=currentptr;
                                currentptr=NULL; //breaks loop, JUST USE BREAK
                            }
                            else{
                                pvrptr=pvrptr->next;//got next
                                currentptr=currentptr->next;

                            }
                        }
                        pvrptr->next=temp->next; //IF ITS THE LAST NODE BEING DELETED. TEMP IS THE LAST NODE
                        //SO TEMP->NEXT WILL POINT TO HEAD SO ITS ALL GOOD
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
                std::cout<<"No nodes on the circularly LL"<<std::endl;
            }
            else{
                Node<T> *n=head;
                do{
                        
                        std::cout<<"key :"<<n->key<<"\tData: "<<n->data<<std::endl;
                        n=n->next;
                }while(n!=head); //as soon as the last node (head) is reached looop breaks
                      
                        
              }
            }
        




};

int main(){

    CircularLinkedList<int> s;
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
