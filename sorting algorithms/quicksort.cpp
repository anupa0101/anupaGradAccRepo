#include<iostream>
#include<conio.h>

//QUICK SORT TIME COMPLEXITY IS O(nlogn)- ONE OF THE MOST EFFICENCNT- 
// however this may vary choosing the pivot pt is important, if badly chosen will make TC on^2.
// in merge sort its always nlogn- more stable.
//divide and conquor- uses recursion
//inplace sorting algorithm- no auxillary array(temp[]) is needed like in mergesort(arr,sz,s,e);

//so SPACE COMPLEXITY IS 0(logN) but in worst case of bad pivot choosing then its o(n)

//different ways to select the pivot, first, last or random. median of first middle and last element is also good. helps ensure the pivot is rougly in the middle
//here picking last. pivot selection is important/.if largesst or smallest choosen. it causes recursive tree to have 0 or 1 eleemnt on one side and the array on the other side. like more linear type. 
//causing o TC n^2 and SC on 

//ALGORITHM-

//1. Pivot point is choosen- last term 
//2. Find partition index- sofrting actually happens inside the partition functionn
//3. qick sort first half //split left side
//4.qick sort second half// split right side


int Partition(int arr[], int sz, int s,int e){

    int pivot=arr[e]; //select the last element as pivot
    int pIndex=s; //go from the start of the sub array beonging to this function
    //pIndex tracks where the values smaller than pivot val ends and larger begins to insert pivot later
    for (int i=s;i<e;i++){ //i<e as we need to STOP before the pivot pt
        if(arr[i]<=pivot){//check if each smaller than or equal to pivot value. pivot is like a REFFERENCE to swap
            
            int temp=arr[i]; //swap smaller than pivot values with the value at pindex and advance pindex to the right
            arr[i]=arr[pIndex];
            arr[pIndex]=temp;
            pIndex++;
        }
    }
    //now insert the pivot element where pIndex stopped.. 
    //where the swapping stopped...where all to the left are smaller than pivot
    arr[e]=arr[pIndex]; //swap pivot with one at pIndex
    arr[pIndex]=pivot;
    return pIndex; //output the pivot index
}


void quickSort( int arr[], int sz, int s, int e)
{
    if(s<e){ 

        int p=Partition(arr,sz,s,e);// returns the pivot point. actual sorting happens here
        quickSort(arr,sz,s,(p-1));// for the left of the pivot pt
        quickSort(arr,sz,(p+1),e); //for the right of the pivot pt
        
    }
    
}


int main(){
    const int SIZE=6;
    int *arry=new int[SIZE]{4,3,6,8,4,1};
    for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<"\n after sort \n";

    
    quickSort( arry, SIZE,0,SIZE-1);

        for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<'\n';
    
    delete []arry;

    return 0;
}