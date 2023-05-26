
//Write a function to find the longest common prefix string amongst an array of strings.

//If there is no common prefix, return an empty string 

//Input: strs = ["flower","flow","flight"]
//Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string minstr="";
          for(std::string s: strs){// find the smallest string
              if(minstr.size()<s.size()){
                  minstr=s;
              }
              
          } 
          int count=0;  
        for(int i=0;i<minstr.size();i++){ //iterate through the characters
             for(int j=1;j<strs.size();j++){
                 if(minstr.at(i)!=strs.at(j).at(i)){
                     return minstr.substr(0,count);
                 }
                 
                 
             }
             count++;
        }
        return minstr.substr(0,count);
        
    }
};