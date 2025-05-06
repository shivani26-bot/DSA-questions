// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, h=n;
        int result=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(isBadVersion(m)){
           result=m;
           h=m-1;
            }
            else{
                l=m+1;
            }
    
        }
        return result;
    }
};