class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=n-1 , j=m-1;
        if(n>m) return false;
        while(i>=0 && j>=0){
            if(s[i]==t[j]){
                i--;
                j--;
            }
            else if(s[i]!=t[j]){
                j--;
            }
        }

//         edge case: 
//         s =
// "b"
// t =
// "c"
// output: false;
        // if(i>0) return false;
        // return true;
           return i<0;
    }
};