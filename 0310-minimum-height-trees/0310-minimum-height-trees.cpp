class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     if we try for all root nodes and then try to find height of every tree-> O(n^2)
    //     we realise holding from leaf will make things big comparison to holding from mid
    //     aim to find the mid  by rmoving leaves
    //     if we hold from leaf it will be long , and that node will never contribute to answer.
    // 1) get the graph build from edges using adjacency list
    // 2)remove the leaf nodes(degree 1) keep track of degree while building the graph , as we remove the leaf with degree 1 , its neighbour will also reduce the degree.keep on doing the process while(number of nodes >2)
    // if in last either 2 nodes remain or 1 node remain that is the answer.
    
// vector<int>res;
// if(n<=0) return res;
//     if(n==1) {
//         res.push_back(0);
//         return res;
//     }
//     vector<int>degree(n,0);
//     vector<vector<int>>adjList(n);
//     for(auto edge: edges){
//         degree[edge[0]]++;
//         degree[edge[1]]++;
//         adjList[edge[0]].push_back(edge[1]);
//         adjList[edge[1]].push_back(edge[0]);
//     }
//  queue<int>q;
//     for(int i=0;i<n;i++){
//         if(degree[i]==1){
//            q.push(i); 
//         }
//     }
//     // we go level by level here and try to remove leaf nodes , hence use bfs
// while(n>2){
// int sz= q.size();
// n-=sz;
// while(sz>0){
//     int ele= q.front();
//     q.pop();
//     //go on all the neighbors and reduce their degree
//     for(auto e: adjList[ele]){
//         degree[e]--;
//         if(degree[e]==1) q.push(e);
//     }
//     sz--;
// }
// }
//       while(!q.empty()){
//         int el= q.front();
//         q.pop();
//         res.push_back(el);
//       }
//       return res;
//     }
vector<int>ans;
if(n==1){
    if(edges.size()==0) ans.push_back(0);
    return ans;
}
unordered_map<int,vector<int>>adjList;
vector<int>degree(n,0);
for(auto it: edges){
    int u=it[0];
    int v=it[1];
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    degree[u]++;
    degree[v]++;
}
queue<int>q;
for(int i=0;i<n;i++){
    if(degree[i]==1){
        q.push(i);
    }
}
while(n>2){
    int size=q.size();
    n-=size;
    while(size--){

        int ele=q.front();
        q.pop();
        for(auto it: adjList[ele]){
            degree[it]--;
            if(degree[it]==1) q.push(it);
        }
    }
}


while(!q.empty()){
    int ele=q.front();
    q.pop();
    ans.push_back(ele);
}
return ans;
    }
    // time: o(n)
    // space: o(n)
};