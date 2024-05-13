class Solution {
public:
// int solve(int index, int buy,vector<int>& prices, int cap){
// if(index==prices.size()) return 0;
// if(cap==0) return 0;


// int profit=0;

//     if(buy==1){
//         profit = max(-prices[index]+solve(index+1,0,prices,cap),0+solve(index+1,1,prices,cap));
//     }
//     else{
//         profit = max(prices[index]+solve(index+1,1, prices,cap-1), 0+solve(index+1,0, prices,cap));
//     }

//     return profit;
// }
    // int maxProfit(int k, vector<int>& prices) {
    //             int n=prices.size();
       
       
    //     return solve(0,1,prices,k); 
    // }

// top down
// int solve(int index, int buy,vector<int>& prices, int cap, vector<vector<vector<int>>>&dp){
// if(index==prices.size()) return 0;
// if(cap==0) return 0;
// if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];

// int profit=0;

//     if(buy==1){
//         profit = max(-prices[index]+solve(index+1,0,prices,cap,dp),0+solve(index+1,1,prices,cap,dp));
//     }
//     else{
//         profit = max(prices[index]+solve(index+1,1, prices,cap-1,dp), 0+solve(index+1,0, prices,cap,dp));
//     }
//     return dp[index][buy][cap]=profit;

// }
    // int maxProfit(int k, vector<int>& prices) {
//                int n=prices.size();
//         // 2 states, index and buy or sell 
//         // cap will be 0 or 1 or 2 transaction remaining 
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
//         return solve(0,1,prices,k,dp);
//     }

// bottom top 
    //    int maxProfit(int k, vector<int>& prices) {
//          int n=prices.size();
//         // 2 states, index and buy or sell 
//         // cap will be 0 or 1 or 2 transaction remaining 
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
//     //    if cap is 0 then index and buy can be anything 1st base case
//     // for(int ind=0;ind<n;ind++){
//     //     for(int buy=0;buy<=1;buy++){
//     //         dp[ind][buy][0]=0;
//     //     }
//     // } 
//     // if index=n then buy and cap can be anything 2nd base case
// //     for(int buy=0;buy<=1;buy++){
// //         for(int cap=0;cap<=2;cap++){
// //  dp[n][buy][cap]=0;
       
// //         }
// //     }
//     // base cases are not necessary because anyways we are initializing the whole matrix with 0
// // for every cap 0 value will be 0 start from cap =1
      
//      for(int index=n-1;index>=0;index--){
//     for(int buy=0;buy<=1;buy++){
//         for(int cap=1;cap<=k;cap++){
//  int profit=0;

//     if(buy==1){
//         profit = max(-prices[index]+dp[index+1][0][cap],0+dp[index+1][1][cap]);
//     }
//     else{
//         profit = max(prices[index]+dp[index+1][1][cap-1], 0+dp[index+1][0][cap]);
//     }
// dp[index][buy][cap]=profit;
// }
//     }
// } 
      
//     return dp[0][1][k]; //initial call
       
  
//     }

// space optimization 
// space optimization
// n*2*3 => 2d dp n* (2*3)
   int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
  
        vector<vector<int>>ahead(2,vector<int>(k+1,0));
         vector<vector<int>>curr(2,vector<int>(k+1,0));
      
     for(int index=n-1;index>=0;index--){
    for(int buy=0;buy<=1;buy++){
        for(int cap=1;cap<=k;cap++){
 int profit=0;

    if(buy==1){
        profit = max(-prices[index]+ahead[0][cap],0+ahead[1][cap]);
    }
    else{
        profit = max(prices[index]+ahead[1][cap-1], 0+ahead[0][cap]);
    }
curr[buy][cap]=profit;
}
ahead=curr;
    }
} 
      
    return ahead[1][k]; //initial call
       
  
    }
};