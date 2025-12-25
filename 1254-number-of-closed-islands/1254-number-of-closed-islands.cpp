class Solution {
public:
int m,n;
bool dfs(int i, int j, vector<vector<int>>& grid){
if(i<0 || j<0 || i>=m ||j>=n) return false;
if(grid[i][j]==1) return true; //closed// water or already visited
// As soon as DFS reaches a land cell (0)
// You mark it as visited by converting it to 1
// This prevents revisiting the same cell again
// If this cell is 0 and DFS visits it, it will be turned to 1”
// Adjacents being 0 only means DFS will continue into them —
// each of those will then also be turned to 1 when visited.
grid[i][j]=1;
    bool left= dfs(i-1,j,grid);
    bool right=dfs(i+1,j,grid);
    bool up= dfs(i,j+1,grid);
    bool down= dfs(i,j-1,grid);
    return left && right && up && down;
}

    int closedIsland(vector<vector<int>>& grid) {
        // use simple dfs
        // find a land and check whether it has land in it's all 4 direction or not
     m=grid.size();
     n=grid[0].size();
   
      int count=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0 ){
                if(dfs(i,j,grid)) count++;
            }}}
      return count;  
    }
};