class Solution {
public:
int solve(int n,vector<int>&nums,int index,vector<int>&dp){
     if(index>=n) return 0;
     if(dp[index]!=-1) return dp[index];
     int include=solve(n,nums,index+2,dp)+ nums[index];
     int exclude= solve(n,nums,index+1,dp);
   dp[index]=max(include,exclude);
   return dp[index];
}
    int rob(vector<int>& nums) {
       int n = nums.size();
    if (n == 1)
        return nums[0];
    
    vector<int> dp(n + 1, -1);
    int x = solve( n - 1,nums, 0, dp);
    
    fill(dp.begin(), dp.end(), -1);
    int y = solve(n,nums, 1,  dp);
    
    return max(x, y);
    }


// int solve(vector<int>& nums, int idx, int n, vector<int>& dp) {
//     if (idx >= n) {
//         return 0;
//     }
//     if (dp[idx] != -1) {
//         return dp[idx];
//     }
//     int include= solve(nums, idx + 2, n, dp)+nums[idx] ;
//     int exclude=solve(nums, idx + 1, n, dp);
//     dp[idx] = max(include, exclude);
//     return dp[idx];
// }
// int rob(vector<int>& nums) {
//     int n = nums.size();
//     if (n == 1)
//         return nums[0];
    
//     vector<int> dp(n + 1, -1);
//     int x = solve(nums, 0, n - 1, dp);
    
//     fill(dp.begin(), dp.end(), -1);
//     int y = solve(nums, 1, n, dp);
    
//     return max(x, y);
// }

};