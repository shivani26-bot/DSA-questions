class Solution {
public:
// int f(int n, vector<int>&nums){
// if(n<0) return 0;
//     int take=nums[n]+f(n-2,nums);
//     int notTake= f(n-1,nums);
//     return max(take,notTake);
// }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         return f(n-1,nums);
//     }
// int f(int n, vector<int>&nums,vector<int>&dp){
// if(n<0) return 0;
// if(dp[n]!=-1) return dp[n];
//     int take=nums[n]+f(n-2,nums,dp);
//     int notTake= f(n-1,nums,dp);
//     return dp[n]=max(take,notTake);
// }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n+1,-1);
//         return f(n-1,nums,dp);
//     }


    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n,0);
    //      dp[0]=nums[0];
    //      int take,notTake;
    //     for(int i=1;i<n;i++){
    //          take=nums[i];  //[1,1]
    //     if(i-2>=0)
    //       take= nums[i]+dp[i-2];
    //       notTake=dp[i-1];
    //       dp[i]= max(take,notTake);
    //     }
    //     return dp[n-1];
    // }

      int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
         int prev=nums[0];
         int prev2=0;
         int take,notTake;
        for(int i=1;i<n;i++){
             take=nums[i];  //[1,1]
        if(i-2>=0)
          take= nums[i]+prev2;
          notTake=prev;
          int curr= max(take,notTake);
          prev2=prev;
          prev=curr;
        }
        return prev;
    }
};