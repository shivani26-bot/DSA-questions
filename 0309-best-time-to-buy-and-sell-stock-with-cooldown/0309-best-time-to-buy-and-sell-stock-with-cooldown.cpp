class Solution {
public:
// int solve(int index, int buy,vector<int>& prices){
// if(index>=prices.size()) return 0;


// int profit=0;

//     if(buy==1){
//         profit = max(-prices[index]+solve(index+1,0,prices),0+solve(index+1,1,prices));
//     }
//     else {
        
//         profit = max(prices[index]+solve(index+2,1, prices), 0+solve(index+1,0, prices));
//     }
//     return profit;
// }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
    
//         return solve(0,1,prices);  
//     }

    // top down 
//     int solve(int index, int buy,vector<int>& prices, vector<vector<int>>&dp){
// if(index>=prices.size()) return 0;

// if(dp[index][buy]!=-1) return dp[index][buy];

// int profit=0;

//     if(buy==1){
//         profit = max(-prices[index]+solve(index+1,0,prices,dp),0+solve(index+1,1,prices,dp));
//     }
//     else{
//         profit = max(prices[index]+solve(index+2,1, prices,dp), 0+solve(index+1,0, prices,dp));
//     }
//     return dp[index][buy]=profit;
// }

// int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         // 2 states, index and buy or sell 
//         vector<vector<int>>dp(n,vector<int>(2,-1));
//         return solve(0,1,prices,dp);
//     }

// bottom top 


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // 2 states, index and buy or sell 
        vector<vector<int>>dp(n+2,vector<int>(2,0));
// n+2 because if i=n-1 then i+2 will cross the boundary if we take n or n+1 
for(int index=n-1;index>=0;index--){
    for(int buy=0;buy<=1;buy++){
 int profit=0;

    if(buy){
        profit = max(-prices[index]+dp[index+1][0],0+dp[index+1][1]);
    }
    else{
        profit = max(prices[index]+dp[index+2][1], 0+dp[index+1][0]);
    }
dp[index][buy]=profit;
}
} 
      
    return dp[0][1];
    }

// space optimization
//   we require 3 different rows becuase we have index+2 and index+1 and curr 
};