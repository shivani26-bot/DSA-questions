class Solution {
public:


int solve(int i, int j, vector< vector< int> > &obstacleGrid,vector<vector<int>>&dp){

	 if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;//safe condition
		if(i==0 && j==0) return 1; //base condition
	if(i<0  || j<0) return 0; //checking is safe or not 
	

	if(dp[i][j]!=-1) return dp[i][j];
		int left= solve(i,j-1,obstacleGrid,dp);
	int up= solve(i-1,j,obstacleGrid,dp);
	return dp[i][j]=   (left+up);
}

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         	int n=obstacleGrid.size();
//             int m=obstacleGrid[0].size();
//             vector<vector<int>>dp(n,vector<int>(m,-1));
//    return solve(n-1,m-1,obstacleGrid,dp);
//     }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        	int m=obstacleGrid.size(); //row size
            int n=obstacleGrid[0].size();//column size
            vector<vector<int>>dp(m,vector<int>(n,0));
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      

        if(obstacleGrid[i][j]!=1){
              if(i==0 && j==0){
            dp[i][j]=1;
            continue;
        }
        int left=0 ,up=0;
if(j>0)
        left =dp[i][j-1];
if(i>0)
        up= dp[i-1][j];

dp[i][j]=left+up;
    }
    }
   }
   return dp[m-1][n-1];
    }
};