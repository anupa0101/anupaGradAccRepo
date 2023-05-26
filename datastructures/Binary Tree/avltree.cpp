//AVL tree is a type of self balancing binary search tree.
// difference between heights of left and right subtree of Each node is not more than one//difference is called balance factor BF={-1.0.1}
#include<iostream>
#include<conio.h>
#define SPACE 10
// faster search than AVL as its balanced. May be slower insertion and deletion due to balancing
//both avg and worst case time complexity of traversing/searching, inserting and deleting (o(logn)) 
//but in unbalanced bst worst case of these may be o(n)

//basic types of rotaions- right (for LL imbalance), left(for RR imbalance), right-left(for RL imbalance), left -right(for LR imbalance) rotations. 
//only 3 nodes are considered in roatations - all others are ignored

class TreeNode{

    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(){
            
            val=0;
            left=NULL;
            right=NULL;
        }
        TreeNode(int v){
            
            val=v;
            left=NULL;
            right=NULL;
        }
};

class AVL{
    public:
        TreeNode *root; 
        AVL(){

            root=NULL;
        }

        bool isTreeEmpty(){ //check if the root is still assigned null(no nodes added yet)
            if(root==NULL){
                return true;
            }
            else{
                return false;

            }

        }

//              y         
//          x         ->          x
//       Z     T2            z          y
//                                   T2

        TreeNode *rightRotate(TreeNode *y){//returns the new parent node
            TreeNode *x= y->left; //left child of y
            TreeNode *T2=x->right;//right child of x
            //T2 and Z can be null too 

            //perform roatation
            //x is the pivot
            x->right=y;//make y the right child of pivot x 
            y->left=T2; //make T2 the left child of y. 
            return x; //return new parent
                        
        }

//              y         
//                  x         ->            x
//               T2      z             y         z
//                                       T2

            TreeNode *leftRotate(TreeNode *y){//returns the new parent node
            TreeNode *x= y->right; //right child of y
            TreeNode *T2=x->left;//left child of x
            //T2 and Z can be null too 

            //perform roatation
            //x is the pivot
            x->left=y;//make y the left child of pivot x 
            y->right=T2; //make T2 the righy child of y. 
            return x; //return new parent
                        
        }

        int heightRecursively(TreeNode *n){ //find the height of node recursively// watch video to understand//or draw tree
                //time and space complexity is o(h) in recursive. Bad for deep trees. non recursive is both o(n) n- number of nodes. 
            if(n==NULL){ //assigns -1 to the variable when met with dead end
                return -1;
            }
            int lheight= heightRecursively(n->left);
            int rheight= heightRecursively(n->right);
            if(lheight>rheight){//when left height greater than right height
                return (lheight+1);
            }
            else{  //when left height smaller than or equal to right height
                return (rheight+1);
            }

        }

        int getBalanceFactor(TreeNode *n){
            if(n==NULL){
                return -1;
            }
            else{

                return heightRecursively(n->left)-heightRecursively(n->right);
            }
        }



