#include<iostream>
#include<conio.h>
#include<algorithm>
#include<vector>
#include<queue>


//find the time taken to rotten all oranges. 0 is empty, 1 is fresh, 2 is rotte.m rotten can rot fresh oranged up, down, left and right in unit time
//use queue and pass in the time as well

void print( std::vector<std::vector<int>> visited){
       int n=visited.size();
       int m=visited.at(0).size();
     for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                std::cout<<visited.at(i).at(j)<<" ";
            }
             std::cout<<std::endl;
     }
                  std::cout<<std::endl;

}
int timetorot(std::vector<std::vector<int>>& grid ){

       int n=grid.size();
       int m=grid.at(0).size();
       std::queue<std::vector<int>> bfsQueue;
       std::vector<std::vector<int>> visited={{0,0,0},{0,0,0},{0,0,0}};
       int tim=0;
       for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid.at(i).at(j)==2){//when rotten is found
                std::vector<int> vert={i,j,tim};// add the coordinates and time to the queue
                bfsQueue.push(vert);
                visited[i][j]=1;//visited these nodes

                }
                else{
                    visited[i][j]=0;//not visited these nodes


                }
            }
       }
       while(!bfsQueue.empty()){
            std::vector<int> vertPoped=bfsQueue.front();
            print(visited);

            bfsQueue.pop();
            std::cout<<vertPoped[0]<<" "<<vertPoped[1]<<" "<<vertPoped[2]<<std::endl;
            bool traversed=false;
            if(vertPoped[0]-1>=0 && vertPoped[0]-1<n && vertPoped[1]>=0 && vertPoped[1]<m && grid.at(vertPoped[0]-1).at(vertPoped[1])==1&&visited.at(vertPoped[0]-1).at(vertPoped[1])!=1){//inside bounds and fresh=1 and not visited
                    bfsQueue.push({vertPoped[0]-1, vertPoped[1],tim+1});
                     visited.at(vertPoped[0]-1).at(vertPoped[1])=1;//visited
                     traversed=true;
                     print(visited);
            }
                if(vertPoped[0]+1>=0 && vertPoped[0]+1<n && vertPoped[1]>=0 && vertPoped[1]<m && grid.at(vertPoped[0]+1).at(vertPoped[1])==1&&visited.at(vertPoped[0]+1).at(vertPoped[1])!=1){//inside bounds and fresh=1 and not visited
                    bfsQueue.push({vertPoped[0]+1, vertPoped[1],tim+1});
                     visited.at(vertPoped[0]+1).at(vertPoped[1])=1;//visited
                      traversed=true;
                    print(visited);

            }
                if(vertPoped[0]>=0 && vertPoped[0]<n && vertPoped[1]-1>=0 && vertPoped[1]-1<m && grid.at(vertPoped[0]).at(vertPoped[1]-1)==1&&visited.at(vertPoped[0]).at(vertPoped[1]-1)!=1){//inside bounds and fresh=1 and not visited
                    bfsQueue.push({vertPoped[0], vertPoped[1]-1,tim+1});
                     visited.at(vertPoped[0]).at(vertPoped[1]-1)=1;//visited
                      traversed=true;
                    print(visited);

            }
                if(vertPoped[0]>=0 && vertPoped[0]<n && vertPoped[1]+1>=0 && vertPoped[1]+1<m && grid.at(vertPoped[0]).at(vertPoped[1]+1)==1&&visited.at(vertPoped[0]).at(vertPoped[1]+1)!=1){//inside bounds and fresh=1 and not visited
                    bfsQueue.push({vertPoped[0], vertPoped[1]+1,tim+1});
                     visited.at(vertPoped[0]).at(vertPoped[1]+1)=1;//visited
                      traversed=true;
                    print(visited);

            }
            if( traversed){
                    tim= vertPoped[2];//as we add tim+1


            }

       }
       return tim;


}

int main(){



    std::vector<std::vector<int>> gridd={{0,1,2},
                                        {0,1,1},
                                        {2,1,1}};
        
    int ret= timetorot(gridd);
    std::cout<<ret;//wrong result
    
    return 0;
}