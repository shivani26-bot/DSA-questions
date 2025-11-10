/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {boolean[]} hasApple
 * @return {number}
 */

   
var minTime = function(n, edges, hasApple) {
    const adjList= Array.from({length:n},()=>[]);
    for(let [u,v] of edges){
        adjList[u].push(v);
        adjList[v].push(u);
    }
    function dfs( node,parent){
 let time=0;


for(let child of adjList[node]){

    if(child==parent) continue;
    const time_from_child= dfs(child,node);
   if(time_from_child>0 || hasApple[child]){
    time+=(time_from_child+2);
   }
}
return time;
}
   
       
   
        return dfs(0, -1);
};