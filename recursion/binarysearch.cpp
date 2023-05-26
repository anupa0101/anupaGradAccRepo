#include<iostream>
#include<conio.h>




int binarysearchrecursively(int arr [], int l, int r, int val){
  if(l>r){
    return false; //exhausted - not found
  }

  int m=(l+r)/2;
  if(arr[m]==val){
    return true;
  }
  else if(val>arr[m]){
    return binarysearchrecursively(arr,m+1,r,val);
  }
   else{
    return binarysearchrecursively(arr,l,m-1,val);
   }
}

int binarysearch(int arr [], int l, int r, int val){

        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]==val){
                return true;
            }
            else if(val>arr[m]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return false;

}
 size_t binarySearchrecursively( int arr[], int l, int r, int val){

  if(r<l){
    return -1;
  }
  int m=(l+r)/2;

  if(arr[m]==val){
    return m;
  }
  else if(arr[m]>val){
    return binarySearchrecursively(arr, l, m-1,val);
  }
  else {
    return binarySearchrecursively(arr, m+1, r,val);
  }

 }




int main(){
    int arr[5]={1,3,5,7,8};
    int res=binarySearchrecursively(arr,0,4,3);
    
    std::cout<<res<<std::endl;
    
    return 0;
}