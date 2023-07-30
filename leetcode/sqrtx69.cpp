//find integer value of the sqrt of x
//using binaary search
//to get log n time complexity
//


class Solution {
public:
    int mySqrt(int x) {
       int ans;
        long long s=0,e=x;
        while(s<=e){//terminates when s>e. this may happen beacuse the exact sqrt may not be found. s=e  is important. it co nverges 
            long long m=s+(e-s)/2;//???prevent overflow if its big??
            if(m*m==x){
                return m;
            }else if(m*m<x){
                ans=m;// ans can be = or < than the actual sqrt
                s=m+1;//check in the bigger half
            }

            else{
                e=m-1;//check in the smaller half
            }
            
        }
        return ans;
        
    }
};


