class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_set<int>st(spaces.begin(),spaces.end());//o(mlogm)
        int n=s.length();
        int m=spaces.size();
        // vector<char>ans(n+m);
        string ans;
        for(int i=0;i<n;i++){//o(n)
            if(st.find(i)!=st.end()){//o(nlogm)
                // ans.push_back(' ');
                ans+=' ';
            }
            // ans.push_back(s[i]);
            ans+=s[i];
        }
        return ans;
    }
};