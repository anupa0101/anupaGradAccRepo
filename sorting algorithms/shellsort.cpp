#include<iostream>
#include<conio.h>

//inplace COMPARISON TYPE sort like  , isnsertion
//variatiom of bubble or insertion sort
//this method avoids large shifts. which may occur in insertion sort 
//if the small value is to the far END it needs to be moved to the far left
//here it is faster
//SHELL SORT IS MORE EFFICIENT WHEN 
//1. WHEN SMALL VALUES ARE TOWARDS THE END
//2. ARRAY IS LARGE

//EFFICIENCY DEPENDS ON HOW WE SETUp THE GAP/INTERVAL= h
//here we choose h=n/2

//TIME COMPLEXITY- worst case o(n^2), best case nlogn, avg case nlog(n^2)???
//SPACE COMPLEXITY - 0(1) inplace comparison type sort

//ALGORITHM
//1. INITIALIZE THE GAP. 
//2. compare elemennts placed at this gap
//3. of element is larger , perform swap(bubble sort) or shift (insertion sort)
//IF SWAP IS DONE THEN SHOULD BE CHECKED THE OTHER WAY AS WELL.
//4. repeat  here gap h=n/2.. reduces every itertion and stops at 0

void shellSort(int arr[],int sz){
    
    for(int gap=sz/2;gap>0;gap/=2){ //reduces the gap size in each iteration

        for (int j=gap;j<sz;j++){

            int temp=arr[j];//stores the value temporarily for swaping
            int i;
            for(i=j;(i>=gap) && (arr[i-gap])>temp;i-=gap){ //checks both sides if swap is done
                arr[i]=arr[i-gap];
            }
            arr[i]=temp;
        }
  
    }

}

int main(){
    const int SIZE=6;
    int *arry=new int[SIZE]{14,3,26,8012,124,1};
    for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<"\n after sort \n";


    shellSort( arry, SIZE); //use max+1 as range as  the max also needs to be included in the count array.

        for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<'\n';
    
    delete []arry;

    _getch();
    return 0;
}