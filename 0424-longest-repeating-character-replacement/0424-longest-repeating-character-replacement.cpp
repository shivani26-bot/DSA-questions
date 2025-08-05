class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0,j=0;
        unordered_map<char,int>mp;
int maxWin=INT_MIN;
int maxRepeatCharInWin=0;
        while(j<n){
            mp[s[j]]++;
            int currLen=j-i+1;
            maxRepeatCharInWin=max(mp[s[j]],maxRepeatCharInWin);
            if(abs(currLen-maxRepeatCharInWin)>k){
                mp[s[i]]--;
                i++;
            }
            currLen=j-i+1;
            maxWin=max(maxWin,currLen);
            j++;
        }
        return maxWin;
    }
};