        TreeNode *insertNodeRecursively(TreeNode *current_node, TreeNode *new_node){// here this wont work for the first node(root node)- wont the root
        //because when insertNodeRecursively(Bstree.root, TN1) is called. Bstree.root pointer is passed by value not by reffernce. so use
        //Bstree.root= insertNodeRecursively(Bstree.root, TN1)
        //can use pass by refference of pointers too insertNodeRecursively(TreeNode **current_node, TreeNode *new_node)
        //insertNodeRecursively(&Bstree.root, TN1) and pass the address to the pointer BUT NEEDS ALOT OF CHANGE I GUESSS- coudlnt do it here

            if (current_node==NULL){  //not just for empty node. it also terminates the redursion(sometimes)
                current_node=new_node;
                return current_node;
            }

            if(new_node->val<current_node->val){ //left subtree
                current_node->left=insertNodeRecursively(current_node->left,new_node);

            }
            else if(new_node->val>current_node->val){//right subtree
                current_node->right=insertNodeRecursively(current_node->right,new_node);

            }
            else{
                std::cout<<"Duplicates not allowed"<<std::endl;
                return current_node;
            }
            //new node is added by now- lets do the rotations if required

            int bf=getBalanceFactor(current_node);// calculates the bf of all associated nodes when insertng 


            if((bf>1)&&(new_node->val)<((current_node->left)->val)) //for LL imbalance        current_node
            {                                                       //               current_node->left      
                return rightRotate(current_node);                  //            new_node
            }

            if((bf<-1)&&(new_node->val)>((current_node->right)->val)) //for RR imbalance    current_node
            {                                                                  //               current_node->right 
                return leftRotate(current_node);//                                                                new_node
            } 

            if((bf>1)&&(new_node->val)>((current_node->left)->val)) //for LR imbalance                        current_node
            {      
                current_node->left= leftRotate(current_node->left); //left rotate   //        current_node->left 
                return rightRotate(current_node);//right rotate                                             new_node
            }
            if((bf<-1)&&(new_node->val)<((current_node->right)->val)) //for RL imbalance                           current_node
            {      
                current_node->right= rightRotate(current_node->right); //right rotate   //                                         current_node->left 
                return leftRotate(current_node);//  left rotate                                                                new_node
            }

            return current_node;
        }




        TreeNode* minValueNode(TreeNode *n){//to get the minimum node of the right subtree(n will be somtn->right to select the right subtree) continuosly traverse to the left in the right subtree
            TreeNode *temp=n;
            while(temp->left!=NULL){
                temp=temp->left;

            }
            return temp;
        }

        TreeNode* deletNode(TreeNode *n, int v){ //USE AVLtree.root=AVLtree.deletNode(AVLtree.root, 5); OR ELSE IT WONT WORK... AVLtree.deletNode(AVLtree.root, 5); DOESNT WORK
        //MAY BE WATCH VIDEO AGAIN
            
            if(n==NULL){//base case
                return n;
            }
            else if(n->val>v){//if smaller goto left 
                n->left=deletNode(n->left,v);
            }

            else if(n->val<v){//if bigger goto right
                n->right=deletNode(n->right,v); 
            }

            else{//when the node is found(n->val==v)

                if(n->left==NULL){///if node does not have a left child link the right child(may not have a right child thererfore linked to null) to the parent node. 
                    TreeNode *temp=n->right; //may be a node or may be null
                    delete n;//delete the current node
                    return temp;//return the right child node or null to be assigned 
                }
                else if(n->right==NULL){////if node does have a left but does not have a right child then link the left child(may not have a left child therfore be linked to null) to the parent node.
                    TreeNode *temp=n->left; //may be a node or may be null
                    delete n;//delete the current node
                    return temp;//return the left child node or null to be assigned 
                }
                else{//when the node has 2 children- approach used here is to replace it with the smallest node of its right subtree
                    TreeNode *temp=minValueNode(n->right);// right node is passed to select the right subtree of n
                    n->val=temp->val;//here the value is simply copied to the node. Not delted like before.
                    n->right=deletNode(n->right,temp->val);// now delete the node present in the right subtree
                }
            }
  
            //to delete a node with 2 children. need to find a node to replace it.
            // can use two methods to find the replacement. find the largesgt node in the left subtree nMax or smallest node in the right subree nMin
            //then copy that value to the current node and delete the nMin or nMax node using the normal way(they may not always be leaf nodes)

// NODE IS NOW DELETED- LETS DO THE ROTATIONS is required

            int bf=getBalanceFactor(n);// calculates the bf of all associated nodes when deleted in recursion 


            if((bf==2)&& getBalanceFactor(n->left)>=0) //for LL imbalance - when deleted from right subtree bf=2       
            {                                                       //                    
                return rightRotate(n);                  //            
            }

            else if((bf==2)&& getBalanceFactor(n->left)==-1) //for LR imbalance  - when deleted from right subtree bf=2                     
            {      
                n->left= leftRotate(n->left); //left rotate   //       
                return rightRotate(n);//right rotate                                        
            }

            else if((bf==-2)&& getBalanceFactor(n->right)<=0)//for RR imbalance- when deleted from left subtree bf=-2    
            {                                                                  //             
                return leftRotate(n);//                                                               
            } 
            else if((bf==-2)&& getBalanceFactor(n->right)==1) //for RL imbalance- when deleted from left subtree bf=-2                        
            {      
                n->right= rightRotate(n->right); //right rotate   //                                        
                return leftRotate(n);//  left rotate                                                               
            }//no else here

         return n;
        }
           
             
       
       
        
        


