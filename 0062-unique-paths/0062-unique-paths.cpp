class Solution {
public:
// recursion
// time complexity: 2^(m*n) because we have m*n cells and for each cell we have two paths.
// space complexity: recursive call stack ie length of the path taken  (m-1)+(n-1)
// bool isSafe(int i, int j, int m, int n){
// 	if(i>=m || j>=n) return false;
// 	return true;
// }
// int solve(int i, int j,int m, int n){
// 	if(i==m-1 && j==n-1) return 1;
// 	if(!isSafe(i,j,m,n)) return 0;
// 	int right= solve(i,j+1,m,n);
// 	int down= solve(i+1,j,m,n);
// 	return right+down;
// }
// int uniquePaths(int m, int n) {
// 	// Write your code here.
// 	return solve(0,0,m,n);
// }

// top down 
// time complexity: o(m*n)
// space complexity: o(m-1+n-1) + o(m*n) ie path length + size of 2d dp array
// bool isSafe(int i, int j, int m, int n){
// 	if(i>=m  || j>=n ) return false;
// 	return true;
// }
// int solve(int i, int j,int m, int n,vector<vector<int>>&dp){
// 	if(i==m-1 && j==n-1) return 1;
// 	if(!isSafe(i,j,m,n)) return 0;
// 	 if(dp[i][j]!=-1) return dp[i][j];
	 
// 	int right= solve(i,j+1,m,n,dp);
// 	int down= solve(i+1,j,m,n,dp);
// 	return dp[i][j]=right+down;
// }
// int uniquePaths(int m, int n) {
// 	// Write your code here.
// 	vector<vector<int>>dp(m,vector<int>(n,-1));
// 	return solve(0,0,m,n,dp);
// }


// bool isSafe(int i, int j, int m, int n){
// 	if(i<0  || j<0 ) return false;
// 	return true;
// }
// int solve(int i, int j,int m, int n,vector<vector<int>>&dp){
		
// 	if(i==0 && j==0) return 1;
// 	if(!isSafe(i,j,m,n)) return 0;
// if(dp[i][j]!=-1) return dp[i][j];
// 	int left= solve(i,j-1,m,n,dp);
// 	int up= solve(i-1,j,m,n,dp);
// 	return dp[i][j]=left+up;
// }
// int uniquePaths(int m, int n) {
// 	// Write your code here.
// 	vector<vector<int>>dp(m,vector<int>(n,-1));
// 	return solve(m-1,n-1,m,n,dp);
// }

// memoization to tabulation
// declare base case
// express all states in for loop, 2 states 2 loops 
// copy the recurrence and write
// time:o(m*n)
// space:o(m*n)

// int solve(int m, int n,vector<vector<int>>&dp){
// for(int i=0;i<m;i++){
// 	for(int j=0;j<n;j++){
//           if (i == 0 && j == 0) {
// 			  dp[i][j]=1;
//             continue;
//           } 
//             int left = 0, up = 0;
//             if (i > 0)
// 			 up = dp[i - 1][j];
            
//             if (j > 0)
//                left = dp[i][j - 1];
			   
//             dp[i][j] = left + up;
//           }
        
// }

// 	return dp[m-1][n-1];
// }
// int uniquePaths(int m, int n) {
// 	// Write your code here.
// 	vector<vector<int>>dp(m,vector<int>(n,-1));
// 	return solve(m,n,dp);
// }

// space optimization
// we are using previous rows and previous column hence we can space optimize it

// Time Complexity: O(M*N)

// Reason: There are two nested loops

// Space Complexity: O(N)

// Reason: We are using an external array of size ‘N’ to store only one row.
int solve(int m, int n){
  vector<int>prev(n,0);

for(int i=0;i<m;i++){
  vector<int>temp(n,0);
	for(int j=0;j<n;j++){

          if (i == 0 && j == 0) {
			  temp[j]=1;
            continue;
          } 
            int left = 0, up = 0;
            if (i > 0)
			 up = prev[j];
            
            if (j > 0)
               left = temp[j - 1];
			   
            temp[j] = left + up;
          }
        prev=temp;
}

	return prev[n-1];
}
int uniquePaths(int m, int n) {
	// Write your code here.
	return solve(m,n);
}

};