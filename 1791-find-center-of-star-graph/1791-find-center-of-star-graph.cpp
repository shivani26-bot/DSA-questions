class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        for(auto it: edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        int n= mp.size();
        int ans=0;
        for(auto it: mp){
            if(it.second==n-1) {
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};