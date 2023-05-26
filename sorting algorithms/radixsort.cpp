#include<iostream>
#include<conio.h>


//COUTING SORT USED HERE IS SLIGHTLY DIFFERENT FROM THE PREVIOSULY DEVELOPED COUNTING SORT

//aka digital sort, bucket sort
//ONLY FOR INTEGERS- INDEX IS USED .. NO NEGATIVE VALIUES( workaround- can add the min and make the range start from 0 and do, then substaract)
//radixSORT TIME COMPLEXITY IS Od(n+k)  LINEAR- d- number of digits in then max element , K= RANGE OF INPUT  - 0 to max val

//so SPACE COMPLEXITY IS 0(n+k)-LINEAR K= RANGE OF INPUT

//USES COUNTING SORT AS A SUBROUTINE. Does counting sort on individual digits to avoid having to create andn traavere huge arrays

//THIS IS NON COMPARISON TYPE SORT.
//THIS HAS MUCH LOWER time COMPLEXITY COMPARED TO COMAPRISON TYPE SORT  LIKE MERGE OR QUICK SORT

//ALGORITHM-

//Range k is the range from 0 to 9= 10)

//1. From ip array find max number
//2. Create 10 QUEUES each representing a bucket for each diigit  from 0-9
//3. Consider LSD of each number and insert into their respective queues.
//4. Group all numbers from queue  0 to queue 9 inorder they have inserted(FIFO) into the array
//5. repeat from tep 3 but from next significant number for the formed array
//6. Repeat till all numbers are grouped based on the MSD
//COUTING SORT USED HERE IS SLIGHTLY DIFFERENT FROM THE PREVIOSULY DEVELOPED COUNTING SORT

//ACTUAL ALGORITHM DOESNT USE QUEUES. JUST USES COUTNING SORT REPEATEDLY ON EACH DIGIT

int GetMax(int arr[], int siz){ //to get the max value
    int max=arr[0];
    for(int i=0;i<siz;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void countingSort( int input_array[], int sz, int div) // div parameter instead of range r/***DIFFERENT***// 
{
    int r=10; // range r=10 (0-9) . since r is a constant can use normal array//***DIFFERENT***// 
    int *output_array=new int[sz];// op array of sz size
    int *count_array=new int[r];// count array of range size   since r is a constant can use normal array
    
    for(int i=0; i<r; i++){  //intialize all elements to 0
        count_array[i]=0;  //can use int *count_array=new int[r]{0};
    }

    for(int i=0; i<sz; i++){  //the indexs of the count array corresponds to unique elements in the ip array
        ++count_array[(input_array[i]/div)%10];  //everytime theres a  element that index in count array is incremented
    }                               //***DIFFERENT***// 

//make the count array cumulative
    for(int i=1; i<r; i++){  //start from 1(not 0) then add the prev
        count_array[i]=count_array[i]+count_array[i-1];  
    }

//mapping-find position of the elements on the op array using values in the cumilative count array
    for(int i=sz-1; i>=0; i--){  // stars from end 
        output_array[--count_array[(input_array[i]/div)%10]]=input_array[i]; //***DIFFERENT***//  
    }
    //the position of terms in the ip array to be added to the op array can be found using
   //cumilative count of the element  -1 IS WRONG. -- WILL REDUCE count_array[input_array[i]] IN EVERY ITERATION, SO 


    for(int x=0;x<sz;x++){ //copy from op array to input array
        input_array[x]=output_array[x];
    }
    delete []output_array;
    delete []count_array;

    //1. to find r - max value

/*        int r=input_array[0]; //max finding algorithm
    for(int i=0;i<sz;i++){
        if(r<arry[i]){
            r=arry[i]; }
    }
    r=r+1;//use max+1 as range as  the max also needs to be included in the count array. */

    //IF THERE ARE NEGATIVE VALUES CAN NORMALIZE??? MY WAY
    //2. Find the smallest value. check if its negative.
    //if negative. then add the positive value of min to all elements.
    //do normal count sort after finding the new range
    //then when copying substract the min
    //worked for me
}
void radixSort(int arr[], int sz)
{
    
    int m=GetMax(arr,sz);// to get the number of digits
    for(int div=1;m/div>0;div*=10)// will iterate the number of digits of the max value
    {                               //div= 1; 10; 100.... will become zero at one point
        countingSort(arr,sz,div);  //COUTING SORT USED HERE IS SLIGHTLY DIFFERENT FROM THE PREVIOSULY DEVELOPED COUNTING SORT

    }
}

int main(){
    const int SIZE=6;
    int *arry=new int[SIZE]{14,3,26,8012,124,1};
    for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<"\n after sort \n";

    /*  int min=arry[0]; //find smallest value
    
    for(int i=0;i<SIZE;i++){
        if(min>arry[i]){
            min=arry[i];
        }

    }
    if(min<0){ //if its negative. then add positive min to make the range from 0.- smallest value 0. ELSE DO NOTHN
        min=min*-1;
        for(int i=0;i<SIZE;i++){
        arry[i]=arry[i]+min;
        }
    } */
    radixSort( arry, SIZE); //use max+1 as range as  the max also needs to be included in the count array.

        for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<'\n';
    
    delete []arry;

    return 0;
}
