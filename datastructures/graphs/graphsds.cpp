#include<iostream>
#include<conio.h>
#include<vector>
#include<list>
#include<queue>
#include<string>
#include<iterator>
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

class Edge{
    public:
        int DestinationVertexID;
        int weight;

        Edge(){

        }
        Edge(int destId, int w){
            DestinationVertexID=destId;
            weight=w;
        }

        void setEdgeValues(int destId, int w){
            DestinationVertexID=destId;
            weight=w;
        }
        void setWeight(int w){
            weight=w;
        }
        int getDestinationVertexId(){
            return DestinationVertexID;
        }
        int getWeight(){

            return weight;
        }

};

class Vertex{
    public:
        int state_id;
        std::string state_name;// here its the name of the city
        std::list<Edge> edgeList; //list of edges to the adjacent vertices- has the destination id and the weight
                                // can use vector here as well

        Vertex(){
            state_id=0;
            state_name="";
        }

        Vertex(int id, std::string sname){
            state_id=id;
            state_name=sname;
        }
        void setStateName(std::string sname){
            state_name=sname;
        }
        void setStateId(int id){
            state_id=id;
        }

        void setEdgeList(){

        }
        std::string getStateName(){
            return state_name;
        }
        int getStateId(){
            return state_id;
        }
        std::list<Edge> getEdgelist(){
            return edgeList;
        }

        void printEdgeList() {
        std::cout << "[";
        //std::list<Edge>::iterator it; can use this instead of using auto
        for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
                std::cout << it -> getDestinationVertexId() << "(" << it -> getWeight() << ") --> ";
            }
        std::cout << "]"<< std::endl;
  }

};

class Graph{
    public:
        std::vector<Vertex> vertices;// vector of vertices- can add and remove vertices

        bool CheckIfVertexExistsById(int id){//checck if vertex exists- vertex id must be unique
            for(int i=0; i<vertices.size();i++){// itertate through all vertices and compare state_id
                if(vertices.at(i).getStateId()==id){
                    return true;
                }
            }
            return false;

        }

         void addVertex(Vertex new_v){

            if(CheckIfVertexExistsById(new_v.getStateId())){
                std::cout<<"Vertex exists"<<std::endl;
            }
            else{
                vertices.push_back(new_v);
                std::cout<<"Vertex added"<<std::endl;   
                
            }
        }       

        Vertex getVertexbyId(int id){
            Vertex temp;
            for(int i=0;i<vertices.size();i++){
                temp=vertices.at(i);
                if (temp.getStateId()==id){
                    return temp;
                }
            }
            return temp;
        }
        bool CheckIfEdgeExistsById(int id1,int id2){//checks if there are any edges between two vertices
            Vertex v=getVertexbyId(id1);
            std::list<Edge> e;
            e=v.getEdgelist();
            std::list<Edge>::iterator it;
            for( it=e.begin();it!=e.end();it++){// iterate through the list to check if the vertex of id2 is there
                if(it->getDestinationVertexId()==id2){
                    return true;
                }
            }
            
            return false;
        }

        void addEdgeById(int id1, int id2, int w){
            if(CheckIfVertexExistsById(id1)&& CheckIfVertexExistsById(id2)){//if both vertices exist
                if(CheckIfEdgeExistsById(id1,id2)){// check is edge already exits

                        std::cout<<"Edge already exists"<<std::endl;  
                }
                else{
                    for(int i=0;i<vertices.size();i++){// graph is undirected- so add edges for both
                        if(vertices.at(i).getStateId()==id1){// from id1 to id2
                            Edge e(id2, w);
                            vertices.at(i).edgeList.push_back(e);//push back
                        }
                        else if(vertices.at(i).getStateId()==id2){//from id2 to id1
                            Edge e(id1,w);
                            vertices.at(i).edgeList.push_back(e);

                        }
                    }
                    std::cout<<"Edge added sucessfully"<<std::endl;
                }
            }
            else{
                std::cout<<"Nodes with these ids do not exist"<<std::endl;
            }
        }

