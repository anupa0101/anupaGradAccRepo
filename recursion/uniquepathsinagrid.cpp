#include<iostream>
#include<conio.h>
#include<stack>

//given an n by m matrix. find the nummberr of unique paths from top left to bottom right
//can only move one step right or down. no opposite direction

// base case all nx1 and 1xm matrice have only one path
// no of paths in nm matrix = no in n x (m-1) and (n-1) x m

int noOfPaths( int n, int m){
    if(n==1||m==1){
        return 1;
    }
    else{

        return noOfPaths(n-1,m)+noOfPaths(n,m-1);
    }
}





int main(){
  
    std::cout<<noOfPaths(3,4)<<std::endl;
    
    return 0;
}