        void print2D(TreeNode * r, int space) { //r is the node from which to start(= AVLtree.root). space is the spacing
            if (r == NULL) // Base case  1
                 {   
                    return;
                 }
            space += SPACE; // Increase distance between levels   2
            print2D(r -> right, space); // Process right child first 3 
            std::cout << std::endl;
            for (int i = SPACE; i < space; i++) // 5 
            std::cout << " "; // 5.1  
            std::cout << r->val << "\n"; // 6
            print2D(r -> left, space); // Process left child  7
        }
        void printPreorder(TreeNode *r){ //pre order traversal. node left and right
            if(r==NULL){ //stop the recursion. -at child nodes or when empty
                return;
            }
            std::cout<<r->val<<" ";//print the current node
            printPreorder(r->left);// first do the left
            printPreorder(r->right);//then do  the right

        }

        void printInorder(TreeNode *r){ //Inorder traversal. left,node and right
            if(r==NULL){ //stop the recursion. -at child nodes or when empty
                return;
            }
            
            printInorder(r->left);// first go to the end of the left
            std::cout<<r->val<<" ";//print the current node
            printInorder(r->right);//then do  the right

        }

        void printPostorder(TreeNode *r){ //Postorder traversal. left, right and node
            if(r==NULL){ //stop the recursion. -at child nodes or when empty
                return;
            }
            
            printPostorder(r->left);// first go to the end of the left
            printPostorder(r->right);//then do  the right
            std::cout<<r->val<<" ";//print the current node

        }

        TreeNode* iterativeSearch(int v){//returns the address to the node with the value. if not found returns null
            if(root==NULL){
                return root; //returns null if empty
            }
            else{
                TreeNode *temp=root; //traverse staring from the root
                while(temp!=NULL){
                    if(v==temp->val){//if found return the node
                        return temp;//stop and return 
                    }
                    else if(v<temp->val){//if smaller than the current node, goto the left child
                        temp=temp->left;
                    }
                    else{ //if larger than the current node, goto the right child
                        temp=temp->right;
                    }
                }
                return NULL; //return null if not found-if the while loop exhausts
            }
        }

        TreeNode* recursiveSearch(TreeNode *n, int v){//returns the address to the node with the value. if not found returns null
            if(n==NULL|| n->val==v){// if found returns address or else returns null
                return n; 
            }

            else if (n->val>v){//if smaller check left 
                return recursiveSearch(n->left,  v);
                             
            }
            else{
                return recursiveSearch(n->right,  v);//if larger check right 
            }
        }


        ///used in breadth first search-aka level order traversal
        void printGivenLevel(TreeNode *n, int level){// prints the given level of the n node. like 5th level from the root node 
            

            if(n==NULL){
                return; //dont print anything
            }
            else if(level==0){ //prints when level variable becomes zero
                std::cout<<n->val<<" ";
            }
            else{
                
                printGivenLevel(n->left, level-1);//print from left to right
                printGivenLevel(n->right, level-1);//level-1 decrements level till ==0 and prints
            }

        }


        void printLevelOrderBSF(TreeNode *n){ //prints in level order or breath first search
            int h= heightRecursively(n);//stores thr number of levels
            for(int i=0;i<=h;i++){ //staeting from 0th level to the h-th level
                printGivenLevel(n,i);// function prints the ith level of the n node. like 5th level of the root node
            }
        }


};