        void UpdateEdgeByID(int id1, int id2, int new_weight){
            if(CheckIfEdgeExistsById(id1,id2)){//if an edge exists between the vertices
                for(int i=0; i<vertices.size();i++){
                        //need to updat the weights in both vertices edeglists
                    if( vertices.at(i).getStateId()==id1)// goto id1 
                    {   ///iterate through the edge list to find the edge to id2.
                        for(auto it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();it++){
                                if(it->getDestinationVertexId()==id2){ //find the edge with destination id2
                                    it->setWeight(new_weight);//update the weight
                                    std::cout<<"Edge updated sucessfully"<<std::endl;
                                    break;
                                }
                        }
                    }
                    else if(vertices.at(i).getStateId()==id2){//goto  id2
                        std::list<Edge>::iterator it;
                        for(it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();i++){
                            if(it->getDestinationVertexId()==id1){//find the edge with destination id1
                                it->setWeight(new_weight); //update the new edge weight
                               std::cout<<"Edge updated sucessfully"<<std::endl;
                                break;
                            }
                        }
                    }
                    
                }
       
            }
            else{
                std::cout<<"Edge not found between the given vertices"<<std::endl;
            }
        }

        void deleteEdgebyId(int id1, int id2){ // goto each vertex find the edge list and delte the edge from both vertices
            if(CheckIfEdgeExistsById(id1,id2)){//check if edge exists 
                for(int i=0;i<vertices.size();i++){//iterate through the vertices
                    if(vertices.at(i).getStateId()==id1){//find id1
                        std::list<Edge>::iterator it;
                        for(it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();i++){
                            if(it->getDestinationVertexId()==id2) // iterate through the edge list and find the edge with destination to id2
                                {
                                    vertices.at(i).edgeList.erase(it); //erase the edge from the edge list using the iterator as index
                                    std::cout<<"Edge deleted"<<std::endl;
                                    break;
                                }
                        }

                    }
                    else if(vertices.at(i).getStateId()==id2){//find id2
                        for(auto it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();i++){
                            if(it->getDestinationVertexId()==id1){// iterate through the edge list and find the edge with destination to id1
                                    vertices.at(i).edgeList.erase(it);
                                    std::cout<<"Edge deleted"<<std::endl;
                                    break;
                            }
                        }
                    }
                }
            }
            else{

                std::cout<<"No such edge exists to delete"<<std::endl;
            }
        }

        void deleteVertexxByid(int id){//first delete the edges from the edgelist in the other vertices, the delete the vertex
// HERE INSTEAD OF GOING TO ALL VERTICES and deleting.  WENT TO THE ONE TO BE DELETED AND THEN TO  EDGE LIST TO FIND THE VERTICES ITS CONNECTED TO. THEN DELETED THEM(function deletes it everywehre). NO NEED TO CHECK ALL VERTICS THAT WAY
            if(CheckIfVertexExistsById(id)){// check if vertex exists
                int v_index=0;
                for(int i=0;i<vertices.size();i++){
                    if(vertices.at(i).getStateId()==id){//goto the vertex
                        v_index=i;//index of the vertex to be delted
                        break;
                    }
                }
                for(auto it=vertices.at(v_index).edgeList.begin();it!=vertices.at(v_index).edgeList.end();it++){
                    int destID= it->getDestinationVertexId();//the id of destination of the edges of the edge list
                    deleteEdgebyId(destID,id);//deleting the edges
                }
                vertices.erase(vertices.begin()+v_index);// add vertices.begin+ v.index becasue erase takes in iterator
                std::cout<<"Vertex deleted"<<std::endl;
            }
            else{

                std::cout<<"No such vertex exists"<<std::endl;
            }
        }
        void updateVertexbyID(int id, std::string name){
            if(CheckIfVertexExistsById(id)){
                for(int i=0;i<vertices.size();i++){
                        if(vertices.at(i).getStateId()==id){//find vertex with the required id
                            vertices.at(i).setStateName(name);//set state name and break
                            std::cout<<"Vertex updated"<<std::endl;
                            break;
                        }
                }
            }
            else{
                std::cout<<"No such vertex"<<std::endl;
            }
        }

