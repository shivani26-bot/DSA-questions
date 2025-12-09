/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
     let islandCount=0;
      const n=grid.length;
   const m=grid[0].length;

     function dfs( grid,i, j, visited){
if(i<0 || i>=n || j<0 || j>=m ||  visited[i][j]=='1' || grid[i][j]=='0')
return;

visited[i][j]='1';

    dfs(grid,i+1,j,visited);
    dfs(grid,i-1,j,visited);
    dfs(grid,i,j+1,visited);
    dfs(grid,i,j-1,visited);

}
    //  const visited= Array.from({length:n},()=>Array.from({length:m},()=>'0'));
     const visited = Array(n).fill().map(() => Array(m).fill('0'));

      for(let i=0;i<n;i++){
        for(let  j=0;j<m;j++){
            if(grid[i][j]=='1' && visited[i][j]=='0'){
                islandCount++;
                dfs(grid,i,j,visited);
            }
        }
      }
return islandCount;
};