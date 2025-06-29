class Solution {
public:
// 1 <= coins[i] <= 5000
// int solve(int index, int target,vector<int>& coins ){
//     if(target==0) return 1;//not required
//     if(index==0){
//         if(target%coins[0]==0) return 1;
//         return 0;
//     }

// // if(index==0){
// //         return target%coins[0]==0;
  
// //     }
//     int notTake= solve(index-1, target, coins);
//     int take=0;
//     if(coins[index]<=target) 
//     take= solve(index, target-coins[index], coins);
//     return take+ notTake;
// }
//     int change(int amount, vector<int>& coins) {
//           int n=coins.size();
//          int ans= solve(n-1,amount, coins);

//          return ans;
//     }

    // top down
// int solve(int index, int target,vector<int>& coins,vector<vector<int>>&dp ){
//     //  if(target==0) return 1;//not required
//     if(index==0){
//         if(target%coins[0]==0) return 1;
//         return 0;
//     }
// if(dp[index][target]!=-1) return dp[index][target];
//     int notTake= solve(index-1, target, coins,dp);
//     int take=0;
//     if(coins[index]<=target) 
//     take= solve(index, target-coins[index], coins,dp);
//     return dp[index][target]= take+ notTake;
// }
//     int change(int amount, vector<int>& coins) {
//           int n=coins.size();
//           vector<vector<int>>dp(n, vector<int>(amount+1,-1));
//         return solve(n-1,amount, coins,dp);
        
//     }

// bottom top 

   int change(int amount, vector<int>& coins) {
          int n=coins.size();
          vector<vector<unsigned long long>>dp(n, vector<unsigned long long>(amount+1,0));
            for(int t=0;t<=amount;t++) 
                {
                //   if(t%coins[0]==0) dp[0][t]=1;
                  dp[0][t]=(t%coins[0]==0);
                }

  for(int index=1;index<n;index++){
    for(int t=0;t<=amount;t++){
    unsigned long long notTake= dp[index-1][t];
    unsigned long long take=0;
    if(coins[index]<=t) 
    take= dp[index][t-coins[index]];
   dp[index][t]=take+notTake;
    }
    
  }
  return dp[n-1][amount];
   }
// space optimize
//   int change(int amount, vector<int>& coins) {
//           int n=coins.size();
//           vector<int>prev(amount+1,0);
//            vector<int>curr(amount+1,0);
//             for(int t=0;t<=amount;t++) 
//                 {
//                 //   if(t%coins[0]==0) dp[0][t]=1;
//                   prev[t]=(t%coins[0]==0);
//                 }

//   for(int index=1;index<n;index++){
//     for(int t=0;t<=amount;t++){
//     int notTake= prev[t];
//     int take=0;
//     if(coins[index]<=t) 
//     take= curr[t-coins[index]];
//   curr[t]=take+notTake;
//     }
//     prev=curr;
//   }
  
//          int ans= prev[amount];
       
//          return ans;
//     }

};