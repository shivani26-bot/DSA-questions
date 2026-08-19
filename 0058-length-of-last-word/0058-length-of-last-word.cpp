class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        int count=0;
        if(n==1) return 1;
        while(s[i]==' ') i--;
        while( i>=0 && s[i]!=' ' ){
            count++;
            i--;
        }
        return count;


        // "a"
        // "a "
        // "day"
    }
};