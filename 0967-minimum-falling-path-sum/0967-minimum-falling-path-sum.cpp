class Solution {
public:
// recursion 
// int solve(int i,int j,vector<vector<int>>& matrix,int m,int n){
//     if(i==m-1) return matrix[i][j];
//    int leftdg=INT_MAX, rightdg=INT_MAX;

//     int down= matrix[i][j]+ solve(i+1,j,matrix,m,n);
//     if(j>0)
//      leftdg= matrix[i][j]+solve(i+1,j-1,matrix,m,n);
//     if(j<n-1)
//      rightdg= matrix[i][j]+solve(i+1,j+1,matrix,m,n);

//     return min(leftdg, min(down,rightdg));
// }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         int minm=INT_MAX;
//         for(int j=0;j<n;j++){
//            minm=min(minm,solve(0,j,matrix,m,n));
//         }
//         return minm;
//     }

// topdown
// int solve(int i,int j,vector<vector<int>>& matrix,int m,int n,vector<vector<int>>&dp){
//     if(i==m-1) return matrix[i][j];
//    int leftdg=INT_MAX, rightdg=INT_MAX;
// if(dp[i][j]!=INT_MAX) return dp[i][j];
//     int down= matrix[i][j]+ solve(i+1,j,matrix,m,n,dp);
//     if(j>0)
//      leftdg= matrix[i][j]+solve(i+1,j-1,matrix,m,n,dp);
//     if(j<n-1)
//      rightdg= matrix[i][j]+solve(i+1,j+1,matrix,m,n,dp);

//     return dp[i][j]=min(leftdg, min(down,rightdg));
// }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
//         int minm=INT_MAX;
//         for(int j=0;j<n;j++){
//            minm=min(minm,solve(0,j,matrix,m,n,dp));
//         }
//         return minm;
//     }

//tabulation
// int solve(vector<vector<int>>& matrix,int m,int n,vector<vector<int>>&dp){
   
//     // base case
//     for(int j=0;j<n;j++){
//         dp[n-1][j]=matrix[n-1][j];
//     }
   
// for(int i=m-2;i>=0;i--){
    
//     for(int j=0;j<n;j++){
//     int down= matrix[i][j]+ dp[i+1][j];
//     int leftdg=matrix[i][j], rightdg=matrix[i][j];
    
//     if(j>0)
//      leftdg+=dp[i+1][j-1];
//      else
//         leftdg+=1e9;
     
//     if(j<n-1)
//      rightdg+=dp[i+1][j+1];
//      else rightdg+=1e9;
   
//    dp[i][j]=min(leftdg, min(down,rightdg));
//     }
   
// }
//     int minm=INT_MAX;
//     for(int j=0;j<n;j++){
//         minm=min(minm,dp[0][j]);
//     }
//     return minm;
// }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,0));
//        return solve(matrix,m,n,dp);
//     }

// space optimization 
int solve(vector<vector<int>>& matrix,int m,int n,vector<vector<int>>&dp){
   
    // base case
    vector<int>next(n,0);
    vector<int>curr(n,0);
    for(int j=0;j<n;j++){
        next[j]=matrix[n-1][j];
    }
   
for(int i=m-2;i>=0;i--){
    
    for(int j=0;j<n;j++){
    int down= matrix[i][j]+next[j];
    int leftdg=matrix[i][j], rightdg=matrix[i][j];
    
    if(j>0)
     leftdg+=next[j-1];
     else
        leftdg+=1e9;
     
    if(j<n-1)
     rightdg+=next[j+1];
     else rightdg+=1e9;
   
   curr[j]=min(leftdg, min(down,rightdg));
    }
    next=curr;
   
}
    int minm=INT_MAX;
    for(int j=0;j<n;j++){
        minm=min(minm,next[j]);
    }
    return minm;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
       return solve(matrix,m,n,dp);
    }
};