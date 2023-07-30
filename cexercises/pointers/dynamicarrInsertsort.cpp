#include<iostream>
#include<conio.h>

using namespace std;

int retmax(int *, int siz);
int retmin(int *, int siz);
int retavg(int *, int siz);
int retmed(const int[], int siz);
int main()

{
    int size;
    cout<<"enter siz";
    cin>>size;
    cout<<size<<endl;
    int *ptr;
    ptr= new int[size];
    for(int i=0;i<size;i++){
        cin>>ptr[i];
    }

    for(int i=0;i<size;i++){
        int k=i;
        while((k>0)&&(ptr[k-1]>ptr[k])){
            int temp=ptr[k];
            ptr[k]=ptr[k-1];
            ptr[k-1]=temp;
            k-=1;

 
        }
    }

     

    cout<<" min median maxc : "<<ptr[0]<<ptr[size/2]<<ptr[size-1]<<endl;

    cout<<retmax(ptr,size)<<endl;
    cout<<retmin(ptr,size)<<endl;
    cout<<retavg(ptr,size)<<endl;
    cout<<retmed(ptr,size)<<endl;




    delete []ptr;
    ptr=NULL;

    _getch;
    return 0;
}

int retmax(int *ar, int siz){
        int max=*ar;
        for(int i=0;i<siz;i++){
            if(ar[i]>max){
                max=ar[i];
            }


        }
        return max;
    
}
int retmin(int *ar, int siz){
        int min=*ar;
        for(int i=0;i<siz;i++){
            if(ar[i]<min){
                min=ar[i];
            }
        }
    return  min;

}

int retavg(int *ar, int siz){

        int avg=0;
        for(int i=0;i<siz;i++){
            
               avg+=ar[i];
            }
        
    return (avg/siz);    
    
}
int retmed(const int ar[], int siz){

    int *psort, med;
    psort=new int[siz];
    for(int i=0;i<siz;i++){
            
               psort[i]=ar[i];
            }
    for(int i=0;i<siz;i++){
    int k=i;
    while((k>0)&&(psort[k-1]>psort[k])){
        int temp=psort[k];
        psort[k]=psort[k-1];
        psort[k-1]=temp;
        k-=1;
        }
    }

    return (psort[siz/2]);


}