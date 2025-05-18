class Solution {
public:
int solve(int n, vector<int>&dp){
    if(n<=0) return 0;

    if(dp[n]!=-1) return dp[n];
    int ans=n; //tells max answer can be n ie. any number can be formed by adding squar of 1 n times
    // for ex: 12, 1^2+1^2.....12times
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+solve(n-i*i,dp));
    }
    return dp[n]=ans;
}
    int numSquares(int n) {
        // greedy will not work, because if in first step we take the largest perfect square
        // and subtract it from n then it is possible that we will have to take more number of steps to reach 0
        // recursion 
    //     if(n<=0) return 0;
    //   int ans=n;
    //     for(int i=1;i*i<=n;i++){
    //         ans=min(ans,1+numSquares(n-i*i));
    //     }
    //     return ans;

    // top down 
    // vector<int>dp(n+1,-1);
    // return solve(n,dp);

    // bottom top 
       vector<int>dp(n+1,0);
   for(int i=1;i<=n;i++){
    dp[i]=i;
    // for every number max answer can be equal to number it self ie 1^2+1^2+...i times 
    // for every number store the ans in tabulation dp 
    for(int j=1;j*j<=i;j++){
  dp[i]=min(dp[i],1+dp[i-(j*j)]);
    }
   }
   return dp[n];

//    Lagrange 4 square theorem
// every natural number can be represented as the sum of 4 integer square 
// p=a0^2+a1^2+a2^2+a3^2 where a0,a1,a2,a3 are 4 integers 
// 3=1^2+1^2+1^2+0^2
// 31=5^2+2^2+1^2+1^2
// lagranges 4 square thorem, sets an upper bound that max answer can be 4, but doesn't give if answer can be 1,2,3 
// ans=1 if number is perfect square itself

    }



};