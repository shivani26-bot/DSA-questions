class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        // long long int totalSum=0;
        // for(int i=0;i<n;i++){
        //     totalSum+=nums[i];
        // }
        vector<long long>prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
          prefixSum[i]=nums[i]+prefixSum[i-1];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
             long long curr_sum=prefixSum[i];
             long long remain_sum= prefixSum[n-1]-prefixSum[i];
             if(curr_sum>=remain_sum) count++;
        }
        return count;
    }
};