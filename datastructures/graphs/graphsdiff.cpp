#include<iostream>
#include<conio.h>
#include<vector>
#include<list>
#include<queue>
#include<string>
#include<iterator>
#include<stack>
//graph is non linear data structure with vertices-nodes and edges
//can have mutiple paths btween two nodes, no root node, can have loops, network model
//directed graph- edges have directions
//undirected graphs- no directionsof the edge- bidirecionla edges
//weighted graphs- edges have weights

//IMPLEMENTATION METHODS

//1. ADJACENCY MATRIX- square matrix with 1 if theres a direct edge between the nodes
//in undirected graphs its symmetric diagonally
//in weighted graphs instead of 1 add weights

//time complexity using adjacency matrix 
//find node -o(1) if using a hash table or o(n)
//find all adjacent nodes- o(n)- traverse the row for non zero values. first find the node using hash table with 0(1) 
//find if two nodes are connected- o(1) direct address. use hash table ton findthe two nodes or else its o(n) for traversing

//space complexity of adjacency matrix is o(n^2)- not great for large node graphs. used for dense graphs with lots of connections but smaller nummber of nodes


//2. ADJACENCY LIST- an ARRAY of LISTS. size of the array is equal to number of vertices
//rows represent the nodes. elementss in the row represents the indexes of the nodes adjacent to it
//lists can be different sizes. so space compelexity is o(edges). memeory saved
//good for higher nnumber of nodes but smaller number of edges. if edges high will become similae to adjacency matrix

//find all adjacent nodes- o(n)- traverse the row . 
//find if two nodes are connected- o(n). have to trverse the row. If its sorted then use binary search then logn.  in adjaceny matrix is 0(1)
//adding new edges in adjacency matrix requries to make a new array. so we use linked lists


//here virtices are numbered starting from 0. so adjacency list vector is n sized
//here space complexoity is o(N)
//time complexity is 0(no of nodes) +o(2*no of edges); 
//as all nodes will be added once. and in an undirected graph all nodes have both way edges so 2* numberr of edges


