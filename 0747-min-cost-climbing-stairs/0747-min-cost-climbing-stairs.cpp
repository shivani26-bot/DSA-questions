class Solution {
public:
// int solve(int n, vector<int>&cost){
//     if(n==0) return cost[0];
//     if(n==1) return cost[1];
//     int ans= cost[n]+min(solve(n-1,cost), solve(n-2,cost));
//     return ans;
// }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         int ans=min(solve(n-1,cost),solve(n-2,cost));
//         return ans;
//     }
// int solve(int i, vector<int>&cost,int n){
//     if(i>=n) return 0;
//     if(i==n-1) return cost[i];
//     int ans= cost[i]+min(solve(i+1,cost,n), solve(i+2,cost,n));
//     return ans;
// }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         int ans=min(solve(0,cost,n),solve(1,cost,n));
//         return ans;
//     }
// top down
// int solve(int i, vector<int>&cost,int n,vector<int>&dp){
//     if(i>=n) return 0;
//     if(i==n-1) return cost[i];
//     if(dp[i]!=-1) return dp[i];
//     dp[i]= cost[i]+min(solve(i+1,cost,n,dp), solve(i+2,cost,n,dp));
//     return dp[i];
// }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int>dp(n+1,-1);
//         int ans=min(solve(0,cost,n,dp),solve(1,cost,n,dp));
//         return ans;
//     }
    // top down
    int solve(int n, vector<int>&cost,vector<int>&dp){
    if(n==0) return cost[0];
    if(n==1) return cost[1];
    if(dp[n]!=-1) return dp[n];
    dp[n]= cost[n]+min(solve(n-1,cost,dp), solve(n-2,cost,dp));
    return dp[n];
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans=min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        return ans;
    }
};