class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     int n=nums.size();
     mp[0]=-1;
       int prefixSum=0;
     for(int i=0;i<n;i++){
prefixSum= (prefixSum +nums[i])%k;
if(mp.find(prefixSum)!=mp.end()){
    if(i-mp[prefixSum]>=2) return true;
}
else
mp[prefixSum]=i;
       
     }
     return false;
    }
};