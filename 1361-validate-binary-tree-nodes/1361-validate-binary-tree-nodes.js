/**
 * @param {number} n
 * @param {number[]} leftChild
 * @param {number[]} rightChild
 * @return {boolean}
 */

class DisjointSet{
constructor(n){
    this.rank= Array(n).fill(0);
    this.parent=Array(n);
    this.size=Array(n).fill(1);
    for(let i=0;i<n;i++){
        this.parent[i]=i;
    }
}
findUPar( node){
    if(node===this.parent[node]) return node;
    return this.parent[node]=this.findUPar(this.parent[node]);
}
unionByRank( u,  v){
    let ulp_u=this.findUPar(u);
    let ulp_v=this.findUPar(v);
    if(ulp_u==ulp_v) return;
    if(this.rank[ulp_u]<this.rank[ulp_v])
{
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
 unionBySize( u,  v){
        let ulp_u=this.findUPar(u);
        let ulp_v=this.findUPar(v);
        if(ulp_u===ulp_v) return ;
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

var validateBinaryTreeNodes = function(n, leftChild, rightChild) {
    const  ds= new DisjointSet(n);
    //   for every node, we are incrementing inedges of left and right child of a node by 1, because it's binary tree, if at any point inedges of a node is >1 it means node has two parents ,
    // const inEdges=Array(n);//array of undefined 
    const inEdges=Array(n).fill(0);
for(let i=0;i<n;i++){
    const node=i;
    const leftC= leftChild[i];
    const rightC=rightChild[i];
   if(leftC!=-1){
    inEdges[leftC]++;
    if(inEdges[node]>1) return false;
    if(ds.findUPar(node)===ds.findUPar(leftC)) return false; //If node and leftC are already in the same component, adding this edge will form a cycle, so the structure is NOT a tree.
    ds.unionBySize(node,leftC);
   }
      if(rightC!=-1){
        inEdges[rightC]++;
        if(inEdges[node]>1) return false;
    if(ds.findUPar(node)===ds.findUPar(rightC)) return false;
    ds.unionBySize(node,rightC);
   }
}
//also there should be one root, the root will have no incoming edges
let countRoot=0;
for(let i=0;i<n;i++){
    if(inEdges[i]===0) countRoot++;
}
return countRoot==1;
};