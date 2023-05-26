#include<iostream>
#include<conio.h>




void merge(int arr [], int sz, int l, int m, int r){
    int *temp= new int[sz];
    int i=l;
    int j=m+1;
    int k=l;

    while(i<=m && j<=r){

        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
        while(i<=m){
            temp[k]=arr[i];
            i++;
            k++;

        }
        while(j<=r){
            temp[k]=arr[j];
            j++;
            k++;
            
        }
    
    for(int p=l;p<=r;p++){
        arr[p]=temp[p];

    }
    delete []temp;
    
 
}

void mergesort(int arr [], int sz, int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(arr, sz,l,m);
        mergesort(arr,sz,m+1,r);
        merge(arr,sz,l,m,r);
    }
}




int main(){
    int arr[5]={1,9,5,7,8};
    mergesort(arr,5,0,4);
    for(int n: arr){
            std::cout<<n<<std::endl;

    }
    
    return 0;
}