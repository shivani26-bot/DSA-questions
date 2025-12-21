/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestPathBinaryMatrix = function(grid) {
    
const n=grid.length;
function isSafe( x,  y){
    return x>=0 && x<n && y>=0 && y<n;
}
      
       
        const q=[];
            if(grid[0][0]==1) return -1;
        q.push([0,0]);
const directions=[[1,0],[1,-1],[0,-1],[-1,-1],[-1,0],[-1,1],[0,1],[1,1]];
 const visited=new Set();   
 let level=0;
        while(q.length>0){
           let sz=q.length;
            while(sz--){
    const [x,y]=q.shift();
          
            if(x==n-1 && y==n-1) return level+1;


            for(const  it of directions){
            const adjX=x+it[0];
            const adjY=y+it[1];
                const key=`${adjX},${adjY}`
                if(isSafe(adjX,adjY) && grid[adjX][adjY]==0 && !visited.has(key)){
                    visited.add(key);
                   q.push([adjX,adjY]);
                }
            }
            }
            level++;
       
        }
        return -1;
};