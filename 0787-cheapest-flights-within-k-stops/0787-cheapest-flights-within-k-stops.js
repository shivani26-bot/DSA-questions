/**
 * @param {number} n
 * @param {number[][]} flights
 * @param {number} src
 * @param {number} dst
 * @param {number} k
 * @return {number}
 */
var findCheapestPrice = function(n, flights, src, dst, k) {
      const adj= Array.from({length:n},()=>[]);
        for(let i=0;i<flights.length;i++){
            adj[flights[i][0]].push([flights[i][1],flights[i][2]]);
        }
    const q=[];
    // {stops,{src,cost}};
    q.push([0,src,0]);
    // storing min cost for a particular node
const cheapPriceDist=Array(n).fill(Infinity);
    cheapPriceDist[src]=0;
    while(q.length>0){
       let [stops,node,cost]=q.shift();
        if(stops>k)
         continue;
        
        for(const [adjNode,edgeWeight] of  adj[node]){
          
            if(cost+edgeWeight<cheapPriceDist[adjNode] && stops<=k){
                cheapPriceDist[adjNode]=cost+edgeWeight;
                q.push([stops+1,adjNode,cost+edgeWeight]);
            }
        }
    }
    if(cheapPriceDist[dst]==Infinity) return -1;
    return cheapPriceDist[dst];

};