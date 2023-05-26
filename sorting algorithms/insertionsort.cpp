#include<iostream>
#include<conio.h>

//INSERTION SORT TIME COMPLEXITY IS O(n^2)- INEFFICENT
//INPRACTICE MORE EFFICENT THAN SELECTION AND BUBBLE#########################
//SPACE COMPLEXITY IS 0(1)
//INPLACE COMPARISON SORT - DOESNT USE EXTRA SPACE FOR MANIPULATING THE INPUT

//ALGORITHM

//1. Pick and element. start from the 2nd element index=1
//2. Shift right all elments thats at the (left of the picked element) that is greater than the picked element 
//3. INSERT the picked element
//4, continue till the end




void insertionSort( int arr[], int sz)
{

    int key;//value at the picked element
    int j;//reverse starting point of the left subarry
    for (int i=1; i<sz;i++)//start from index 1(2nd element)
    {
        key=arr[i]; //picked element
        j=i-1;//reverse starting point of the left side array 

        while(j>=0 && key<arr[j]){        //CHANGE SYMBOL FOR DECENDING ORDER
            arr[j+1]=arr[j];  //shifting all elements in left side greater than the picked(key) element to the right
            j--;                  //decrementing to check from right to left   from pickedd point     

        }
        arr[j+1]=key; //INSERTING the picked(key) at the right place
        
    }
}

int main(){
    int SIZE=6;
    int *arry=new int[SIZE]{4,3,6,8,4,1};
    for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<"\n after sort \n";

    
    insertionSort( arry, SIZE);

        for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<'\n';
    
    delete []arry;

    return 0;
}