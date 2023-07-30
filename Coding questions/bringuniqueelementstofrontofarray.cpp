#include<iostream>
#include<conio.h>
#include<algorithm>
// not good?
void bringuniqueelementstothefront(int arr[], int siz){
    
    std::sort(arr,arr+siz);
    int k=0; //swapping index
    for(int i=0;i<siz;i++){
        bool flag=false;
        for(int j=k;j<siz;j++){
            if(arr[i]==arr[j]&&i!=j){
                flag=true;
                break;
            }

        }
        if(flag==false){
            int temp=arr[k];
            arr[k]=arr[i];
            arr[i]=temp;
            k++;
        }
        
    }



}

int main(){
    
    int arr[]={1,6,3,4,1,8,4,2,3,5};
    int arr_siz=sizeof(arr)/sizeof(arr[0]);

    bringuniqueelementstothefront(arr, arr_siz);
     for(int i=0;i<arr_siz;i++){
        std::cout<<arr[i]<<"\t";
     }




    return 0;
}