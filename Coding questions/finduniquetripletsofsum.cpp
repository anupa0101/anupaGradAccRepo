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

    std::sort(arr.begin(),arr.end());//sorting the array- on(logn)- ignored as the nlogn+ (n^2)==== n^2

     std::vector<std::vector<int>> uniqueTriplets;
    for(int i=0;i<arr.size()-2;i++){// time complexity is o(n) and thetwo pointer is log(n) so all log(n^2)
        while(arr[i]==arr[i+1]){// till unique of first element is found
            i++;
        }
        int sumRem=sum- arr[i];
        int front=i+1;
        int back=arr.size()-1;

// just use set to store?

        while(front<back){//DO NOT USE FRONT!=BACK- IT CAN SKIP THIS CONDITION AT AT FRONT++ AND BACK--
            int sumOfTwo=arr[front]+arr[back];
            if(sumOfTwo==sumRem){

                uniqueTriplets.push_back({arr[i],arr[front],arr[back]});
                do{
                    front++;
                }while(arr[front]==arr[front-1] && front<back);// do once then increment till unique of 2nd element is found

                do{
                    back--;
                }while(arr[back]==arr[back+1]&& front<back);// do once then decrement till unique of 3rd element isfound
                

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
    



