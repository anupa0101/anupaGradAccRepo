#include<iostream>
#include<conio.h>

//SELECTION SORT TIME COMPLEXITY IS O(n^2)- INEFFICENT
//SPACE COMPLEXITY IS 0(1)
//INPLACE COMPARISON SORT - DOESNT USE EXTRA SPACE FOR MANIPULATING THE INPUT

//SELECTS THE LOWEST/HIGHEST TERM IN THE RIGHT SUBLIST AND SWAPS WITH THE LEFT MOST UNSORTED ELEMNT


void selectionSort( int arr[], int sz)
{
    for (int i=0; i<sz;i++)
    {
        int minIndx=i;// stores the index of the smallest value
        for(int j=i+1;j<sz;j++){//search from i+1 th element
            if(arr[minIndx]>arr[j]){ //just change the sign for decending order
                minIndx=j;//get the min value in the right side 
            }

        }
        
        if(minIndx!=i){ //find the smallest term on the right and swap with the leftmost unsorted element 
            int temp=arr[i];
            arr[i]=arr[minIndx];
            arr[minIndx]=temp;
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

    
    selectionSort( arry, SIZE);

        for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<'\n';
    
    delete []arry;

    return 0;
}