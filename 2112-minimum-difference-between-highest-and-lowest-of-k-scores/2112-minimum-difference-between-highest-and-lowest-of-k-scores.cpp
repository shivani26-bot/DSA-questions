class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int minm=INT_MAX;
        int maxm=INT_MIN;
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        while(j<n){
         
            if(j-i+1<k) j++;
            else if(j-i+1==k){
              minm=nums[i];
                maxm=nums[j];
                ans=min(ans,(maxm-minm));
              
                i++;
                j++;
            }
        }
        return ans;
    }
};