class Solution {
public:
//connected components
// int dfs(vector<vector<int>>&grid, int r, int c){
// if(r<0 || r>=grid.size()|| c<0 || c>=grid[0].size() || grid[r][c]==0){
//     return 1;
// }
// if(grid[r][c]==-1) return 0;

//     // mark the cell visited 
//     grid[r][c]=-1;

//     return dfs(grid,r-1,c)+dfs(grid,r+1,c)+dfs(grid,r,c+1)+dfs(grid,r,c-1);

// }
int dfs(vector<vector<int>>& grid,int r, int c, vector<vector<int>>&visited){
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0){
        return 1;
    }
if(visited[r][c]==-1) return 0;
    visited[r][c]=-1;
    return dfs(grid,r,c+1,visited)+dfs(grid,r,c-1,visited)+dfs(grid,r-1,c,visited)+dfs(grid,r+1,c,visited);
}
    int islandPerimeter(vector<vector<int>>& grid) {
        // int perimeter=0;

        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if( grid[i][j]==1){
        //             perimeter+=4;
        //         if(i>0 && grid[i-1][j]==1){
        //             perimeter-=2;
        //         }
        //         if(j>0 && grid[i][j-1]==1){
        //             perimeter-=2;
        //         }
        //         }
        //     }
        // }
        // return perimeter;

        // dfs
        // int perimeter=0;
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(grid[i][j]==1){
        //             perimeter+=   dfs(grid,i,j);
        //         }
        //     }
        // }
        // return perimeter;


        int perimeter=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j]!=-1){
                        perimeter+= dfs(grid,i,j,visited);
                }
            }
        }
        return perimeter;
    }
};