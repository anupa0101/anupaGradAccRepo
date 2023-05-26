#include<iostream>
#include<conio.h>

//Binary search used for sorted only - type of interval search
//compare and divide by half and search
//time complexity is O(logn)
//space complexity in RECURSION its of 0(logn)
int BinarSearch(int a[],int left, int right ,int x){

    while(left<=right){
        int mid=left+ (right-left)/2;
        if(a[mid]==x){ //if the x value is at mid index 
            return mid;//breaks;
        }
        else if(a[mid]>x){ //move right to the middle
          return BinarSearch(a,left,mid-1 , x);   //RECURSIVELY RETURN THE SAME FUNCTION
          
            
        }
        else{ //move left to the middle
           return BinarSearch(a,mid+1,right, x);
            
            
        }
    }
    std::cout<<" Not found\n";
    return -1; //if the loop isnt broken index -1 is returned. element not found
}

int main(){
    int SIZE=5;
    int find=7;

    
    int *arr= new int[SIZE]{1,3,5,2,7};

    
    for(int i=0; i<SIZE; i++){
        std::cout<<arr[i]<<'\t';
    }
    std::cout<<'\n';

    
    if (BinarSearch(arr,0,SIZE-1,find)!=-1)
    {
    std::cout<<" Found at :"<<BinarSearch(arr,0,SIZE,find)<<std::endl;
    }
    else{
        std::cout<<" Not found\n";
    }

    delete []arr;


    return 0;
}