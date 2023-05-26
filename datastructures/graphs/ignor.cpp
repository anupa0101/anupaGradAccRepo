  bool directedHelperDFSRecursiveCyclic( int node,  std::vector<std::list<int>> adj, std::vector<int>& visitiedVertices,std::vector<int>& PathvisitiedVertices, std::vector<int>& dfsTraversed){//using  - helper function
        visitiedVertices[node]=1;//mark the  vertice as visitied
        PathvisitiedVertices[node]=1;//mark the  path visited vertice as visitied
        dfsTraversed.push_back(node);//FIRST add to dfs traverssed array
        std::list<int> neigbours=adj[node];//get the neighbours list of the selected vertex
//HAVENT USED NEIGBOURS HERE. BUT ADJ[VER] ISSOKAY
        for(auto itr=adj[node].begin();itr!=adj[node].end();itr++){//go through all negbours of the selected vertex
                if(visitiedVertices.at(*itr)==0){//go through visited vertices to see if already visited
                    if(directedhelperDFSRecursiveCyclic(*itr,adj,visitiedVertices,dfsTraversed)==true){// RECURSIVE CALL INSIDE THE IF STATEMENT
                        return true; //a cascade of trues. if just one returns true all will return true
                    }  
                    else if(visitiedVertices.at(*itr)!=0 && PathvisitiedVertices.at(*itr)!=0 ){// if both past visited and visited BOTH>>>>this returns true. the above helperrecrucivecylic will return true. leading to cascade of trues
                            return true;
                    }
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
    std::vector<int> dfsTraversed;//NOT NEEDED

    return directedhelperDFSRecursiveCyclic(node,adj,visitiedVertices,pathvisitiedVertices,dfsTraversed);   //parent node initially is -1

}