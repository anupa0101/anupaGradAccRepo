#include<iostream>
#include<conio.h>
#include<algorithm>
#include<string>


//findthe maximum subarray. use kadanes algorithm- 0(n)


int main(){


    int arr[4]={2,3,-2,4};
    int global_max=arr[0];//the global maximumm sub array
    int current_max=arr[0];// the maximum subarray ending at index i.
    // it is the value at the index(sub array is just itself) or the current max subarray + the current index

    for(int i=1;i<4;i++){//start from index 1
        current_max=std::max(arr[i],current_max+arr[i] ); ///max of value at the index(sub array is just itself) or the current max subarray + the current index
        if(current_max>global_max){
            global_max=current_max;
        }               
    }

    std::cout<<global_max<<std::endl;

    int global_prodmax=arr[0];//the global maximumm prod sub array
    int current_prodmax=arr[0];// the maximum prod subarray ending at index i.
    // it is the value at the index(sub array is just itself) or the current max prod subarray * the current index

    for(int i=1;i<4;i++){//start from index 1
        current_prodmax=std::max(arr[i],current_prodmax*arr[i] ); ///max of value at the index(sub array is just itself) or the current max subarray times the current index
        if(current_prodmax>global_prodmax){
            global_prodmax=current_prodmax;
        }               
    }
   

//to find maximum products of sub array'

        int max_p=1, min_p=1, mp=INT_MIN;
        for(int i: arr){
            // i, i*reg_p, i*neg_p
            
            int pos=std::max(std::max(max_p*i, i), min_p*i);
            int neg=std::min(std::min(max_p*i, i), min_p*i);

            max_p=pos;
            min_p=neg;

            mp=std::max(std::max(mp, max_p), min_p);
         }
         std::cout<<mp<<std::endl;
        

    
    return 0;
}