int main(){

    
    TreeNode *TN1= new TreeNode;  //if we create TreeNode TN1; it doesnt have global scope. if a do while loop is used to create objects over and over
    //then itll be destoryed. but when created as new using pointers then it stays in the heap in global scope till deleted.

    ///since we arent using a do while loop just TreeNode TN1 will also work
    TN1->val=6;
    TreeNode *TN2= new TreeNode{3};
    //TN2->val=2;
    TreeNode *TN3= new TreeNode;
    TN3->val=7;
    TreeNode TN4(2);// not created as a pointer in the heap. Its in the stack. if its creted over and over in a do while loop. it will get destroyed after it leaves scope in each iteration
    TreeNode *TN5;//creating a pointer in the stack(NOT heap)
    TreeNode TN55(5);
    TN5=&TN55;

   
   
    
    
    AVL AVLtree;
    AVLtree.root=AVLtree.insertNodeRecursively(AVLtree.root,TN1);
    AVLtree.root=AVLtree.insertNodeRecursively(AVLtree.root,TN2);
    AVLtree.root=AVLtree.insertNodeRecursively(AVLtree.root,TN3);
    AVLtree.root=AVLtree.insertNodeRecursively(AVLtree.root,&TN4);// address of the TN4 as its not a pointer

    AVLtree.insertNodeRecursively(AVLtree.root,TN5);//recursively add

    AVLtree.print2D(AVLtree.root,SPACE);

    int k=8;
     do{
        TreeNode *new_node= new TreeNode;// new pointer created in the heap(not stack) has globalm scope and wont be destroyed in every iteration  unless deleted 
        new_node->val=k;
        AVLtree.root=AVLtree.insertNodeRecursively(AVLtree.root,new_node);
        k++;
    }while(k<12);




    AVLtree.print2D(AVLtree.root,SPACE);

    std::cout<<std::endl;
    std::cout<<"printPreorder"<<std::endl;

    AVLtree.printPreorder(AVLtree.root);

    std::cout<<std::endl;
    std::cout<<"printInorder"<<std::endl;
    AVLtree.printInorder(AVLtree.root);

    std::cout<<std::endl;
    std::cout<<"printPostorder"<<std::endl;
    AVLtree.printPostorder(AVLtree.root);

    std::cout<<std::endl;
    std::cout<<"print BFS aka Level order traversal"<<std::endl;
    AVLtree.printLevelOrderBSF(AVLtree.root);
    std::cout<<std::endl;



    TreeNode *iterative_search_node=AVLtree.iterativeSearch(2);
    if( iterative_search_node==NULL){
        std::cout<<"not found"<<std::endl;

    }
    else{
        std::cout<<"Node found with value "<<iterative_search_node->val<<std::endl;
    }

    
    TreeNode *recursive_search_node=AVLtree.recursiveSearch(AVLtree.root,2);
    if( recursive_search_node==NULL){
        std::cout<<"not found"<<std::endl;

    }
    else{
        std::cout<<"Node found with value "<<recursive_search_node->val<<std::endl;
    }
    std::cout<<"Tree height/deapth "<<AVLtree.heightRecursively(AVLtree.root)<<std::endl;

//deleting a node- deleteNode returns the root node
    TreeNode *toDelete= new TreeNode;
    toDelete= AVLtree.iterativeSearch(2);
    if( toDelete==NULL){
        std::cout<<"not found"<<std::endl;

    }
    else{
        std::cout<<"Node available: "<<toDelete->val<<std::endl;
        AVLtree.root=AVLtree.deletNode(AVLtree.root, 2);//returns the pointer to the root node
        std::cout<<"Node deleted "<<std::endl;
    }

    AVLtree.print2D(AVLtree.root,SPACE);
    AVLtree.root=AVLtree.deletNode(AVLtree.root, 5); //Use AVLtree.root= ro else wont work
     AVLtree.print2D(AVLtree.root,SPACE);

    



    return 0;
}