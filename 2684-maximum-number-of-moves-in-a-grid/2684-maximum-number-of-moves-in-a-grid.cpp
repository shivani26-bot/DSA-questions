class Solution {
public:

// int solve(int row, int col, int m, int n, vector<vector<int>>&grid){
//     // if(row<0  || row>=m || col>=n ) return 0;
    

// int right=0,up_right_diag=0,bottom_right_diag=0;

// if(col+1<n && grid[row][col+1]>grid[row][col])
//      right= 1+solve(row,col+1,m,n,grid); //->

// if(row-1>=0 && col+1<n && grid[row-1][col+1]>grid[row][col])
//      up_right_diag= 1+solve(row-1,col+1,m,n,grid);
    
// if(row+1<m && col+1<n && grid[row+1][col+1]>grid[row][col])
//      bottom_right_diag= 1+solve(row+1, col+1,m,n,grid);
    
  
//     return max({right,up_right_diag,bottom_right_diag});

// }
//     int maxMoves(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
// cout<<m<<" "<<n<<endl;
//         int result=INT_MIN;
       
//         for(int i=0;i<m;i++){

//              result=max(result,solve(i,0,m,n,grid));
//         }
//         return result;
//     }

// top down 
// int solve(int row, int col, int m, int n, vector<vector<int>>&grid,vector<vector<int>>&dp){
//     // if(row<0  || row>=m || col>=n ) return 0;
    
// if(dp[row][col]!=-1) return dp[row][col];
// int right=0,up_right_diag=0,bottom_right_diag=0;

// if(col+1<n && grid[row][col+1]>grid[row][col])
//      right= 1+solve(row,col+1,m,n,grid,dp); //->

// if(row-1>=0 && col+1<n && grid[row-1][col+1]>grid[row][col])
//      up_right_diag= 1+solve(row-1,col+1,m,n,grid,dp);
    
// if(row+1<m && col+1<n && grid[row+1][col+1]>grid[row][col])
//      bottom_right_diag= 1+solve(row+1, col+1,m,n,grid,dp);
    
  
//     return dp[row][col]=max({right,up_right_diag,bottom_right_diag});

// }
//     int maxMoves(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
// cout<<m<<" "<<n<<endl;
//         int result=INT_MIN;
//        vector<vector<int>>dp(m,vector<int>(n,-1));
//         for(int i=0;i<m;i++){

//              result=max(result,solve(i,0,m,n,grid,dp));
//         }
//         return result;
//     }


// bottom top 
// int top down col was from 0 to n-1 hence in bottom up it will be from n-1 to 0
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
cout<<m<<" "<<n<<endl;
        int result=INT_MIN;
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       
       for(int col=n-1;col>=0;col--){
          for(int row=0;row<m;row++){
             int right=0,up_right_diag=0,bottom_right_diag=0;

             if(col+1<n && grid[row][col+1]>grid[row][col])
                right= 1+dp[row][col+1]; //->

             if(row-1>=0 && col+1<n && grid[row-1][col+1]>grid[row][col])
                up_right_diag= 1+dp[row-1][col+1];
    
             if(row+1<m && col+1<n && grid[row+1][col+1]>grid[row][col])
                bottom_right_diag= 1+dp[row+1][col+1];
    
  
            dp[row][col]=max({right,up_right_diag,bottom_right_diag});
             if(col==0) result=max(result,dp[row][0]);
        }
       }
       
        return result;
    }
};