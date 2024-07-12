class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

int findUPar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findUPar(parent[node]);
}
    void unionByRank(int u, int v){
       int ulp_u=findUPar(u);
       int ulp_v=findUPar(v);
       if(ulp_u==ulp_v) return;
       if(rank[ulp_u]<rank[ulp_v]) parent[ulp_u]=ulp_v;
       else if(rank[ulp_v]<rank[ulp_u]) parent[ulp_v]=ulp_u;
else{
    parent[ulp_v]=ulp_u;
    rank[ulp_u]++;
}
    }

void unionBySize(int u, int v){
       int ulp_u=findUPar(u);
       int ulp_v=findUPar(v);
       if(ulp_u==ulp_v) return;
       if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
       }
      else{
    parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
       }
}
};

class Solution {
public:
// there are total n stones
// let suppose there are k components 
// c1, c2 ,c3,c4,........ck each component having following stones
// x1, x2 ,x3,x4,........xk= sum of all these stones is equal to n stones
//     the number of stones that can be removed in a component is totalsizeofcomponent-1
// x1-1,x2-1,x3-1,x4-1,.....xk-1= (x1+x2+x3+x4+...xk)-(1+1+1+1+...+k)= n-(number of components)
    int removeStones(vector<vector<int>>& stones) {
        // here we treat row and column as a node in disjoint set
        // if we have node at 0,0 then any stone at 0th row or 0th col ie 5th
        // will be combined to make a component
        // for ex: matrix with 5 rows and 4 columns
        // row: 0 1 2 3 4
        // coordinate shift, col+rowsize
        // 5th  can be treated as 0th column
        // 6th  can be treated as 1th column
        // 7th  can be treated as 2th column
        // 8th can be treated as 3th column
        // col: 5 6 7 8 
        // matrix:
        // 1 0 1 0
        // 0 0 0 1
        // 0 0 0 0
        // 1 0 1 0
        // 0 0 0 1
        // ultimate parents :0 1 2 3 4 5 6 7 8
// after processing ultimate parents:            0      1    2   6
//nodes connected to their ultimate parents:   7 3 5   4 8 
// we can discard 2 and 6 as there are no stones in 2nd row and 1st column and only 
// consider valid parents 0, 1      
int n=stones.size();   
int maxRow=0;
int maxCol=0;
for(auto it: stones){
    maxRow= max(maxRow,it[0]);
    maxCol= max(maxCol,it[1]);
}                      
// here rows and column are considered as node
DisjointSet ds(maxRow+maxCol+1);
unordered_map<int,int>stoneNodes;
// for every row same stones in same row and same column can combines to same component 
for(auto it: stones){
int nodeRow=it[0];
int nodeCol=it[1]+maxRow+1;
ds.unionBySize(nodeRow,nodeCol);
// storing nodes present in disjointSet 
stoneNodes[nodeRow]=1;
stoneNodes[nodeCol]=1;
}
int connectedComponents=0;
for(auto it: stoneNodes){
    if(ds.findUPar(it.first)==it.first){
        connectedComponents++;
    }
}
return n-connectedComponents;
    }
};