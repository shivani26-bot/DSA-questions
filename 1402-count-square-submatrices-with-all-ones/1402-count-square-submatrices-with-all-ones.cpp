// class Solution {
// public:
// int solve(int i,int j, vector<vector<int>>& matrix){
//       int m=matrix.size();
//       int n=matrix[0].size();
//       if(i>=m || j>=n) return 0;

//       if(matrix[i][j]==0) return 0;

//       int right= solve(i,j+1,matrix);
//       int bottom= solve(i+1, j,matrix);
//       int diagonal= solve(i+1, j+1, matrix);
//       return 1+min(right,min(bottom,diagonal));
// }

//     int countSquares(vector<vector<int>>& matrix) {
//         // 1x1
//         // 1
//          // increase one in horizontal vertical and diagonal direction
//         // to achieve next square.
//         // 2x2 
//         // 1 1
//         // 1 1
//          // increase one in horizontal vertical and diagonal direction
//         // to achieve next square.
//         // 3x3
//         // 1 1 1
//         // 1 1 1
//         // 1 1 1
//         // for every check check in the right, bottom and diagonal direction 
//     //    don't consider duplicate squares
//     // for 3x3 matrix when we are at (0,0)
//     // if we check in right we have 2 1's, in bottom we have 2 1's and in diagonal we have
//     // 2 1's
//     // hence 1+min(2,2,2)=3, 1 is for 1 at current cell (0,0)
//     // 3 indicates that 3x3 square matrix can be build, hence 2x2 and 1x1 can also be build
//     // starting from the current cell
//     // call recursion for all the three directions: 
//     // base condition: if(i>=m || j>=n) return 0;
//     // int right= solve(i, j+1, grid);
//     // int diagonal= solve(i+1, j+1, grid);
//     // int bottom= solve(i+1, j, grid);
//     // return 1+min(right, diagonal ,bottom )
//       int m=matrix.size();
//       int n=matrix[0].size();
//     int result=0;
//     for(int i=0;i<m;i++){ o(m*n)
//         for(int j=0;j<n;j++){
//               if(matrix[i][j]==1){
//                 result+=solve(i,j,matrix);
//               }
//         }
//     }
//    return result;
//     }

// top down 
// time: o(m*n)
// space: o(m*n)
// int solve(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>&dp){
//       int m=matrix.size();
//       int n=matrix[0].size();
//       if(i>=m || j>=n) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//       if(matrix[i][j]==0) return 0;

//       int right= solve(i,j+1,matrix,dp);
//       int bottom= solve(i+1, j,matrix,dp);
//       int diagonal= solve(i+1, j+1, matrix,dp);
//       return dp[i][j]=1+min(right,min(bottom,diagonal));
// }

//     int countSquares(vector<vector<int>>& matrix) {
     
//       int m=matrix.size();
//       int n=matrix[0].size();
//       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//     int result=0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//               if(matrix[i][j]==1){
//                 result+=solve(i,j,matrix,dp);
//               }
//         }
//     }
//    return result;
//     }

// bottom top 
// int solve(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>&dp){
//       int m=matrix.size();
//       int n=matrix[0].size();
//       if(matrix[i][j]==0) return 0;

//       int right= dp[i][j+1];
//       int bottom= dp[i+1][j];
//       int diagonal= dp[i+1][j+1];
//       return dp[i][j]=1+min({right,bottom,diagonal});
// }

//     int countSquares(vector<vector<int>>& matrix) {
     
//       int m=matrix.size();
//       int n=matrix[0].size();
//       vector<vector<int>>dp(m+1,vector<int>(n+1,0));
//     int result=0;
//     for(int i=m-1;i>=0;i--){
//         for(int j=n-1;j>=0;j--){
//               if(matrix[i][j]==1){
//                 result+=solve(i,j,matrix,dp);
//               }
//         }
//     }
//    return result;
//     }
// };



class Solution {
public:
// for square problems use tabulation 
// for every element in the matrix check in how many squares that element
// is the right bottom 
// 1 1 1        1 1 1
// 1 1 1        1 2 2
// 1 1 1        1 2 3   sum all the elements in the matrix
//  first row and column will be as it is because they themselves are the right bottom 
// ex: 1 1 1 1             1 1 1 1
//     1 1 1 1    =>       1 2 2 2
//     1 1 1 1             1 2 3 3

// 1 1 0          1 1 0
// 1 1 1   =>     1 2 1 
// 1 1 0          1 2 0
// dp[i][j]=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) 

    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
        for(int i=0;i<n;i++) dp[i][0]=matrix[i][0];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
if(matrix[i][j]==0) dp[i][j]=0;
else{
    dp[i][j]=1+ min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) ;
}
            }
            
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};
