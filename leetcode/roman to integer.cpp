/*Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:*/

/*roman numbers are generally arranged from hight to low. so start from start of the stirng to the end . 
if the character represents a value smaller than the i+1, then substract it. ex IV -- I smaller than V. So reduce I. add V

or else just add it

when checking the last charcter i+1 will cause overflow. so check if i<size()-1 before checkn i+1 condition.
 it will terminate as soon as its false without checkn the other which causes the overflow
*/

class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
     

        std::unordered_map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};         

        for(int i=0;i<s.size();i++){
            if(i<s.size()-1 && mp.at(s[i])<mp.at(s[i+1])){// i<size()-1 is checked and if coni=dition immediately terminates. it doesnt look for the mp.at(s[i+1]) which will cause overflow
                sum-=mp.at(s[i]);
            }
            else{
                sum+=mp.at(s[i]);
            }


        }
        return sum;
    }
};