        void printAllNeigboursByid(int id){

            if(CheckIfVertexExistsById(id)){
                for(int i=0;i<vertices.size();i++){
                    if(vertices.at(i).getStateId()==id){
                        for(auto it=vertices.at(i).edgeList.begin();it!=vertices.at(i).edgeList.end();it++)
                        {
                        std::cout<<it->getDestinationVertexId()<<"\t";
                        }
                        std::cout<<std::endl;
                        break;
                        
                    }
                }
            }
            else{
                std::cout<<"No such vertx exists"<<std::endl;
            }
        }


        void printGraph() {
            for (int i = 0; i < vertices.size(); i++) {
                Vertex temp;
                temp = vertices.at(i);
                std::cout << temp.getStateName() << " (" << temp.getStateId() << ") --> ";
                temp.printEdgeList();
                }
        }




        std::list<Vertex> BFS(Vertex v1){

            std::vector<Vertex> vistitedVertices;//stores the visited vertices
            std::queue<Vertex> vertexQueue;//queue for bfs
            std::list<Vertex> traversed;//stores the bfs traverssaal order

            vertexQueue.push(v1);//push the starting node on to the queue first
            vistitedVertices.push_back(v1);//push the staring node to the visited

            while(vertexQueue.empty()!=0){//while the queue is not empty
                Vertex frontV= vertexQueue.front();
                vertexQueue.pop();//remove the front vertex
                traversed.push_back(frontV);//add to the bfs traversed list


                std::list<Edge> neighbours=frontV.edgeList;//stores the neigbours of the top vertex
                for(auto itr=neighbours.begin();itr!=neighbours.end();itr++){//go through all the neigbours
                   Vertex neighbourV=getVertexbyId(itr->DestinationVertexID);
                   bool found=false;
                   for(int i=0;i<vistitedVertices.size();i++){//search in visited vertices if v exists. if not push to queue and visited
                       if(vistitedVertices.at(i).state_id==neighbourV.state_id){//cant equate vertices in guesss ,,DOEES == NEED TO BE OVERLOADED that THIS WORK
                            found=true;
                            break;
                        } 
                   }                                   
                 
                 if(found==false){//if not found
                    vertexQueue.push(neighbourV);//add to the queue list if not found in the visited vetices 
                    vistitedVertices.push_back(neighbourV);//push the  to the visited vertices vector

                    }
                }
            
            }
            return traversed;
        }
     
};

int main(){

    Graph g;
    Vertex v1;
    v1.setStateId(1);
    v1.setStateName("Panniptiya");
        Vertex v2;
    v2.setStateId(2);
    v2.setStateName("Mahargama");
        Vertex v3;
    v3.setStateId(3);
    v3.setStateName("Kulliapiriya");
        Vertex *v4= new Vertex;
    v4->setStateId(4); ///using a pointer
    v4->setStateName("Rawatawatta");

    g.addVertex(v1);
    g.addVertex(v2);
    g.addVertex(v3);
    g.addVertex(*v4);//deferencing the pointer
    g.printGraph();

    g.addEdgeById(1,2,23);
    g.addEdgeById(1,3,45);
    g.addEdgeById(1,4,12);
    g.addEdgeById(2,3,87);

    g.printGraph();

    g.UpdateEdgeByID(1,2,99);
    g.printGraph();
    g.deleteEdgebyId(1,2);
    g.printGraph();

    //g.deleteVertexxByid(1);
    g.printGraph();   
    g.printAllNeigboursByid(3); 
    g.updateVertexbyID(2,"DOmpe");
    std::cout<<(g.getVertexbyId(2)).getStateName()<<std::endl;

    std::list<Vertex> bfsTraversed=g.BFS(v2);
    for(auto itr=bfsTraversed.begin();itr!=bfsTraversed.end();itr++){//print the bfs in order
    std::cout<<itr->state_id<<"-->";

    }
    std::cout<<std::endl;



        return 0;

}
