class Solution {
public:
// s="100010000111"
// 10 00 10 00 01 11
// 3 minimum changes
// number of partition doesn't effect the answer 
    int minChanges(string s) {
        int n=s.length();
        int changes=0;
        for(int i=0;i<n;i+=2){
            if(s[i]!=s[i+1]) changes++;
        }
        return changes;
    }
};