class Solution {
public:
// recursion 
// bool isSafe(int i, int j){
// 	if(i<0 || j<0) return false;
// 	return true;
// }
// int solve(int i, int j,vector<vector<int>> &grid){
// 	if(i==0 && j==0) return grid[0][0] ;
// 	if(!isSafe(i,j)) return 1e9; //as we will not take this path,
// 	int up=grid[i][j]+solve(i-1,j,grid);
// 	int left= grid[i][j]+solve(i,j-1,grid);
// 	return min(left,up);
// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//     int n=grid[0].size();
//     return solve(m-1,n-1,grid);
//     }

// top down 
// bool isSafe(int i, int j){
// 	if(i<0 || j<0) return false;
// 	return true;
// }
// int solve(int i, int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
// 	if(i==0 && j==0) return grid[0][0] ;
// 	if(!isSafe(i,j)) return 1e9; //as we will not take this path,
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int up=grid[i][j]+solve(i-1,j,grid,dp);
// 	int left= grid[i][j]+solve(i,j-1,grid,dp);
// 	return dp[i][j]=min(left,up);
// }
// int minPathSum(vector<vector<int>> &grid) {
//     // Write your code here.
//     int m=grid.size();
//     int n=grid[0].size();
// 	vector<vector<int>>dp(m, vector<int>(n,-1));
//     return solve(m-1,n-1,grid,dp);
// }

// tabulation 
// int solve(int i, int j,int m, int n ,vector<vector<int>> &grid,vector<vector<int>>&dp){
// for(int i=0;i<m;i++){
// 		for(int j=0;j<n;j++){
// 				if(i==0 && j==0) dp[i][j]= grid[0][0] ;
// 				else{
//                     int left=grid[i][j],up=grid[i][j];
// 					if(i>0)
//                      up+=dp[i-1][j];
//                      else up+=1e9;
//                     if(j>0)
//                      left+=dp[i][j-1];
//                      else 
//                      left+=1e9;
// 	dp[i][j]=min(left,up);
// }
// 				}
// 		}
// 		return dp[m-1][n-1];
// 	}
	
// int minPathSum(vector<vector<int>> &grid) {
//     // Write your code here.
//    int m=grid.size();
//     int n=grid[0].size();
// 	vector<vector<int>>dp(m, vector<int>(n,0));
//     return solve(m-1,n-1,m,n,grid,dp);
// }

// space optimization 
// two states
// dp[i-1][j] and dp[i][j-1] ie previous row and current row.
int solve(int i, int j,int m, int n ,vector<vector<int>> &grid,vector<vector<int>>&dp){
vector<int>prev(n,0);
for(int i=0;i<m;i++){
    vector<int>curr(n,0);
		for(int j=0;j<n;j++){
				if(i==0 && j==0) curr[j]= grid[0][0] ;
				else{
                    int left=grid[i][j],up=grid[i][j];
					if(i>0)
                    // requiring previous row's j column 
                     up+=prev[j];
                     else up+=1e9;
                    if(j>0)
                    // requiring current row's j-1 column 
                     left+=curr[j-1];
                     else 
                     left+=1e9;
	curr[j]=min(left,up);
}
				}
                prev=curr;
		}
		return prev[n-1];
	}
	
int minPathSum(vector<vector<int>> &grid) {
    // Write your code here.
   int m=grid.size();
    int n=grid[0].size();
	vector<vector<int>>dp(m, vector<int>(n,0));
    return solve(m-1,n-1,m,n,grid,dp);
}

};