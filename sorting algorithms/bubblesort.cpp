#include<iostream>
#include<conio.h>

//BUBBLE SORT TIME COMPLEXITY IS O(n^2)- INEFFICENT

//SPACE COMPLEXITY IS 0(1)
//INPLACE COMPARISON SORT - DOESNT USE EXTRA SPACE FOR MANIPULATING THE INPUT
//like a bubble the largest element bubbles to the highest index

//ALGORITHM- sorts from the end towards the begining

//1. . start from the 1st element index=0
//2. compare the adjacent next element and swap is its bigger. and continue comparing the adjent all the way and swapping. 
//THE LARGEST ELEMENT BBUBBLES TO THE TOP(HIGHEST INDEX) in the first iteration
//3. Do the same, BUT now not till the end but till (size-1-num of iterations)



void bubbleSort( int arr[], int sz)
{

    for (size_t i=0; i<sz;i++)//i will reduce the unsorted array in each iteration
    {
        
        for (size_t j=0; j<(sz-i-1);j++){        //SIZE-i-1 as we check j+1
            if(arr[j+1]<arr[j]){//CHANGE SYMBOL FOR DECENDING ORDER
                int temp=arr[j];  
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
}

int main(){
    int SIZE=6;
    int *arry=new int[SIZE]{4,3,6,8,4,1};
    for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<"\n after sort \n";

    
    bubbleSort( arry, SIZE);

        for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<'\n';
    
    delete []arry;

    return 0;
}