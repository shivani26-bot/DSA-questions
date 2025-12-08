/**
 * @param {number[][]} grid
 * @return {number}
 */
var getMaximumGold = function(grid) {
      let m=grid.length;
      let  n=grid[0].length;

const directions=[[1,0],[0,-1],[-1,0],[0,1]];
function isSafe( i,j, grid ){
    if(i<0 || i>=m ||j<0 ||j>=n || grid[i][j]==0) return false;
    return true;
}

    function dfs(i, j, grid){

if(!isSafe(i,j,grid)) return 0;
 let originalValue=grid[i][j];
    grid[i][j]=0;
let maxGold=0;
    for(const it of  directions){
const adj_i=i+it[0];
const adj_j=j+it[1];
maxGold= Math.max(maxGold,dfs(adj_i,adj_j,grid));
    }
grid[i][j]=originalValue;
return originalValue+maxGold;
}

      let maxGold=0;
       for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            if(grid[i][j]!=0){
                  maxGold=Math.max(maxGold,dfs(i,j,grid));
            }
        }
       }
       return maxGold;
};