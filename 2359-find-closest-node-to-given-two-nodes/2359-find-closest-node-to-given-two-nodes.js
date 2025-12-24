/**
 * @param {number[]} edges
 * @param {number} node1
 * @param {number} node2
 * @return {number}
 */
var closestMeetingNode = function(edges, node1, node2) {

  const n=edges.length;
   const dist1= Array(n).fill(Infinity); //will store distance of all other nodes from node1
       const dist2=Array(n).fill(Infinity); //will store distance of all other nodes from node1

const visited1=Array(n).fill(false);
const visited2=Array(n).fill(false);

function bfs( node, distance,visited){


const q=[];
q.push(node);
visited[node]=true;
while(q.length>0){
    let n=q.shift();

 let adjNode=edges[n];
    if(adjNode!=-1 && !visited[adjNode] ){
        distance[adjNode]=1+distance[n];
        q.push(adjNode);
        visited[adjNode]=true;
    }
}
}
         
   

dist1[node1]=0;
dist2[node2]=0;

    bfs(node1,dist1,visited1);
       
      bfs(node2,dist2,visited2);
let minDistanceNode=-1;
let minDistanceTillNow=Infinity;
      for(let i=0;i<n;i++){
        let maxDistance=Math.max(dist1[i],dist2[i]);
        if(minDistanceTillNow>maxDistance){
              minDistanceNode=i;
            minDistanceTillNow=maxDistance;
          
        }
      }
      return minDistanceNode;
};