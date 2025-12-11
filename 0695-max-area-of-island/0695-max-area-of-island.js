/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    const n=grid.length;
       const m=grid[0].length;
      let maxArea=0;


    function   dfs(row, col){

if(row<0 || row>=n || col<0 || col>=m || grid[row][col]==0) return 0;
grid[row][col]=0;


return 1+dfs(row+1,col,grid,n,m)+dfs(row-1,col,grid,n,m)+dfs(row,col+1,grid,n,m)+dfs(row,col-1,grid,n,m);

}


        for(let i=0;i<n;i++){
            for(let j=0;j<m;j++){
                if(grid[i][j]==1){
                   maxArea= Math.max(maxArea,dfs(i,j,grid,n,m) ) ;
                } 
            }
        }
        return maxArea;
};