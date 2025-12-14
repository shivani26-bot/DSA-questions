/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */
var minReorder = function(n, connections) {
      const adj=new Map();
        let count=0;
function dfs(node,parent){

    for(const [v,check] of adj.get(node)){
       
       
      
        if(v!=parent){
              if(check==1) count++; //1->real edge 0-> fake edge 
                dfs(v,node,adj, count);
        }
      
    }
    
}
        for(let i=0;i<connections.length;i++){
            // const u=connections[i][0];
            // const v=connections[i][1];
            const [u,v]=connections[i];
            if(!adj.has(u)) adj.set(u,[]);
            if(!adj.has(v)) adj.set(v,[]);
           
            adj.get(u).push([v,1]);
              adj.get(v).push([u,0]);
           
        }
      

        // start from node 0
        dfs(0,-1);
        return count;
};