class Solution {
public:
vector<vector<int>>directions={{1,0},{0,-1},{-1,0},{0,1}};
int m,n;
void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>&visited ){
    visited[r][c]=true;

    for(auto it: directions){
         int adjR= r+it[0];
         int adjC= c+it[1];
         if(adjR>0 && adjR<m && adjC>0 && adjC<n && !visited[adjR][adjC] && grid[adjR][adjC]==1){
            dfs(adjR,adjC,grid,visited);
         }
    }

}
    int numEnclaves(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        int count=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
      
       for(int j=0;j<n;j++){
        if(grid[0][j]==1 && !visited[0][j]) dfs(0,j,grid, visited);
        if(grid[m-1][j]==1 && !visited[m-1][j]) dfs(m-1,j,grid,visited);
       }
        for(int i=1;i<m-1;i++){
        if(grid[i][0]==1 && !visited[i][0]) dfs(i,0,grid,visited);
        if(grid[i][n-1]==1  && !visited[i][n-1]) dfs(i,n-1,grid,visited);
       }
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j]==1 && !visited[i][j]) count++;
    }
}
        return count;
    }
};