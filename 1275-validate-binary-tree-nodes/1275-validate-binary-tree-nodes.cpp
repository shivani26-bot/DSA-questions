
//using dsu
class DisjointSet{

public:
vector<int>rank,parent,size;
DisjointSet(int n){
    rank.resize(n,0),parent.resize(n),size.resize(n,1);
    for(int i=0;i<n;i++){
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
    if(rank[ulp_u]<rank[ulp_v])
{
    parent[ulp_u]=ulp_v;
}
else if(rank[ulp_u]>rank[ulp_v]){
parent[ulp_v]=ulp_u;
}
else{
  parent[ulp_v]=ulp_u;
  rank[ulp_u]++;
  
}
    

    }
    void unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:


//     bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
//         // if it's part of same component it's not a binary tree 
//         // binary treee never contains cycle 

//         // check properties of valid binary tree 
//         // every child must have only one parent
//         // only one root and it has no parents 
//         // connected->only one component 


//         // to check every child has only one parent or not
//         // make a  child to parent map, every child should have one parent

//         // start from root node, make a dfs or bfs call, count the nodes it travelled,
//         // if number of nodes travelled is not equal to total nodes then it means we have two different components and it's not a valid bt 
//         // in order to traverse we can make a adjacency list from parent to child

// unordered_map<int, int>child_parent;//child to parent
// unordered_map<int,vector<int>>parent_child;//PARENT TO CHILD, for traversal, adj list
// for(int i=0;i<n;i++){
//   int node=i;
//   int leftC= leftChild[i];
//   int rightC= rightChild[i];

//     if(leftC!=-1) {
//     parent_child[node].push_back(leftC);//adjList
//         if(child_parent.find(leftC)!=child_parent.end()) return false;// child already has parent and child has two parents
        
//     child_parent[leftC]=node;
//     }

//    if(rightC!=-1){
//       parent_child[node].push_back(rightC);//adjList
// if(child_parent.find(rightC)!=child_parent.end()) return false;
//     child_parent[rightC]=node;
//    }

// }

// // find the root, if root is present in child_parent map then return false;
// // root should not have any parent 
// int root=-1;
// for(int i=0;i<n;i++){
// //   root will not be present in child_parent map 
// if(child_parent.find(i)==child_parent.end()){
//     //if root is not -1 then return false, means if we have two roots,
//     if(root!=-1) return false; 
//   root=i;
// }
// }

// //if we don't find the root
// if(root==-1) return false;  //n = 2, leftChild = [1,0], rightChild = [-1,-1] this case will fail, if we don't give this condition,  because there is not root

// //in order to find that we have more than one component or not use bfs/dfs
// // count number of nodes travelled through the bfs/dfs 

// vector<bool>visited(n,false);
// queue<int>q;
// int count=1;
// q.push(root); //start from root
// visited[root]=true;
// while(!q.empty()){
// int node=q.front();
// q.pop();

// for(auto it: parent_child[node]){
//     if(visited[it]) return false;//in binary tree we can never come to visited node again , we always go in downward direction 
// if(!visited[it]){
//     visited[it]=true;
//     count++;
//     q.push(it);
// }
// }
// }
// return count==n;// to check whether we only have one component or not
//     }



    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
      DisjointSet ds(n);
    //   for every node, we are incrementing inedges of left and child child of a node by 1, because it's binary tree, if at any point inedges of a node is >1 it means node has two parents ,
    vector<int>inEdges(n);
for(int i=0;i<n;i++){
    int node=i;
    int leftC= leftChild[i];
    int rightC=rightChild[i];
   if(leftC!=-1){
    inEdges[leftC]++;
    if(inEdges[node]>1) return false;
    if(ds.findUPar(node)==ds.findUPar(leftC)) return false;
    ds.unionBySize(node,leftC);
   }
      if(rightC!=-1){
        inEdges[rightC]++;
        if(inEdges[node]>1) return false;
    if(ds.findUPar(node)==ds.findUPar(rightC)) return false;
    ds.unionBySize(node,rightC);
   }
}
//also there should be one root, the root will have no incoming edges
int countRoot=0;
for(int i=0;i<n;i++){
    if(inEdges[i]==0) countRoot++;
}
return countRoot==1;
    }

};