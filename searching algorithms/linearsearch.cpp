#include<iostream>
#include<conio.h>

//Types of searching algorithms 
//1. Sequential search ex: Linear search 
//2. interval search ex: Binary search  

void LinearSearch(int a[],int sz,int num){

    bool flag=false;
    for (int i=0;i<sz;i++){
            if(a[i]==num){ 
                std::cout<<"Found at "<<i<<std::endl;
                flag=true;
                return;
            }


    }
    if (flag==false){
        std::cout<<"Not Found "<<std::endl;
    }
}

int main(){
    int SIZE=5;

    int *arr;
    arr= new int[SIZE]{1,3,5,2,7};

    
    for(int i=0; i<SIZE; i++){
        std::cout<<arr[i]<<'\t';
    }
    std::cout<<'\n';

    LinearSearch(arr,SIZE,3);

    delete []arr;


    return 0;
}