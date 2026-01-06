/**
 * @param {number[][]} times
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var networkDelayTime = function(times, n, k) {
         // source is given as node k
    const adjList=new Map();
    const pq=[];
    for(let i=1;i<=n;i++) adjList.set(i,[]);
    for(const [u,v,time] of times){
          adjList.get(u).push([v,time]);
    }

    const distance=Array(n+1).fill(Infinity);
    distance[k]=0;
    pq.push([0,k]);//time,node
    let min_time=0;
    while(pq.length>0){
        pq.sort((a,b)=>a[0]-b[0]); //sort based on time
        const [time,node]=pq.shift();

        for(const [adjNode,edgeTime] of adjList.get(node)){
             
         
                if(time+edgeTime<distance[adjNode]){
                    pq.push([time+edgeTime, adjNode]);
                    distance[adjNode]=time+edgeTime;
                    
       
                }
        }
    }
    // if(distance[n-1]==1e9) return -1;
    // for(int i=1;i<=n;i++){
    //    min_time=max(min_time,distance[i]);
    // }
    // return min_time==1e9?-1:min_time;

     for(let i=1;i<=n;i++){//distance array will store shortest distance from src node to every other node , we need to find maximum out of all to find the minimum time to take the signal to reach each node, if it's 1e9 it means we never reached that node and return -1
        if(distance[i]===Infinity) return -1;
       min_time=Math.max(min_time,distance[i]);
    }
    return min_time;
};