#include<iostream>
#include<conio.h>
#define SPACE 10

//when balanced(avg case) for search/access/update, insert/add, delete/remove is all Olog(N)

//when unbalanced(worst case) for search/access/update, insert/add, delete/remove is all O(N)


//bst can do fast insertion and deletion but is not self balancing. So when unbalacnced may cause search to be slow.
//avl trees have slower insertion and deletion as it has to self balance. searching remains fast.

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

class BST{
    public:
        TreeNode *root; 
        BST(){

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

        void InsertNode( TreeNode *n){ 

            if(isTreeEmpty()){ //when the tree is empty add the root node
                root=n;
                std::cout<<"root node added"<<std::endl;
            }

            else{//when tree is not empty
                TreeNode *temp=root;//to start travering the tree starting from root 
            
                while(temp!=NULL) { //loop till leaf nodes(but will break before that)
                        if(n->val==root->val){
                            std::cout<<"Duplicate values not allowed"<<std::endl;
                            break;
                        }
                        else if(n->val<temp->val  &&  temp->left==NULL){ //if the value of the new node is less than the parent node and theres no left child.
                            temp->left=n;//  value inserted to the left
                            std::cout<<"value inserted to the left"<<std::endl;
                            break;
                        }
                        else if(n->val<temp->val){ //if the value of the new node is less than the parent node (but theres is a left child).
                            temp=temp->left; //  traversed to the  left child
                        }
                        else if(n->val>temp->val  &&  temp->right==NULL){ //if the value of the new node is greater than the parent node and theres no right child.
                            temp->right=n;//  value inserted to the right
                            std::cout<<"value inserted to the right"<<std::endl;
                            break;
                        }
                        
                        else { //if(n->val>temp->val)if the value of the new node is greater than the parent node (but theres is a right child).
                            temp=temp->right; //  traversed to the  right child
                        }
                    }
                }
        }

        TreeNode *insertNodeRecursively(TreeNode *current_node, TreeNode *new_node){// here this wont work for the first node(root node)- wont the root
        //because when insertNodeRecursively(Bstree.root, TN1) is called. Bstree.root pointer is passed by value not by reffernce. so use
        //Bstree.root= insertNodeRecursively(Bstree.root, TN1)
        //can use pass by refference of pointers too insertNodeRecursively(TreeNode **current_node, TreeNode *new_node) but how abt this->root???? CHECK
        //insertNodeRecursively(&Bstree.root, TN1) and pass the address to the pointer BUT NEEDS ALOT OF CHANGE I GUESSS- coudlnt do it

            if (current_node==NULL){  //not just for empty node. it also terminates the redursion(sometimes)
                current_node=new_node;
                return current_node;
            }

            if(new_node->val<current_node->val){ //left subtree
                current_node->left=insertNodeRecursively(current_node->left,new_node);
                return current_node;

            }
            else if(new_node->val>current_node->val){//right subtree
                current_node->right=insertNodeRecursively(current_node->right,new_node);
                return current_node;

            }
            else{
                std::cout<<"Duplicates not allowed"<<std::endl;
                return current_node;
            }
        }

        void print2D(TreeNode* r, int space) { //r is the node from which to start(= BStree.root). space is the spacing
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
            if(n==NULL|| n->val==v){//terminate condition if found returns address or else returns null
                return n; 
            }

            else if (n->val>v){//if smaller check left 
                return recursiveSearch(n->left,  v);
                             
            }
            else{
                return recursiveSearch(n->right,  v);//if larger check right 
            }
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

        TreeNode* minValueNode(TreeNode *n){//to get the minimum node of the left subtree(n will be somtn->left to select the left subtree) continuosly traverse to the left in the left subtree
            TreeNode *temp=n;
            while(temp->left!=NULL){
                temp=temp->left;

            }
            return temp;
        }

        TreeNode* deletNode(TreeNode *n, int v){ //finallly returns n back
            
            if(n==NULL){//base case
                return n;
            }
            else if(n->val>v){//if smalller goto left 
                n->left=deletNode(n->left,v);
            }

            else if(n->val<v){//if bigger goto right
                n->right=deletNode(n->right,v); 
            }

            else{//when the node is found(n->val==v)

                if(n->left==NULL){///if node does not have a left child link the right child(may not have a right child thererfore linked to null) to the parent node. 
                    TreeNode *temp=n->right; //may be a node or may be null
                    delete n;//delete the current node- butno memory allocated?
                    return temp;//return the right child node or null to be assigned - wny not return n->right?
                }
                else if(n->right==NULL){////if node does have a left but does not have a right child then link the left chi to the parent node.
                    TreeNode *temp=n->left; //may be a node or may be null
                    delete n;//delete the current node- butno memory allocated?
                    return temp;//return the left child node or null to be assigned 
                }
                else{//when the node has 2 children- approach used here is to replace it with the smallest node of its right subtree
                    TreeNode *temp=minValueNode(n->right);// right node is passed to select the right subtree of n
                    n->val=temp->val;//here the value is simply copied to the node. Not delted like before.
                    n->right=deletNode(n->right,temp->val);// now delete the node present in the right subtree
                }
            }
            return n;     
            //to delete a node with 2 children. need to find a node to replace it.
            // can use two methods to find the replacement. find the largesgt node in the left subtree nMax or smallest node in the right subree nMin
            //then copy that value to the current node and delete the nMin or nMax node using the normal way(they may not always be leaf nodes)
        }

        void InvertBT(TreeNode *n){

            if(n==NULL){
                return;
            }
            InvertBT(n->left);// first move to the bottom then start doing the swaps
            InvertBT(n->right);
            TreeNode *temp= n->left;
            n->left=n->right;
            n->right=temp;

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

   
   
    
    
    BST BStree;


    BStree.root=BStree.insertNodeRecursively(BStree.root,TN1);//recursively add
    BStree.InsertNode(TN2);
    BStree.InsertNode(TN3);
    BStree.InsertNode(&TN4);// address of the TN4 as its not a pointer 


    

    BStree.root=BStree.insertNodeRecursively(BStree.root,TN5);//recursively add
    //use BStree.root=BStree.insertNodeRecursively. it worked without AS WELL but not for the first node. root node wasnt set because current node is 
    //if first node root node is created. then it works 

    BStree.print2D(BStree.root,SPACE);

    int k=8;
     do{
        TreeNode *new_node= new TreeNode;// new pointer created in the heap(not stack) has globalm scope and wont be destroyed in every iteration  unless deleted 
        new_node->val=k;
        BStree.root=BStree.insertNodeRecursively(BStree.root,new_node);
        k++;
    }while(k<12);




    BStree.print2D(BStree.root,SPACE);

    std::cout<<std::endl;
    std::cout<<"printPreorder"<<std::endl;

    BStree.printPreorder(BStree.root);

    std::cout<<std::endl;
    std::cout<<"printInorder"<<std::endl;
    BStree.printInorder(BStree.root);

    std::cout<<std::endl;
    std::cout<<"printPostorder"<<std::endl;
    BStree.printPostorder(BStree.root);

    std::cout<<std::endl;
    std::cout<<"print BFS aka Level order traversal"<<std::endl;
    BStree.printLevelOrderBSF(BStree.root);
    std::cout<<std::endl;



    TreeNode *iterative_search_node=BStree.iterativeSearch(2);
    if( iterative_search_node==NULL){
        std::cout<<"not found"<<std::endl;

    }
    else{
        std::cout<<"Node found with value "<<iterative_search_node->val<<std::endl;
    }

    
    TreeNode *recursive_search_node=BStree.recursiveSearch(BStree.root,2);
    if( recursive_search_node==NULL){
        std::cout<<"not found"<<std::endl;

    }
    else{
        std::cout<<"Node found with value "<<recursive_search_node->val<<std::endl;
    }
    std::cout<<"Tree height/deapth "<<BStree.heightRecursively(BStree.root)<<std::endl;

//deleting a node- deleteNode returns the root node
    TreeNode *toDelete= new TreeNode;
    toDelete= BStree.iterativeSearch(2);
    if( toDelete==NULL){
        std::cout<<"not found"<<std::endl;

    }
    else{
        std::cout<<"Node available: "<<toDelete->val<<std::endl;
        BStree.deletNode(BStree.root, 2);//returns the pointer to the root node
        std::cout<<"Node deleted "<<std::endl;
    }

    BStree.print2D(BStree.root,SPACE);

    std::cout<<"Invert Tree"<<std::endl;

    BStree.InvertBT(BStree.root);
    BStree.print2D(BStree.root,SPACE);


    return 0;
}