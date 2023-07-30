#include<iostream>
#include<conio.h>
#include<vector>
#include<array>

int main(){

    int arr[]={1,2,3,4,5,6};
    std::vector<float> v={1,2,3,4,5,6};
    std::array<int,6> ar={1,2,3,4,5,6};

    for(const int& n:arr){     //DONT DO THIS INSIDE A FUNCTION THAT TAKES IN A ARRAY ARGUMENT. ITS A POINTER SO CANT ITERATE LIKE THIS
        std::cout<<n<<"\t";
    }
    std::cout<<std::endl;

    for(float n:v){
        std::cout<<n<<"\t";
    }
    std::cout<<std::endl;    

    for(int n:ar){
        std::cout<<n<<"\t";
    }
    std::cout<<std::endl;

    return 0;
}