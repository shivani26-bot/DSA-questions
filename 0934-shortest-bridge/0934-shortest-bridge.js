/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestBridge = function(grid) {
   const n=grid.length;
 const m=grid[0].length;
const directions=[[0,1],[1,0],[0,-1],[-1,0]];
function isSafe(i, j){
    return (i>=0 && i<n && j>=0 && j<m);
}
    
function dfs(i,j, visited){
    // Arrays are compared by reference, not value.
    const key=`${i},${j}`;
    if(!isSafe(i,j) || grid[i][j]==0 ||  visited.has(key)) return;

visited.add(key);//unvisitedcell with value 1


for(const it of directions){
  const i_=i+it[0];
   const j_=j+it[1];
    dfs(i_,j_,visited);
}
}
function bfs(visited){
    const q=[];
    // Convert string → numbers when pushing into queue
    for(const key of visited){
        const [x,y]=key.split(',').map(Number);
        q.push([x,y]);
    }
    let level=0;
    while(q.length>0){
      let sz=q.length;
        while(sz--){
        const [x,y]=q.shift();
      
           for(const  it of directions){
           const x_= x+it[0];
          const y_=y+it[1];
          const key=`${x_},${y_}`
            if(isSafe(x_,y_) && !visited.has(key)){
                if(grid[x_][y_]==1)  //we found 2nd island
                return level;
                     
                
                visited.add(key);
                q.push([x_,y_]);
            }
           }
        }
        level++;
    }
    return level;
}


      const visited=new Set();
        for(let i=0;i<n;i++){
            for(let j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,visited);
return bfs(visited);
                }
            }
        }
   
     
return -1;
};