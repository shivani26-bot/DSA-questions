class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // [9,9,9,1,2,3]
        // 3
        int n=nums.size();
        int i=0,j=0;
        long long maxAns=0;
        long long sum=0;
        unordered_map<char,int>mp;
        while(j<n){
            sum+=nums[j];
            mp[nums[j]]++;          
            if(j-i+1<k) j++;
            else {
                if(mp.size()==k)
                maxAns=max(maxAns,sum);
                mp[nums[i]]--;
                  if(mp[nums[i]]==0) mp.erase(nums[i]);
                sum-=nums[i];
              
                i++;
j++;
            }
        }
        return maxAns;
    }
};