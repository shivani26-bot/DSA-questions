class Solution {
public:
// int solve(int i,int j, vector<vector<char>>& matrix){
//       int m=matrix.size();
//       int n=matrix[0].size();
//       if(i>=m || j>=n) return 0;

//       if(matrix[i][j]=='0') return 0;

//       int right= solve(i,j+1,matrix);
//       int bottom= solve(i+1, j,matrix);
//       int diagonal= solve(i+1, j+1, matrix);
//       return 1+min(right,min(bottom,diagonal));
// }
//     int maximalSquare(vector<vector<char>>& matrix) {
//               int m=matrix.size();
//       int n=matrix[0].size();
  
//     int maxResult=0;
   
//     for(int i=0;i<m;i++){ //o(m*n)
      
//         for(int j=0;j<n;j++){
    
//               if(matrix[i][j]=='1'){   
//                  maxResult= max(maxResult,solve(i,j,matrix));
//               }
             
//         }
        
//     }
//    return maxResult*maxResult;
//     }

// int solve(int i,int j, vector<vector<char>>& matrix, vector<vector<int>>&dp){
//       int m=matrix.size();
//       int n=matrix[0].size();
//       if(i>=m || j>=n) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//       if(matrix[i][j]=='0') return 0;

//       int right= solve(i,j+1,matrix,dp);
//       int bottom= solve(i+1, j,matrix,dp);
//       int diagonal= solve(i+1, j+1, matrix,dp);
//       return dp[i][j]=1+min(right,min(bottom,diagonal));
// }

//     int maximalSquare(vector<vector<char>>& matrix) {
     
//       int m=matrix.size();
//       int n=matrix[0].size();
//       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//     int result=0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//               if(matrix[i][j]=='1'){
//                 result=max(result,solve(i,j,matrix,dp));
//               }
//         }
//     }
//    return result*result;
//     }

int solve(int i,int j, vector<vector<char>>& matrix, vector<vector<int>>&dp){
      int m=matrix.size();
      int n=matrix[0].size();
      if(matrix[i][j]=='0') return 0;

      int right= dp[i][j+1];
      int bottom= dp[i+1][j];
      int diagonal= dp[i+1][j+1];
      return dp[i][j]=1+min({right,bottom,diagonal});
}

    int maximalSquare(vector<vector<char>>& matrix) {
     
      int m=matrix.size();
      int n=matrix[0].size();
      vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    int result=0;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
              if(matrix[i][j]=='1'){
                result=max(result,solve(i,j,matrix,dp));
              }
        }
    }
   return result*result;
    }
};