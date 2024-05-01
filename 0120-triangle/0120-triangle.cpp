class Solution {
public:
// there is no fixed ending point hence don't start from n-1 m-1, instead start from 0 0
	// time complexity: number of element in each row-> 1 , 2 ,3, 4....n
	// for every row we have 2 options go down or diagonal hence, 2^(summation of (1,2,...n))
// space complexity: o(n) stack space going from top to bottom 
// recursion 
// int solve(int i, int j, vector<vector<int>>&triangle, int n){
// 	if(i==n-1) return triangle[i][j];

// 	int down=triangle[i][j]+solve(i+1,j,triangle,n);
// 	int diagonal=triangle[i][j]+solve(i+1,j+1,triangle,n);

// 	return min(down, diagonal);
// }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         return solve(0,0,triangle, n);
//     }

// memoization, top down 
// time complexity o(n*n)
// space: o(n+n^2)
// int solve(int i, int j, vector<vector<int>>&triangle, int n,vector<vector<int>>&dp){
// 	if(i==n-1) return dp[i][j]= triangle[i][j];
//   if(dp[i][j]!=-1) return dp[i][j];
// 	int down=triangle[i][j]+solve(i+1,j,triangle,n,dp);
// 	int diagonal=triangle[i][j]+solve(i+1,j+1,triangle,n,dp);

// 	return dp[i][j]=   min(down, diagonal);
// }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //      vector<vector<int>>dp(n,vector<int>(n,-1));
	// return solve(0,0,triangle, n,dp);
    // }
// tabulation bottom up 
// int tabulation its opposite
// if recursion we write for 0 to n-1 then for tabulation it will be from n-1 to 0
// tabulation is opposite of top down
// base case  to main problem 
// here we will start filling the table from n-1 as base case is n-1 and will go till 0th index 
// for 0th row-> we have 0 column
// for 1st row-> we have 0,1 column
// for 2nd row-> we have 0,1,2 column
// for 3rd row-> we have 0,1,2,3 column
// time : o(n*n)
// space: o(n*n)
// number of column in each row is i+1
// int solve( vector<vector<int>>&triangle, int n,vector<vector<int>>&dp){
// 	// we can have 4 different base cases at the n-th row
// 	 for(int j=0;j<n;j++){
// 		 dp[n-1][j]=triangle[n-1][j];
// 	 }
//   for(int i=n-2;i>=0;i--){
// 	  for(int j=i;j>=0 ;j--){
         
//               int down=triangle[i][j]+dp[i+1][j];
// 	          int diagonal=triangle[i][j]+dp[i+1][j+1];
// 			  dp[i][j]=   min(down, diagonal);
// 	  }
// 	}
//   return dp[0][0];
// }

//   int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,0));
// 	return solve(triangle, n,dp);
//     }

// space optimization 
// time complexity:o(n*n)
// space:o(n)
int solve( vector<vector<int>>&triangle, int n){
	// we can have 4 different base cases at the n-th row
    vector<int>next(n,0);
     vector<int>curr(n,0);
	 for(int j=0;j<n;j++){
		 next[j]=triangle[n-1][j];
	 }
     
  for(int i=n-2;i>=0;i--){
   
	  for(int j=i;j>=0 ;j--){
         
              int down=triangle[i][j]+next[j];
	          int diagonal=triangle[i][j]+next[j+1];
			  curr[j]=   min(down, diagonal);
	  }
      next=curr;
	}
  return next[0];
}

  int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       
	return solve(triangle, n);
    }
};