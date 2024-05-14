class Solution {
public:

bool isSafe(int i, int j,vector<vector<int>>& grid, vector<vector<bool>>&visited){
       int n=grid.size();
        int m=grid[0].size();
      if(i<0 || i>=n ||j<0 || j>=m || visited[i][j] || grid[i][j]==0) return false;
      return true;
}

int solve(vector<vector<int>>& grid, vector<vector<bool>>&visited ,int i, int j){
      int n=grid.size();
        int m=grid[0].size();
if(!isSafe(i,j,grid,visited)) return 0;
//   int left=0,right=0 ,up=0,down=0;
       visited[i][j]=true;
          int left= solve(grid,visited,i,j-1);
          int right= solve(grid,visited,i,j+1);
          int down=solve(grid,visited,i+1,j);
          int up= solve(grid,visited,i-1,j);
visited[i][j]=false;

        return grid[i][j] + max( max(left,right) ,max(down,up));


}
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans= 0;
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]!=0){
                    ans= max(ans,solve(grid,visited,i,j));
                }
            }
        }
        return ans;
    }
};