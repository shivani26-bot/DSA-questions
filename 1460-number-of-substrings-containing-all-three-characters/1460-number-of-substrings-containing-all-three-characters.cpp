class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int i=0,j=0;
        int countSubstr=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;

            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                // For each valid window from [i, j], all substrings that start at position i and end at or after position j will also be valid. There are len(s) - j such substrings.
                countSubstr+=(n-j);
                mp[s[i]]--;
                i++;
            }
           
j++;
        }
        return countSubstr;
    }
};