/**
 * @param {number[][]} points
 * @return {number}
 */
var minCostConnectPoints = function(points) {
//      const n=points.length;
//    const adj=new Map();
//    for(let i=0;i<n;i++){
//             adj.set(i,[]);
//     }
//     for(let i=0;i<n;i++){
//         for(let j=i+1;j<n; j++){
//             const distance= Math.abs(points[i][0]-points[j][0])+Math.abs(points[i][1]-points[j][1]);
//             adj.get(i).push([j,distance]);
//             adj.get(j).push([i,distance]);
//         }
//     }
//     const pq=[];
//     let minCost=0;
//     pq.push([0,0]);
//     const visited=Array(n).fill(0);
//     while(pq.length>0){
//         pq.sort((a,b)=>a[0]-b[0]);//sort based on first parameter
//        const [wt,node]= pq.shift();
       
//         if(visited[node]) continue;
//         visited[node]=1;
//         minCost+=wt;
//         for(const [adjNode,edgeWt] of  adj.get(node)){
           
//             if(!visited[adjNode]){
//                 pq.push([edgeWt,adjNode]);
//             }
//         }
//     }
//     return minCost;


// remove pq completely as it adds extra time complexity 
const n=points.length;
const visited= Array(n).fill(false);
const distance=Array(n).fill(Infinity);//stores min distance to reach node i

distance[0]=0;
let min_cost=0;

for(let i=0;i<n;i++){
    let u=getMinDistanceVertex(visited,distance);

    visited[u]=true;
    min_cost+=distance[u];

    for(let j=0;j<n;j++){
        if(!visited[j]){
            const dist=Math.abs(points[u][0]-points[j][0])+Math.abs(points[u][1]-points[j][1]);
            distance[j]=Math.min(distance[j],dist);
        }
    }

}
return min_cost;
};

var getMinDistanceVertex=function(visited,distance){
    let minVertex=-1;
    let minDist=Infinity;
    for(let i=0;i<distance.length;i++){
        if(!visited[i] && distance[i]<minDist){
            minDist=distance[i];
            minVertex=i;
        }
    }
    return minVertex;
}