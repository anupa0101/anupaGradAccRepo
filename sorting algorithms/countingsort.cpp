#include<iostream>
#include<conio.h>


//ONLY FOR INTEGERS- INDEX IS USED .. NO NEGATIVE VALIUES( workaround- can add the min and make the range start from 0 and do, then substaract)
//counting SORT TIME COMPLEXITY IS O(n+k)- LINEAR K= RANGE OF INPUT  -  - 0 to max val
//EXAMPLE OF RANGE 0 TO 9 IS 10. (USE MAX+1) AS THE R FOR THE FUNCTION INPUT


//so SPACE COMPLEXITY IS 0(n+k)-LINEAR K= RANGE OF INPUT
//USE WHEN RANGE-K IS SMALLER THAN THE NUMBER OF ELEMENTS-N. OR ELSE TIME COMPLEXITY IS HIGH BECAUSE OF HHIGH K

//USE WHEN RANGE IS SMALL - K IS SMALL. OR ELSE LARGE ARRAyS NEEDS TO BE TRAVERSED

//THIS IS NON COMPARISON TYPE SORT.
//THIS HAS MUCH LOWER time COMPLEXITY COMPARED TO COMAPRISON TYPE SORT  LIKE MERGE OR QUICK SORT

//ALGORITHM-

//Range k is the range from 0 to MAXIMUM value. (not minnimum to max)

//1. Create an ouput array the size of the ip aray
//2. Create a count array the size of the range and i initilaize to 0
//3. Count each element in the ip array and place in count array
//4.Makde the count arry cumilative// TO GET DECSENDING ORDER GET THE CUMULATIVE IN THE OPPOSITE DIRECTION
//5. Use arithemtic to find position in the op array using values in cumilatuve count array
//6. trasnsfer to op array


void countingSort( int input_array[], int sz, int r)
{




    int *output_array=new int[sz];// op array of sz size
    int *count_array=new int[r];// count array of range size
    
    for(int i=0; i<r; i++){  //intialize all elements to 0
        count_array[i]=0;  //can use int *count_array=new int[r]{0};
    }

    for(int i=0; i<sz; i++){  //the indexs of the count array corresponds to unique elements in the ip array
        ++count_array[input_array[i]];  //everytime theres a unique element that index in count array is incremented
    }
    
//NO NEED TO MAKE IT CUMULATIVE TO SORT NUMBERS.(NEED IT TO SORT OTHERS LU- not sure), CAN JUST PRINT THE COUNT_ARRAY UNTILL THE VALUE GOES TO ZERO THEN MOVE TO TTHE NEXT INDEX
//ALWAYS make the count array cumulative
    for(int i=1; i<r; i++){  //start from 1(not 0) then add the prev
        count_array[i]=count_array[i]+count_array[i-1];  
    }

/*     //FOR DESCENDING ORDER- make the count array cumulative in the opposite direction
    for(int i=r-2; i>=0; i--){  //start from 1(not 0) then add the prev
        count_array[i]=count_array[i]+count_array[i+1];  
    } */

//mapping-find position of the elements on the op array using values in the cumilative count array
    for(int i=sz-1; i>=0; i--){  //stars from end backwards
        output_array[--count_array[input_array[i]]]=input_array[i];  //this decrements value stored in count array by 1 and saves it
    }
    //the position of terms in the ip array to be added to the op array can be found using
    //  cumilative count of the element  -1 IS WRONG as it wont decrement the value stored. -- WILL REDUCE count_array[input_array[i]] IN EVERY ITERATION, SO 


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

int main(){
    const int SIZE=18;
    int *arry=new int[SIZE]{1,9,2,7,6,4,8,6,2,5,9,4,4,3,6,8,4,1};
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
    

    int max=arry[0];
    
    for(int i=0;i<SIZE;i++){
        if(max<arry[i]){
            max=arry[i];
        }

    }
    
    countingSort( arry, SIZE,max+1); //use max+1 as range as  the max also needs to be included in the count array.

        for(int i=0; i<SIZE;i++){
        std::cout<<arry[i]<<'\t';
    }
    std::cout<<'\n';
    
    delete []arry;

    return 0;
}