/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestPathBinaryMatrix = function(grid) {
    
const n=grid.length;
function isSafe( x,  y){
    return x>=0 && x<n && y>=0 && y<n;
}
      
       
//         const q=[];
//             if(grid[0][0]==1) return -1;
//         q.push([0,0]);
// const directions=[[1,0],[1,-1],[0,-1],[-1,-1],[-1,0],[-1,1],[0,1],[1,1]];
//  const visited=new Set();   
//  let level=0;
//         while(q.length>0){
//            let sz=q.length;
//             while(sz--){
//     const [x,y]=q.shift();
          
//             if(x==n-1 && y==n-1) return level+1;


//             for(const  it of directions){
//             const adjX=x+it[0];
//             const adjY=y+it[1];
//                 const key=`${adjX},${adjY}`
//                 if(isSafe(adjX,adjY) && grid[adjX][adjY]==0 && !visited.has(key)){
//                     visited.add(key);
//                    q.push([adjX,adjY]);
//                 }
//             }
//             }
//             level++;
       
//         }
//         return -1;

// dijkstra 
 
        if( grid[0][0]!=0) return -1;
     const pq=[];
const distance= Array.from({length:n}, ()=> Array(n).fill(1e9));//will contain the min distance to reach from 0,0 to all the other cells
      const directions=[[1,0],[1,-1],[0,-1],[-1,-1],[-1,0],[-1,1],[0,1],[1,1]];
     
        grid[0][0]=1;         // also mark it as visited, not required as  using minheap will always take the smallest distance first
         distance[0][0]=0;
       pq.push([0,0,0]); //{distance,{x,y}}

        while(pq.length>0){
          const [dist,x,y]= pq.shift();
         
          for(let i=0;i<8;i++){
          
  const adj_x= x+directions[i][0];
  const adj_y= y+directions[i][1];


    if(isSafe(adj_x,adj_y) && grid[adj_x][adj_y]==0 ){

if(1+dist<distance[adj_x][adj_y]){

    pq.push([1+dist,adj_x,adj_y]);
    grid[adj_x][adj_y]=1;
        distance[adj_x][adj_y]=1+dist;
}
            }
          }

       
        }
        if(distance[n-1][n-1]==1e9) return -1;//not reachable
        return distance[n-1][n-1]+1;
};