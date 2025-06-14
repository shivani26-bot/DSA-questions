class Solution {
public:
// int solve(int i,int j,vector<vector<int>>& matrix,int m,int n){
//     if(i==m-1) return matrix[i][j];
//     int maxPoints=INT_MIN;
//  for(int k=0;k<n;k++){
//     int points=matrix[i][j]+solve(i+1,k,matrix,m,n)-abs(j-k);
//     maxPoints=max(maxPoints,points);
//  }

//     return maxPoints;
// }
//     long long maxPoints(vector<vector<int>>& matrix) {
//         // version of minimum falling path sum 
//                 int m=matrix.size();
//         int n=matrix[0].size();
//         int maxm=INT_MIN;
//         for(int j=0;j<n;j++){
//            maxm=max(maxm,solve(0,j,matrix,m,n));
//         }
//         return maxm;
//     }


// long long solve(int i,int j,vector<vector<int>>& matrix,int m,int n, vector<vector<long long>>&dp){
//     if(i==m-1) return matrix[i][j];
//     if(dp[i][j]!=-1) return dp[i][j];
//     long long maxPoints=0;
//  for(int k=0;k<n;k++){
//     long long points=matrix[i][j]+solve(i+1,k,matrix,m,n,dp)-abs(j-k);
//     maxPoints=max(maxPoints,points);
//  }
//     return dp[i][j]=maxPoints;
// }


//     long long maxPoints(vector<vector<int>>& matrix) {
//         // version of minimum falling path sum 
//                 int m=matrix.size();
//         int n=matrix[0].size();
//         long long maxm=0;
//         vector<vector<long long>>dp(m,vector<long long>(n,-1));
//         for(int j=0;j<n;j++){
//            maxm=max(maxm,solve(0,j,matrix,m,n,dp));
//         }
//         return maxm;
//     }


// go from last row to first row for bottom top 
    // long long maxPoints(vector<vector<int>>& matrix) {
    //     // version of minimum falling path sum 
    //             int m=matrix.size();
    //     int n=matrix[0].size();
    //     long long maxm=0;
    //     vector<vector<long long>>dp(m,vector<long long>(n,0));
        
    //     for(int j=0;j<n;j++){
    //       dp[m-1][j]=matrix[m-1][j];
    //     }


    //     for (int i = m - 2; i >= 0; i--) {
    //     vector<long long> leftMax(n, 0), rightMax(n, 0);

    //     // Calculate the max from the left side
    //     leftMax[0] = dp[i + 1][0];
    //     for (int j = 1; j < n; j++) {
    //         leftMax[j] = max(leftMax[j - 1] - 1, dp[i + 1][j]);
    //     }

    //     // Calculate the max from the right side
    //     rightMax[n - 1] = dp[i + 1][n - 1];
    //     for (int j = n - 2; j >= 0; j--) {
    //         rightMax[j] = max(rightMax[j + 1] - 1, dp[i + 1][j]);
    //     }

    //     // Fill the dp table for the current row
    //     for (int j = 0; j < n; j++) {
    //         dp[i][j] = matrix[i][j] + max(leftMax[j], rightMax[j]);
    //     }
    // }

    // // The answer is the maximum value in the first row
    // long long result = dp[0][0];
    // for (int j = 1; j < n; j++) {
    //     result = max(result, dp[0][j]);
    // }

    // return result;
    // }


    long long maxPoints(vector<vector<int>>& matrix) {
        // version of minimum falling path sum 
                int m=matrix.size();
        int n=matrix[0].size();
        long long maxm=0;
        // vector<vector<long long>>dp(m,vector<long long>(n,0));
        vector<long long>next(n,0);
        for(int j=0;j<n;j++){
          next[j]=matrix[m-1][j];
        }

        
        for (int i = m - 2; i >= 0; i--) {
            vector<long long>curr(n,0);
        vector<long long> leftMax(n, 0), rightMax(n, 0);

        // Calculate the max from the left side
        leftMax[0] = next[0];
        for (int j = 1; j < n; j++) {
            leftMax[j] = max(leftMax[j - 1] - 1, next[j]);
        }

        // Calculate the max from the right side
        rightMax[n - 1] = next[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j + 1] - 1, next[j]);
        }

        // Fill the dp table for the current row
        for (int j = 0; j < n; j++) {
            curr[j] = matrix[i][j] + max(leftMax[j], rightMax[j]);
        }
        next=curr;
    }

    // The answer is the maximum value in the first row
    long long result = next[0];
    for (int j = 1; j < n; j++) {
        result = max(result, next[j]);
    }

    return result;
    }
};