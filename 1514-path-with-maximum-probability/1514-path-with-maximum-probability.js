/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} succProb
 * @param {number} start_node
 * @param {number} end_node
 * @return {number}
 */
var maxProbability = function(n, edges, succProb, start_node, end_node) {
    const adj=Array.from({length:n},()=>[]);
        for(let i=0;i<edges.length;i++){
            adj[edges[i][0]].push([succProb[i],edges[i][1]]);
            adj[edges[i][1]].push([succProb[i],edges[i][0]]);
        }



     const dist=Array(n).fill(0.0);//finds distance from start node to every other node
     dist[start_node]=1.0;
  
     const pq=[];
    pq.push([1.0,start_node]);
    while(pq.length>0){
        pq.sort((a,b)=>b[0]-a[0])
        const [distance,node]=pq.shift();
       
        if (node === end_node) return distance;
        for(const [edgeWeight,adjNode] of adj[node]){
            if(distance*edgeWeight>dist[adjNode]){
                dist[adjNode]=distance*edgeWeight;
                pq.push([dist[adjNode],adjNode]);
            }
        }
    }
        return 0;
};