std::vector<int> BFS( std::vector<std::list<int>> adj, int V){//level order
//here space complexoity is o(N)
//time complexity is 0(no of nodes) +o(2*no of edges); 
//as all nodes will be added once. and in an undirected graph all nodes have both way edges so 
    std::queue<int> bfsQueue; //queue to for bfs
    std::vector<int> visitiedVertices={0,0,0,0,0,0,0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> bfsTraversed;
    bfsQueue.push(V);//push the starting vertice to queue
    visitiedVertices[V]=1;//mark the starting vertice as visitied
    while(bfsQueue.empty()!=true){
        
        int ver=bfsQueue.front();
        bfsQueue.pop();
        bfsTraversed.push_back(ver);
        std::list<int> neigbours=adj[ver];//grt the neighbours list of the selected vertex

        for(auto itr=adj[ver].begin();itr!=adj[ver].end();itr++){//go through all negbours of the selected vertex
                if(visitiedVertices.at(*itr)==0){//go through visited vertices to see if already visited
                    bfsQueue.push(*itr);//push to queue
                    visitiedVertices[*itr]=1; //mark as visited      
                }                
            }
    }
    return bfsTraversed;


    }


    std::vector<int> DFSwithStack( std::vector<std::list<int>> adj, int V){//using stack

    //here space complexoity is o(N)
    //time complexity is 0(no of nodes) +o(2*no of edges); 
    //as all nodes will be added once. and in an undirected graph all nodes have both way edges so 
    std::stack<int> dfsStack; //stack to for dfs
    std::vector<int> visitiedVertices={0,0,0,0,0,0,0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> dfsTraversed;
    dfsStack.push(V);//push the starting vertice to stack
    visitiedVertices[V]=1;//mark the starting vertice as visitied
    while(dfsStack.empty()!=true){
        
        int ver=dfsStack.top();
        dfsTraversed.push_back(ver);
        dfsStack.pop();//pop the top
        std::list<int> neigbours=adj[ver];//get the neighbours list of the selected vertex
//HAVENT USED NEIGBOURS HERE. BUT ADJ[VER] ISSOKAY
        for(auto itr=adj[ver].begin();itr!=adj[ver].end();itr++){//go through all negbours of the selected vertex
                if(visitiedVertices.at(*itr)==0){//go through visited vertices to see if already visited
                    dfsStack.push(*itr);//push to stack
                    visitiedVertices[*itr]=1; //mark as visited      
                }                
            }
    }
    return dfsTraversed;


    }

    void HelperDFSRecursive( std::vector<std::list<int>> adj, int V, std::vector<int>& visitiedVertices, std::vector<int>& dfsTraversed){//using  - helper function
        visitiedVertices[V]=1;//mark the  vertice as visitied
        dfsTraversed.push_back(V);//FIRST add to dfs traverssed array
        std::list<int> neigbours=adj[V];//get the neighbours list of the selected vertex
//HAVENT USED NEIGBOURS HERE. BUT ADJ[VER] ISSOKAY
        for(auto itr=adj[V].begin();itr!=adj[V].end();itr++){//go through all negbours of the selected vertex
                if(visitiedVertices.at(*itr)==0){//go through visited vertices to see if already visited
                    HelperDFSRecursive(adj,*itr,visitiedVertices,dfsTraversed);  
                }                
            }
       }

std::vector<int> DFSwithRecursion( std::vector<std::list<int>> adj, int V){//using recursion- setting up all here
    std::vector<int> visitiedVertices={0,0,0,0,0,0,0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> dfsTraversed;

     HelperDFSRecursive(adj,V,visitiedVertices,dfsTraversed);   
       
    
    return dfsTraversed;

    //here space complexoity is o(N)
//time complexity is 0(no of nodes) +o(2*no of edges); 
//as all nodes will be added once. and in an undirected graph all nodes have both way edges so 

    }
bool detectCyclesWithBFS(std::vector<std::list<int>> adj, int V){// V is the node suspected to be on the cycle to check
       //o(v+2E)
        //use BFS - queue to find out abt cycles. the queue will have pairs <node,source node>
        //if there are negbours who were visited BUT IS NOT THE SOURCE NODE. THAT MEANS ITS A CYCLE.
  //starting node sourceis given as -1. queue staris {V,-1}
   //             1  
  //      0               3
   //             2
 //  1{2,4}
 //  2{1,3}
 //  3{2,4}
 //  4{1,3}

 //IF THE GRAPH ISNT CONNECTED WE CAN RUN THIS FOR THE UNVISITED NODES AND CHECK FOR CYCLES
 
    std::queue<std::pair<int,int>> bfsQueue;//stores the node and the source node
    std::vector<int> visitiedVertices={0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> bfsTraversed;//NOT REALLY NEEDED
    
    bfsQueue.push({V,-1}); //starting node, sourcce node =-1
    visitiedVertices[V]=1;//mark the starting vertice as visitied
    while(bfsQueue.empty()!=true){
        
        int ver=bfsQueue.front().first;
        int source=bfsQueue.front().second;//source node
        bfsTraversed.push_back(ver);
        bfsQueue.pop();
        std::list<int> neigbours=adj[ver];//grt the neighbours list of the selected vertex

        for(auto itr=adj[ver].begin();itr!=adj[ver].end();itr++){//go through all negbours of the selected vertex
                if(visitiedVertices.at(*itr)==0){//go through visited vertices to see if already visited
                    bfsQueue.push({*itr,ver});//push to queue with the parent of this(ver is the parent here)
                    visitiedVertices[*itr]=1; //mark as visited      
                } 
                else if(visitiedVertices.at(*itr)!=0 && *itr!=source){// if it is visited already but it isnt a sourcce node .- means theres a cycle
                        return true; // return true because theres  cycle
                }               
            }
    }
    return false;// when exhasuted
}

bool detectCyclesWithDFS(std::vector<std::list<int>> adj, int V){// V is the node suspected to be on the cycle to check
       //o(v+2E)
        //use DFS - STACK to find out abt cycles. the stack will have pairs <node,source node>
        //if there are negbours who were visited BUT IS NOT THE SOURCE NODE. THAT MEANS ITS A CYCLE.
  //starting node sourceis given as -1. stack starts {V,-1}
   //             1  
  //      0               3
   //             2
 //  1{2,4}
 //  2{1,3}
 //  3{2,4}
 //  4{1,3}

 //IF THE GRAPH ISNT CONNECTED WE CAN RUN THIS FOR THE UNVISITED NODES AND CHECK FOR CYCLES
 
    std::stack<std::pair<int,int>> dfsStack;//stores the node and the source node
    std::vector<int> visitiedVertices={0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> bfsTraversed;//NOT REALLY NEEDED

    dfsStack.push({V,-1}); //starting node, sourcce node =-1
    visitiedVertices[V]=1;//mark the starting vertice as visitied
    while(dfsStack.empty()!=true){
        
        int ver=dfsStack.top().first;
        int source=dfsStack.top().second;//source node
        bfsTraversed.push_back(ver);
        dfsStack.pop();
        std::list<int> neigbours=adj[ver];//get the neighbours list of the selected vertex

        for(auto itr=adj[ver].begin();itr!=adj[ver].end();itr++){//go through all negbours of the selected vertex
                if(visitiedVertices.at(*itr)==0){//go through visited vertices to see if already visited
                    dfsStack.push({*itr,ver});//push to stack with the parent of this(ver is the parent here)
                    visitiedVertices[*itr]=1; //mark as visited      
                } 
                else if(visitiedVertices.at(*itr)!=0 && *itr!=source){// if the neigbour is visited already but it isnt a sourcce node .- means theres a cycle. it was visited in another way
                        return true; // return true because theres  cycle
                }               
            }
    }
    return false;// when exhasuted
}

   bool helperDFSRecursiveCyclic( int node, int source,  std::vector<std::list<int>> adj, std::vector<int>& visitiedVertices, std::vector<int>& dfsTraversed){//using  - helper function
        visitiedVertices[node]=1;//mark the  vertice as visitied
        dfsTraversed.push_back(node);//FIRST add to dfs traverssed array
        std::list<int> neigbours=adj[node];//get the neighbours list of the selected vertex
//HAVENT USED NEIGBOURS HERE. BUT ADJ[VER] ISSOKAY
        for(auto itr=adj[node].begin();itr!=adj[node].end();itr++){//go through all negbours of the selected vertex
                if(visitiedVertices.at(*itr)==0){//go through visited vertices to see if already visited
                    if(helperDFSRecursiveCyclic(*itr,node,adj,visitiedVertices,dfsTraversed)==true){// RECURSIVE CALL INSIDE THE IF STATEMENT
                        return true; //a cascade of trues. if just one returns true all will return true
                    }
                }  
                else if(visitiedVertices.at(*itr)!=0 && *itr!=source){// if this returns true. the above helperrecrucivecylic will return true. leading to cascade of trues
                        return true;
                }
                               
            }
        return false; // when exhausted
       }

bool detectCyclesswithrecursiveDFS( std::vector<std::list<int>> adj, int node){//using recursion- setting up all here

//DO IT FOR ALL UNVISITED NODES- USE A LOOP IF THERES DISCONNCETED COMPONENTS
    std::vector<int> visitiedVertices={0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> dfsTraversed;//NOT NEEDED

    return helperDFSRecursiveCyclic(node,-1,adj,visitiedVertices,dfsTraversed);   //parent node initially is -1

}

//#######DIRECTED GRAPH CYCLE DTECTION WITH RECURSIVE DFS

bool directedHelperDFSRecursiveCyclic( int node,  std::vector<std::list<int>> adj, std::vector<int>& visitiedVertices,std::vector<int>& PathvisitiedVertices, std::vector<int>& dfsTraversed){//using  - helper function
        visitiedVertices[node]=1;//mark the  vertice as visitied
        PathvisitiedVertices[node]=1;//mark the  path visited vertice as visitied
        dfsTraversed.push_back(node);//FIRST add to dfs traverssed array
        std::list<int> neigbours=adj[node];//get the neighbours list of the selected vertex
//HAVENT USED NEIGBOURS HERE. BUT ADJ[VER] ISSOKAY
        for(auto itr=adj[node].begin();itr!=adj[node].end();itr++){//go through all negbours of the selected vertex
                if(visitiedVertices.at(*itr)==0){//go through visited vertices to see if already visited
                    if(directedHelperDFSRecursiveCyclic(*itr,adj,visitiedVertices,PathvisitiedVertices,dfsTraversed)==true){// RECURSIVE CALL INSIDE THE IF STATEMENT
                        return true; //a cascade of trues. if just one returns true all will return true
                    } 
                }
                else if(visitiedVertices.at(*itr)!=0 && PathvisitiedVertices.at(*itr)!=0 ){// if both past visited and visited BOTH>>>>this returns true. the above helperrecrucivecylic will return true. leading to cascade of trues
                        return true;
                }
                               
            }
        PathvisitiedVertices[node]=0;//mark the  path visited vertice as not visited 

        return false; // when exhausted
       }

bool directedDetectCyclesswithrecursiveDFS( std::vector<std::list<int>> adj, int node){//using recursion- setting up all here

//DO IT FOR ALL UNVISITED NODES- USE A LOOP IF THERES DISCONNCETED COMPONENTS
    std::vector<int> visitiedVertices={0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> PathvisitiedVertices={0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
   //path visited is needed to check because it should be on the same directed path
   //you can just use visitedVertices and mark as 2 if path visited
    std::vector<int> dfsTraversed;//NOT NEEDED

    return directedHelperDFSRecursiveCyclic(node,adj,visitiedVertices,PathvisitiedVertices,dfsTraversed);   //parent node initially is -1

}




//#########DIRECTED GRAPH CYCLE DETECTION WITH BFS (using khans algorithm)

//just do the toposort on this. but toposorts are for DAG. no Cycles can be present
//if a toposort created is less than the number of elements it means theres a cycle
//if the toposort has exactly the number of nodes then therres no cycle
bool directedDetectCyclesswithBFSkhans( std::vector<std::list<int>> adj, int node, int N){//
    std::vector<int> visitiedVertices={0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> inDegree={0,0,0,0};//number of incoming edges to the nodes
    std::vector<int> toposort;//NO NEED -stores the topological sort- linear ordering for returning
    int count=0;//stores the number of nodes in the toposort.(if==N at the end , no cycles)
    std::queue<int> bfsQueue;
//CREATE THE INDEGREE VECTOR 
     for (int i = 0; i < adj.size(); i++)//goto each node
    {
        for(auto itr=adj.at(i).begin();itr!=adj.at(i).end();itr++){//traverse the edge list
            inDegree[*itr]++;//increment the indegree each time a edge towards it is found
        }
        
    }
    for (int i = 0; i < inDegree.size(); i++)
    {
        if(inDegree.at(i)==0)// add all the nodes with indegree to queue
        {
            bfsQueue.push(i);//add to the queue
        }  
    }
     while(!bfsQueue.empty()){// 
            int node =bfsQueue.front();// choose the fornt node and then goto all the neigbours and reduce their indegree
            toposort.push_back(bfsQueue.front());//NO NEEDD -add to topo sort vector as soon as poppped
            bfsQueue.pop();
            count++;//increment the number of nodes in the toposort
            for(auto itr=adj.at(node).begin();itr!=adj.at(node).end();itr++){// reduce indegree of neighbours
                inDegree[*itr]--; //decrement the indegree as if the node is now deleted
                if(inDegree[*itr]==0){// push to the queue alll that reach an indegree of 0
                    bfsQueue.push(*itr);
                } 
            }
            
        }
    return count==N?false:true;// if the toposort has N number of nodes then no cycles. if less than N then there must have ben a cycle
}



//TOPOLOGICAL SORT. FOR DIRECTED ACYCLIC GRAPHS. LINEARLY ORDERED- USING modified DFS HERE
//IF NO FURTHER DFS CALLS PUT TO STACK-no popping like in normal dfs
//at the end empty the stack 

void helperDFSforTopoSort(int node, std::vector<std::list<int>> adj, std::vector<int>& visitiedVertices, std::stack<int>& dfsStack ){
    visitiedVertices[node]=1;// mark as visited
    for(auto itr=adj.at(node).begin();itr!=adj.at(node).end();itr++){
        if(visitiedVertices.at(*itr)==0){//if unvisited call dfs again
            helperDFSforTopoSort(*itr,adj, visitiedVertices,dfsStack);// call dfs
        }
    }
    dfsStack.push(node); //ADD TO THE STACK when no more dfs calls can be made
}

std::vector<int> topoSortDFS( std::vector<std::list<int>> adj, int node){
    std::vector<int> visitiedVertices={0,0,0,0,0,0,0};//make visited 1 and not visited 0. can even use a bool vector
    std::vector<int> toposort;//stores the topological sort- linear ordering for returning
    std::stack<int> dfsStack;

    for (int i = 0; i < visitiedVertices.size(); i++)
    {
        if(visitiedVertices.at(i)==0)// if unvisited then traverse. DAG will exhaust prematurely without fully traversing. so need to force it to visit all
        {
            helperDFSforTopoSort(i,adj,visitiedVertices,dfsStack);

        }  
    }
     while(!dfsStack.empty()){// empty the stack and add to the vector and return the vector
            toposort.push_back(dfsStack.top());
            dfsStack.pop();
        }
    return toposort;
}


//KAHN'S ALGORITHM - TOPOLOGICAL SORT. FOR DIRECTED ACYCLIC GRAPHS. LINEARLY ORDERED- USING BFS HERE
//QUeue data structure is used- modifiedd form of BFS
//use a vector called indegree- number of incoming edges to a vertice.
//add the ones with 0(atleast one will be there) to the start 
//then choose the one on the queue front and pop it(then add to toposort). and reduce the indegree of the connected vertices(like if edges are removed)
//do it till some reach 0 and add to queue as soon as the ones that reach 0
//NO NEED OF VISITED VERTICES array
std::vector<int> topoSortBFS( std::vector<std::list<int>> adj, int node){
    std::vector<int> inDegree={0,0,0,0,0,0,0};//number of incoming edges to the nodes
    std::vector<int> toposort;//stores the topological sort- linear ordering for returning
    std::queue<int> bfsQueue;
//CREATE THE INDEGREE VECTOR 
     for (int i = 0; i < adj.size(); i++)//goto each node
    {
        for(auto itr=adj.at(i).begin();itr!=adj.at(i).end();itr++){//traverse the edge list
            inDegree[*itr]++;//increment the indegree each time a edge towards it is found
        }
        
    }
    for (int i = 0; i < inDegree.size(); i++)
    {
        if(inDegree.at(i)==0)// add all the nodes with indegree0 to queue
        {
            bfsQueue.push(i);//add to the queue
        }  
    }
     while(!bfsQueue.empty()){// 
            int node =bfsQueue.front();// choose the fornt node and then goto all the neigbours and reduce their indegree
            toposort.push_back(bfsQueue.front());//add to topo sort vector as soon as poppped
            bfsQueue.pop();
            for(auto itr=adj.at(node).begin();itr!=adj.at(node).end();itr++){// reduce indegree of neighbours
                inDegree[*itr]--; //decrement the indegree as if the node is now deleted
                if(inDegree[*itr]==0){// push to the queue alll that reach an indegree of 0
                    bfsQueue.push(*itr);
                } 
            }
            
        }
    return toposort;
}



/*Dikstras algorithm - can use  - priority queue(minimum heap) , fibonacci heapO(E + VlogV), binary heap , set(set is not faster- says chatgpt)
Single source shortest path algorithm to all other nodes
Priority queue(minimum heap) will store the cummulative distance and the node as pairs
Shorter distance will be at the front. SINCE WE ADD PAIRS. TO OREDER IT WILL FIRST LOOK AT THE FIRST, IF ITSTHE SAME ITLL THEN LOOK AT THE SECOND
Distance array with INT_MAX is also needed. NO VISITED ARRAY so multiple visits happen to each node
Every time a bettter distance is found add it to the distaance array and priority queue


Wont work for negative weights. use bellman ford for negative weights
to get the distance between each pair,( not single source) use floyd warshall
Use A* to find least cost path betweeen two verrtices- with heuristic fucnntion like euclidian or mmanhattan distance(if weights are actually distaance. never overestimate though)

// SYNTAX FOR PRIORITY QUEUE- #import <queue>  logn time comlexity
MAX HEAP   std::priority_queue<int> pq;
MIN heap   std::priority_queue< int, std::vector<int>, STD::greater<int>> pq;

*/

std::vector<int> dijkastrasPriorityQueue(std::vector<std::list<std::pair<int,int>>> adj, int source, int num){// time complexity is ElogV

    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> priorityQueue;// ADD STD::GREATER
    std::vector<int> distance(num);// create vector of num size and initialize all to INT_MAX
    for(int i=0; i<distance.size();i++){
        distance[i]=INT_MAX;
    }
    distance[source]=0; //initialize distance from source to source is 0.
    priorityQueue.push({0,source}); //push the initial source node to the priority queue
    //PAIR CONTAINS THE DISTACNE AS FIRST AND THE NODE TO WHICH IT ARRIVED AT AS SECOND
    while(!priorityQueue.empty()){//untill priority queue is empty
        std::pair<int,int> top=priorityQueue.top();// take the now top of the priority queue. PQ top always changes accordingly
        int cuml_weight=top.first;
        int node= top.second;
        priorityQueue.pop();
        std::list<std::pair<int,int>>::iterator itr;
        for(itr=adj.at(node).begin(); itr!=adj.at(node).end();itr++){// this list will also have pairs. but first is the node and second is the weight
            std::pair<int,int> pr=*itr;
            int neighNode=pr.first; //neigbouring node
            int Edgeweight=pr.second;// weight to goto that node
            int total_weight = Edgeweight+cuml_weight; //total weight if arrived using this edge
            if(distance[neighNode]>total_weight){// if the distance in the distance vector is larger than this. this path is better so add this
                distance[neighNode]=total_weight;
                priorityQueue.push({total_weight,neighNode}); //IF BETTER DISTACANCE IS FOUND ADD TO PRIOIRTY QUEUE
            }
            
        }

        
    }
    return distance;
}

/* 
PRIMS ALGORITHM- for UNDIRECTED graphs .GREEDY. alternative is kruskals algorothm
    1. Find the minimum edge and add to the graph
    2. find the minimum edge connectd to the two vertices of the minimum edge and add to the graph
    3. now 3 vetrtices are joined in the new mst. now conisder the minnimum of the edges attached to the 3 verrticess and add to the graph
    4. continue this and tick off the nodes -goal is to make sure all nodes are traversed
    4. result will be the minnimum spanning tree

    O(N^2) without min heap- use for dense graphs
    0(ElogV) with  MIN HEAP- use for sparse graph 

    1.Priority queue that stores the weight, node, parent  and a visited array is needed, sum stores weight of the mst
    2. start 0, 0, -1  for the first node. mark as visited add to the priority queue but dont add to the mst 
    3. add all unvisited neigboours to the priority queue but DONT mark them as visited
    4. take the top of the priority queue and add to mst as (parent, node), update sum and mark as visited
    5. if the priortiy queue node is already visited donot add to mst. just ignore

 */
    std::vector<std::pair<int,int>> primsMinimumSpanningTree(std::vector<std::list<std::pair<int,int>>> adj, int num){
        std::vector<std::pair<int,int>> mst;//stores the minimumm spanning tree
        std::vector<int> visitedArray(num,0); // num sized visited array . (NUM,0) will initialize all to zero
        int sum=0; //total weight of the mst
        std::priority_queue<std::pair<int,std::pair<int,int>>,std::vector<std::pair<int,std::pair<int,int>>>,std::greater<std::pair<int,std::pair<int,int>>>> priorityQueue;
// HERE PRIOIRTY QUEUE HAS THE WEIGHT, {NODE, PARENT} SO ITS FORMAT IS PAIR<INT, PAIR<INT,INT>>
        priorityQueue.push({0,{0,-1}});// push the staring node 0. weight is 0, parent is -1. so 0, {0,-1}
        while(!priorityQueue.empty()){
            std::pair<int,std::pair<int,int>> pr=priorityQueue.top();
            priorityQueue.pop();// remove the top of the pq
            int node=pr.second.first;
            int parent=pr.second.second;
            int weight=pr.first;
            if(visitedArray[node]==0){//if the top of the pq is unvisited
                visitedArray[node]=1; //mark as visited ONLY HERE. 
                sum+=weight;
                mst.push_back({parent,node});//ADD to mst array push PARENT, NODE
               std::list<std::pair<int,int>>::iterator itr;//AUTO DID NOT WORK HERE
                for(itr= adj.at(node).begin();itr!=adj.at(node).end();itr++){//goto the adecent nodes of the top of the pq and add to the pq if not visited
                    int neighNode=itr->first;//can declare a pair ad then use .first or iust use ->first without *
                    int edgeWeight=itr->second;//edge weight
                    if(visitedArray[neighNode]==0){//if not previously visited....NO MARKING AS VISITED HERE, ONLY MARK AS VISITED IF ADDED TO MST
                        priorityQueue.push({edgeWeight,{neighNode,node}}); //push the adacent node and its parent with is the node
                    }

                }
            }
        }

        std::cout<<"sum of mst:"<<sum<<std::endl;
        return mst;


        //HERE THE -1,0 IS ALSO ADDED TO THE MST, BUT THINK OF A WAY TO GET RID OF IT
    }

int main(){

    std::vector<std::list<int>> adj; //adjacency list. vector of lists
    adj={{1},{2,6},{1,3,4},{2},{2,5},{4,8},{1,7,9},{6,8},{5,7},{6}};
    //     0   1     2      3     4    5     6       7     8     9    
    //std::vector<int> vertices={0,1,2,3,4,5,6,7,8,9};

    std::vector<int> bfsresult= BFS(adj,0);
    for(int i=0;i<bfsresult.size();i++){
        std::cout<<bfsresult.at(i)<<"->";
    }
        std::cout<<std::endl;

    std::vector<int> dfsresultwithStack= DFSwithStack(adj,0);
    for(int i=0;i<dfsresultwithStack.size();i++){
        std::cout<<dfsresultwithStack.at(i)<<"->";
    }

        std::cout<<std::endl;

    std::vector<int> dfsresultwithRecursion= DFSwithRecursion(adj,0);
    for(int i=0;i<dfsresultwithRecursion.size();i++){
        std::cout<<dfsresultwithRecursion.at(i)<<"->";
    }
     std::cout<<std::endl;

    std::vector<std::list<int>> Cyclic; //adjacency list. vector of lists
    Cyclic={{1,2},{3,0},{3,0},{1,2}};
    std::cout<<detectCyclesWithBFS(Cyclic, 0)<<std::endl;
    std::cout<<detectCyclesWithDFS(Cyclic, 0)<<std::endl;
    std::cout<<detectCyclesswithrecursiveDFS(Cyclic, 0)<<std::endl;

     std::vector<std::list<int>> DirectedCyclic; //adjacency list. vector of lists
    DirectedCyclic={{1},{3},{0},{2}};
    std::cout<<directedDetectCyclesswithrecursiveDFS(DirectedCyclic, 0)<<std::endl;
    std::cout<<directedDetectCyclesswithBFSkhans(DirectedCyclic, 0, DirectedCyclic.size());

std::vector<std::list<int>> topo={{1,2},{2,5},{3},{},{},{3,4},{1,5}};
    std::vector<int> topologicalsortwithDFS= topoSortDFS(topo,0);
    for(int i=0;i<topologicalsortwithDFS.size();i++){
        std::cout<<topologicalsortwithDFS.at(i)<<"->";
    }
     std::cout<<std::endl;

std::vector<int> topologicalsortwithBFS= topoSortBFS(topo,0);
    for(int i=0;i<topologicalsortwithBFS.size();i++){
        std::cout<<topologicalsortwithBFS.at(i)<<"->";
    }
     std::cout<<std::endl;
 std::vector<std::list<std::pair<int,int>>> weightedAdj; //adjacency list. with weights. neigbour node and its edge weight given
 weightedAdj={{{1,1},{2,3}},{{0,1},{2,1}},{ {1,1},{0,3} }  };
std::vector<int> shortestPaths= dijkastrasPriorityQueue(weightedAdj,0, weightedAdj.size());
    for(int i=0;i<shortestPaths.size();i++){
        std::cout<<i<<"->" <<shortestPaths.at(i)<<std::endl;
    }
     std::cout<<std::endl;


     std::vector<std::pair<int,int>> minimumSpanninggTree = primsMinimumSpanningTree(weightedAdj,weightedAdj.size());
     for(auto itr: minimumSpanninggTree){
        std::cout<<itr.first<<" ->"<<itr.second<<std::endl;
     }
     std::cout<<std::endl;
     



    return 0;
}