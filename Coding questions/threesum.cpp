//INCOMPLETE


#include<iostream>
#include<conio.h>
#include<vector>
#include<unordered_set>
#include<iterator>
#include<algorithm>
//find all sets of 3 numbers that add to sum
// can use for binary search for the other 2 after sorting. thats n *n *logn
//can use 2 pointer thats log(n2)
//hash is also log(n2)

//using hash set gives o(n) space complexity , 2 pointer approach gives 0(1). both time complexities are o(n2)

int main(){
    int sum=9;
    std::vector<int> num_arr={1,0,3,4,5,4,4,8};
    sort(num_arr.begin(),num_arr.end());// sorting is nlogn also space complexity of logn
    //JUST USE undoredd set to save the unique 3s. so therre wont be any duplicates
    for(int i=0;i<num_arr.size()-2;i++){
        while(num_arr[i+1]==num_arr[i] && i<num_arr.size())i++;//increment till element infront is different

        int fNum=num_arr[i];
        int comp=sum-fNum;
        std::unordered_set<int> num; // increases space complexity to o(n)
        for(int j=i+1;j<num_arr.size();j++){
            
            if(num.find(num_arr[j])==num.end()){//if the current element is not in the set
                if(num.find(comp-num_arr[j])!=num.end()){// if the complement is found
                    std::cout<<i<<'\t'<< num_arr[j]<<'\t'<<comp-num_arr[j]<<std::endl;
                }
                num.insert(num_arr[j]);// insert the currnt element. prevents duplicates
            }                                                
        }

    }
    return 0;
}

// two pointer approach
/* 

#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
//find unqiue triplets that sum to a certain value with o(n^2).

//sort the array
//use two pointer approach. 
//take i element in for loop. substract from sum==sumRemoved. use two indices from i+1 and end. 
//as its sorted i++ if sum of remaining two is smaller than sumRemoved. end-1 if sum larger
std::vector<std::vector<int>> uniqueTriplets(std::vector<int> &,int sum);

int main(){

    int sum=8;
    std::vector<int> arr={-1,0,0,2,3,5,6,7,8};
    std::vector<std::vector<int>> unique=uniqueTriplets(arr,sum);
                 std::cout<<std::endl;


     for(int i=0;i<unique.size();i++){
             for(int j=0;j<unique[i].size();j++){
             std::cout<<unique[i][j]<<'\t';
             }
             std::cout<<std::endl;
        }
     return 0;
}

std::vector<std::vector<int>> uniqueTriplets(std::vector<int> &arr,int sum){

    std::sort(arr.begin(),arr.end());//sorting the array- o(logn)- ignored as the logn+ (n^2)==== n^2

     std::vector<std::vector<int>> uniqueTriplets; // make this a set?
    for(int i=0;i<arr.size()-2;i++){// time complexity is o(n) and thetwo pointer is log(n) so all log(n^2)
        while(arr[i]==arr[i+1] && i<arr.size()){// till unique of first element is found
            i++;
        }
        int sumRem=sum- arr[i];
        int front=i+1;
        int back=arr.size()-1;



        while(front<back){//DO NOT USE FRONT!=BACK- IT CAN SKIP THIS CONDITION AT AT FRONT++ AND BACK--
            int sumOfTwo=arr[front]+arr[back];
            if(sumOfTwo==sumRem){

                uniqueTriplets.push_back({arr[i],arr[front],arr[back]});
                do{
                    front++;
                }while(arr[front]==arr[front-1] && front<back);// do once then increment till unique of 2nd element is found

                do{
                    back--;
                }while(arr[back]==arr[front+1]&& front<back);// do once then decrement till unique of 3rd element isfound
                

            }
            else if(sumOfTwo<sumRem){
                 do{
                    front++;
                }while(arr[front]==arr[front-1]&& front<back);// do once then increment till unique of 2nd element is found

            }
            else{
                do{
                    back--;
                }while(arr[back]==arr[front+1] && front<back);// do once then decrement till unique of3rd element is found
            }
        }

    }
    return uniqueTriplets;
}
    

 */

