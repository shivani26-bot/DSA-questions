class Solution {
public:
// int solve(int i,int n,int sum,vector<int>&v, int k){
//     if(i==v.size() || sum==n){
//         if(k>=2) return 1;
//         return 0;
//     }
// int notTake=solve(i+1,n,sum,v,k);
// int take=1;
//   if(sum+v[i]<=n){

//    take= v[i]*solve(i,n,sum+v[i],v,k+1);
//   }

// return max(take,notTake);
// }
//     int integerBreak(int n) {
//     vector<int>v;
//     for(int i=1;i<=n;i++){
//         v.push_back(i);
//     }

//       return solve(0,n,0,v,0);
//     }

int solve(int i,int n){
    if(n==0) return 1;
    if(i==1){
        return 1;
    }

int notTake=solve(i-1,n);
int take=1;
  if(i<=n){
   take= i*solve(i,n-i);
  }

return max(take,notTake);
}
    int integerBreak(int n) {
      return solve(n-1,n);
    }
// dp
// int solve(int i,int n,vector<vector<int>>&dp){
//     if(n==0) return 1;
//     if(i==1){
//         return 1;
//     }
// if(dp[i][n]!=-1) return dp[i][n];
// int notTake=solve(i-1,n,dp);
// int take=1;
//   if(i<=n){
//    take= i*solve(i,n-i,dp);
//   }

// return dp[i][n]=max(take,notTake);
// }
//     int integerBreak(int n) {
//       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//       return solve(n-1,n,dp);
//     }

// int dp[59];
// int solve(int n){
//     if(n==1) return 1;
// if(dp[n]!=-1) return dp[n];
// int ans=INT_MIN;
//     for(int i=1;i<=n-1;i++){
//         int product= i*max(n-i,solve(n-i));
//         ans=max(product,ans);
//     }
//     return dp[n]=ans;
// }
//     int integerBreak(int n) {
//     memset(dp,-1,sizeof(dp));
//       return solve(n);
//     }

// int solve(int n){
// if(n==0) return 1;

// int result=INT_MIN;
//     for(int i=1;i<=n-1;i++){

//        int product=  i* max(n-i, solve(n-i));
//        result=max(result, product);
//     }
//     return result;
// }

//     int integerBreak(int n) {

//       return solve(n);
//     }


// int solve(int n,vector<int>&dp){
// if(n==0) return 1;
// if(dp[n]!=-1) return dp[n];
// int result=INT_MIN;
//     for(int i=1;i<=n-1;i++){

//        int product=  i* max(n-i, solve(n-i,dp));
//        result=max(result, product);
//     }
//     return dp[n]=result;
// }

//     int integerBreak(int n) {
//      vector<int>dp(n+1,-1);
//       return solve(n,dp);
//     }

    // without memoization, for every n we have n-1 options to break into
    // n* n^(n-1) exponential
    // memoization: n*(n-1)
    // n for for loop , n-1 states
};

// num=2 output=1
// num=4 output=4
// 4: 1+1+1+1, 1+2+1, 1+3,3+1,2+2
// num=6 output =9 
// 6: 1+1+1+1+1+1, 1+5, 2+2+2,2+2+1+1, 3+3 ...so on
// num=7, output=12
// 7:4+3
// num=10, output=36
// 10:3+3+4


//               5
//      1,4          2,3         3,2     4,1
// 1,3 2,2 3,1     1,2  2,1     1,1

// 1,4 =4
// 1,1,3 =3
// 1,2,2 =4
// 1,3,1=3

// either i*(n-i) is the best answer or
// i*solve(n-i) is the best answer
// i* max(n-i, solve(n-i))