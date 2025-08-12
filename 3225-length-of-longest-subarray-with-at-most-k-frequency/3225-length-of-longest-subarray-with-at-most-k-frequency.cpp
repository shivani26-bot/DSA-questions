class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int maxWindow=INT_MIN;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]<=k){
                //if current element frequency is <=k
                //possible window
                maxWindow=max(maxWindow,j-i+1);
                j++;
            }
            else{
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
                j++;
            }
        }
        return maxWindow;
    }
};