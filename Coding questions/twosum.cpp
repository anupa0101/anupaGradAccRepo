
#include<iostream>
#include<conio.h>
#include<unordered_map>
#include<unordered_set>
#include<iterator>
#include<vector>

//find the pairs that add to a sum.  Only unique

//two methods
//hash set and hash map
//hash set method makes sense. if index needs to be returned use hash map
//o(n) time complexity

//ELEMENT IS THE KEY, AND INDEX IS THE VALUE.

int main(){
    int sum=8;


    std::vector<int> num_arr={1,3,2,6,4,5,5,3,5,4,4};
    std::unordered_map<int,int> mp; //element is the key and index is the value
    for(int i=0;i<num_arr.size();i++){
            if(mp.find(num_arr[i])==mp.end()){// not in the map(adds all the unique ones)
                mp[num_arr[i]]=i; //creates and adds to the map (ACTUALLY this alone will also work without if block. when there are duplicates. the latest index will get aassigned)
               //after adding check if complement exists
                if(mp.find(sum-num_arr[i])!=mp.end() && mp.at(sum-num_arr[i])!=i) // check if the complement of it is avaiable. and also check if the complement isnt itself.(same index as itself) like if 4, 4
                    {
                    std::cout<<num_arr[mp.at(sum-num_arr[i])]<< num_arr[mp.at(num_arr[i])]<< std::endl;
                    }
                  
            }

    }

    //can do the above in the below way too. first check if the current element is unavialable in the set. then check if its complement is there and print it if present.
    //then add the element to the set. no need to worry abt itself being considered as a solutiion 4-4 instance

    // but what abt 4+4? somaybe use maps and .....or add a special clause when st.find(num_arr[i])!=st.end() && num_arr[i]num-num_arr[i]??????????????????
    std::unordered_set<int> st; //
        for(int i=0;i<num_arr.size();i++){
            if(st.find(num_arr[i])==st.end()){//current element isnt in the set
                if(st.find(sum-num_arr[i])!=st.end()){//found the complement in the set. do it before adding the current element to the set because then it might find itself like 4,4
                    std::cout<<sum-num_arr[i]<<num_arr[i]<< std::endl;
                }
              st.insert(num_arr[i]);//add the current element to the set
            }
        }


    return 0;
}