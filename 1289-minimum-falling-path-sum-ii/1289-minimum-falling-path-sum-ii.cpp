class Solution {
public:
// similar question as ninja training , dp series striver 
// recursion 
// int solve(int curr, int prev, vector<vector<int>>&grid){
//     if(curr==0){
//         int mini=1e8;
//         for(int j=0;j<grid.size();j++){
//             if(j!=prev){
//                 mini=min(mini,grid[curr][j]);
//             }
//         }
//         return mini;
//     }

//     int mini=1e8;
//     for(int j=0;j<grid.size();j++){
//         if(j!=prev){
//             int ans=grid[curr][j] + solve(curr-1,j,grid);
//             mini=min(mini,ans);
//         }
//     }
//     return mini;
// }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         // we will start from last row and at first we have n choices ie n number of columns from where we can start
//         return solve(n-1,n,grid);
//     }

// top down 
// int solve(int curr, int prev, vector<vector<int>>&grid,vector<vector<int>>&dp){
//     if(curr==0){
//         int mini=1e8;
//         for(int j=0;j<grid.size();j++){
//             if(j!=prev){
//                 mini=min(mini,grid[curr][j]);
//             }
//         }
//         return mini;
//     }

// if(dp[curr][prev]!=-1) return dp[curr][prev];
//     int mini=1e8;
//     for(int j=0;j<grid.size();j++){
//         if(j!=prev){
//             int ans=grid[curr][j] + solve(curr-1,j,grid,dp);
//             mini=min(mini,ans);
//         }
//     }
//     return dp[curr][prev]= mini;
// }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         // we will start from last row and at first we have n choices ie n number of columns from where we can start
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         return solve(n-1,n,grid,dp);
//     }

// bottom up 
// int solve(vector<vector<int>>&grid,vector<vector<int>>&dp,int n){

//     for(int i=0;i<=n;i++){
//          int mini=1e8;
//         for(int j=0;j<n;j++){
//             if(j!=i){
//                 mini=min(mini,grid[0][j]);
//             }
//         }
//         dp[0][i]=mini;
//     }

//  for(int day=1;day<n;day++){
//             for(int last=0;last<=n;last++){
//                 int mini=1e8;
//                 for(int curr=0;curr<n;curr++){
//                    if(curr!=last){
//                     mini=min(mini,grid[day][curr]+dp[day-1][curr]);
//                    }
//                 }
//                 dp[day][last]=mini;
//             }
//         }
//         return dp[n-1][n];
// }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         // we will start from last row and at first we have n choices ie n number of columns from where we can start
//         vector<vector<int>>dp(n,vector<int>(n+1,0));
//         return solve(grid,dp,n);
//     }

// space optimize 
int solve(vector<vector<int>>&grid,int n){
vector<int>prev(n+1,0);
    for(int i=0;i<=n;i++){
         int mini=1e8;
        for(int j=0;j<n;j++){
            if(j!=i){
                mini=min(mini,grid[0][j]);
            }
        }
        prev[i]=mini;
    }

 for(int day=1;day<n;day++){
     vector<int>curr(n+1,0);
            for(int last=0;last<=n;last++){
                int mini=1e8;
                for(int curr=0;curr<n;curr++){
                   if(curr!=last){
                    mini=min(mini,grid[day][curr]+prev[curr]);
                   }
                }
                curr[last]=mini;
            }
            prev=curr;
        }
        return prev[n];
}
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        return solve(grid,n);
    }
};