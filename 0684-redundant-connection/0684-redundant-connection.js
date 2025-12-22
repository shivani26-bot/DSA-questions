/**
 * @param {number[][]} edges
 * @return {number[]}
 */

class DisjointSet{


  constructor( n){
       this.rank=Array(n+1).fill(0);
       this.size=Array(n+1).fill(1);
       this.parent=Array(n+1);
        for(let i=0;i<n;i++){
            this.parent[i]=i;
        }
    }
    findUPar(node){
        if(node==this.parent[node]) return node;
        return this.parent[node]=this.findUPar(this.parent[node]);
    }
     unionByRank( u, v){
        let ulp_u=this.findUPar(u);
        let ulp_v=this.findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(this.rank[ulp_u]<this.rank[ulp_v]){
            this.parent[ulp_u]=ulp_v;
        }
        else if(this.rank[ulp_u]>this.rank[ulp_v]){
            this.parent[ulp_v]=ulp_u;
        }
        else{
              this.parent[ulp_v]=ulp_u;
              this.rank[ulp_u]++;
        }
    }
       unionBySize( u, v){
        let ulp_u=this.findUPar(u);
        let ulp_v=this.findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(this.size[ulp_u]<this.size[ulp_v]){
            this.parent[ulp_u]=ulp_v;
            this.size[ulp_v]+=this.size[ulp_u];
        }
        else{
              this.parent[ulp_v]=ulp_u;
             this.size[ulp_u]+=this.size[ulp_v];
        }
    }

};
var findRedundantConnection = function(edges) {
     
     const n=edges.length;
     const ds= new  DisjointSet(n);
        for(const [u,v] of edges){
       
            if(ds.findUPar(u)===ds.findUPar(v)){
                return [u,v];
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        return [-1,-1];
    
};