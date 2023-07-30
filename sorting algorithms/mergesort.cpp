#include<iostream>
#include<conio.h>

//MERGE SORT TIME COMPLEXITY IS O(nlogn)- ONE OF THE MOST EFFICENCNT
//divide and conquor- divides input arrray to 2 halves. 
//calls itself for the two halves recursively (TILL 1 element)  and then merges the sorted halves
//SPACE COMPLEXITY IS 0(N)- need the temp array of n size

//NO NEED TO MAKE THE TEMP ARR THE SIZE OF N. WE CAN JJUST MAKE IT SIZE OF
//R-L+1.  THEN K WILL START FROM 0 NOT L. BUT WHEN COPYING BACK LETS ADD L to make sure its added to the correct place of the original arr

//ALGORITHM-

//1. .find middle point- m= (r+l)/ 2
//2. call mergesort(arr, l,m) //split left side
//3.mergesort(arr,m+1,r)// split right side
//4. merge(arr,l,m,r)

void merge(int arr[], int l, int m, int r){

    int *temp=new int[r-l+1]; //array created
//USED a dynamic array because cant pass in variable to decide the size of the temp array. 
    int i=l; //like the index of the split left array
    int j=m+1;//like the index of the split right array
    int k=0; // index of the temp array
    

    while(i<=m && j<=r)//loop till either left or right array completes
    {
        if(arr[i]<=arr[j]){//CHANGE SIGN HERE FOR DECENDING ORDER
            temp[k]=arr[i];
            i++;// advance index on the left split array
            k++; //move to next index on the temp array
        }
        else{
            temp[k]=arr[j];
            j++;// advance index on the right split array
            k++;//move to next index on the temp array
        }

    }

    while(i<=m){// till the left split array completes
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=r){// till the right split array completes
        temp[k]=arr[j];
        k++;
        j++;

    }
    for(int p=0;p<k;p++){ //copy to array. here its p<k not p<=k because k++ is done above.k=size

        arr[p+l]=temp[p];//P+L copied to p+L as we need to copy to the correct place of the original array.
    }
    delete []temp;///delete temp


}

void mergeSort( int arr[], int l, int r)
{
    if(l<r){ //do nothng when l=r. only single element remaining

        int m=(l+r)/2; //mid point
        mergeSort(arr,l,m);//merge sort the left split array
        mergeSort(arr,m+1,r);//merge sort the right split array
        merge(arr,l,m,r); //merge  
    }
}

int main(){
    const int SIZE=6;
    int *arry=new int[SIZE]{4,3,6,8,4,1};
    for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<"\n after sort \n";

    
    mergeSort( arry,0,SIZE-1);

        for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<'\n';
    
    delete []arry;

    return 0;
}