class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        unordered_set<char>st;
        int maxWindow=0;
        while(j<n){
           st.insert(s[j]);
            if(j-i+1>st.size()){
while(st.size()<j-i+1){
st.erase(s[i]);
i++;
}
j++;
            }
            else if(j-i+1==st.size()){
                maxWindow=max(maxWindow,j-i+1);
                j++;
            }
        }
        return maxWindow;
    }
};