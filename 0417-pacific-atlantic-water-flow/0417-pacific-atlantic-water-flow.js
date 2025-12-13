/**
 * @param {number[][]} heights
 * @return {number[][]}
 */
var pacificAtlantic = function(heights) {
    const n=heights.length;
const m=heights[0].length;
const ans=[];
const pacificQ=[];
const atlanticQ=[];
const pacific=Array.from({length:n},()=>Array(m).fill(false));
const atlantic=Array.from({length:n},()=>Array(m).fill(false));

for(let j=0;j<m;j++){
    pacificQ.push({x:0,y:j});
    pacific[0][j]=true;
    atlanticQ.push({x:n-1,y:j});
    atlantic[n-1][j]=true;
}
for(let i=0;i<n;i++){
    pacificQ.push({x:i,y:0});
    pacific[i][0]=true;
    atlanticQ.push({x:i,y:m-1});
    atlantic[i][m-1]=true;
}

 function bfs(arr,q){
      while(q.length>0){
      let {x,y}=q.shift();
     
        const xdir=[-1,0,+1,0];
        const ydir=[0,+1,0,-1];
        for(let i=0;i<4;i++){
            let adjX=x+xdir[i];
            let adjY=y+ydir[i];
            if(adjX>=0 && adjX<n && adjY>=0 && adjY<m && !arr[adjX][adjY] &&  heights[adjX][adjY]>=heights[x][y]){
                arr[adjX][adjY]=true;
                q.push({x:adjX,y:adjY});
            }
        }
      }
}



bfs(pacific,pacificQ);
bfs(atlantic,atlanticQ);
for(let i=0;i<n;i++){
    for(let j=0;j<m;j++){
        if(pacific[i][j] && atlantic[i][j]){
            ans.push([i,j]);
        }
    }
}
return ans;
};