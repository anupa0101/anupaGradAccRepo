#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
//WIHTOUT meomization incredibly inefficent- o(2^n) 2 to the power n.. 
//SPACE COMPLEXITY IS O(N) due to recursive calll stack
/* 


int fibonaci( int n){
    if(n==0||n==1){
        return n;
    }
    return fibonaci(n-1)+fibonaci(n-2); */

//after momization
/* std::vector<int> memo(100,0);
int fib(int n, std::vector<int>& memo){

    if(n==0||n==1){
        return n;
    }
    if(memo[n]!=0){
        return memo[n];
    }
    memo[n]=fib(n-1)+fib(n-2);
    return memo[n];
} */
//time complexity is o(N)
//same 0(n) space complexity as the memeoization array just stores the removedd recursive calls
int memo[1000]={0};

int fibonaci( int n){
    if(n==0||n==1){
        return n;
    }
  
    if(memo[n]!=0){//if present in the  momization array return it
        return memo[n];
    }
    memo[n]= fibonaci(n-1)+fibonaci(n-2);//else use recursion
    return memo[n];
  

}





int main(){


    std::cout<<fibonaci(7)<<std::endl;

        
    return 0;
}