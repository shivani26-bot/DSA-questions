class Solution {
public:

int fib(int n, vector<int>&dp){
if(n<=1) return n;
      if(n==2) return 1;
      if(dp[n]!=-1) return dp[n];

      dp[n]= fib(n-1,dp)+fib(n-2,dp)+fib(n-3,dp);
      return dp[n];
}
    int tribonacci(int n) {
        //recursion
    //   if(n<=1) return n;
    //   if(n==2) return 1;

    //   return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);

      //dp
     vector<int>dp(n+1,-1);

    return fib(n, dp);
      

    }
};