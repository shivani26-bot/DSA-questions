class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int>mp;//occurence of each number in a window
        // the adjustment k = k + 1 when k is less than the size of the nums array ensures that the sliding window size is at least k.
if(k<n) k=k+1;
else k=n;
        while(j<n){
            mp[nums[j]]++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
             if(mp.size()<k) return true;
             mp[nums[i]]--;
             if(mp[nums[i]]==0) mp.erase(nums[i]);
             i++;
             j++;
          }  
        }
        return false;
    }
};