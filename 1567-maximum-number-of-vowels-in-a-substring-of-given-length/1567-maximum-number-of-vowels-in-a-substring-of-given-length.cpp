class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0,j=0;
        unordered_set<char>st={'a','e','i','o','u'};
        int ans=0,countVowel=0;
        while(j<n){
            if(st.count(s[j])) countVowel++;//counts vowel in window
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                ans= max(ans,countVowel);
                if(st.count(s[i])) countVowel--;
                if(countVowel<0) countVowel=0;
                i++;
                j++;
            }
        }
        return ans;
    }
};