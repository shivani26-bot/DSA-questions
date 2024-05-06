class Solution {
public:
// int solve(int index, int target,vector<int>& coins ){
//     if(index==0){
//         if(target%coins[0]==0) return target/coins[0];
//         return 1e9;
//     }

//     int notTake= solve(index-1, target, coins);
//     int take=INT_MAX;
//     if(coins[index]<=target) 
//     take= 1+solve(index, target-coins[index], coins);
//     return min(take, notTake);
// }
//     int coinChange(vector<int>& coins, int amount) {
//           int n=coins.size();
//          int ans= solve(n-1,amount, coins);
//          if(ans>=1e9) return -1;
//          return ans;
//     }

// top down
// int solve(int index, int target,vector<int>& coins,vector<vector<int>>&dp ){
//     if(index==0){
//         if(target%coins[0]==0) return target/coins[0];
//         return 1e9;
//     }
// if(dp[index][target]!=-1) return dp[index][target];
//     int notTake= solve(index-1, target, coins,dp);
//     int take=INT_MAX;
//     if(coins[index]<=target) 
//     take= 1+solve(index, target-coins[index], coins,dp);
//     return dp[index][target]=min(take, notTake);
// }
//     int coinChange(vector<int>& coins, int amount) {
//           int n=coins.size();
//           vector<vector<int>>dp(n, vector<int>(amount+1,-1));
//          int ans= solve(n-1,amount, coins,dp);
//          if(ans>=1e9) return -1;
//          return ans;
//     }
// bottom top 

//     int coinChange(vector<int>& coins, int amount) {
//           int n=coins.size();
//           vector<vector<int>>dp(n, vector<int>(amount+1,0));
//             for(int t=0;t<=amount;t++) 
//     {
//     if(t%coins[0]==0) dp[0][t]=t/coins[0];
//     else dp[0][t]=1e9;
//     }

//   for(int index=1;index<n;index++){
//     for(int t=0;t<=amount;t++){
//     int notTake= dp[index-1][t];
//     int take=INT_MAX;
//     if(coins[index]<=t) 
//     take= 1+dp[index][t-coins[index]];
//    dp[index][t]=min(take, notTake);
//     }
//   }
  
//          int ans= dp[n-1][amount];
//          if(ans>=1e9) return -1;
//          return ans;
//     }

// space optimization 
    int coinChange(vector<int>& coins, int amount) {
          int n=coins.size();
          vector<int>prev(amount+1,0);
          vector<int>curr(amount+1,0);
            for(int t=0;t<=amount;t++) 
    {
    if(t%coins[0]==0) prev[t]=t/coins[0];
    else prev[t]=1e9;
    }

  for(int index=1;index<n;index++){
    for(int t=0;t<=amount;t++){
    int notTake= prev[t];
    int take=INT_MAX;
    if(coins[index]<=t) 
    take= 1+curr[t-coins[index]];
   curr[t]=min(take, notTake);
    }
    prev=curr;
  }
  
         int ans= prev[amount];
         if(ans>=1e9) return -1;
         return ans;
    }

};