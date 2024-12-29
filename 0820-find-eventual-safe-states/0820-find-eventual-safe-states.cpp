class Solution {
public:
//   bool dfs(int node, vector<vector<int>>& graph, vector<int>&visited, vector<int>&pathVisited, vector<int>&check){
//      visited[node]=1;
//      pathVisited[node]=1;
//      for(auto it: graph[node]){
//          if(!visited[it]){
//    if(dfs(it,graph,visited,pathVisited,check)==true) return true;
//          }
//          else if(pathVisited[it]){
//              return true;
//          }
//      }
//      check[node]=1;
//      pathVisited[node]=0;
//      return false;
//  }

  bool dfs(int node, vector<vector<int>>& graph, vector<int>&visited, vector<int>&pathVisited){
     visited[node]=1;
     pathVisited[node]=1;
     for(auto it: graph[node]){
         if(!visited[it]){
   if(dfs(it,graph,visited,pathVisited)==true) return true;
         }
         else if(pathVisited[it]){
             return true;
         }
     }

     pathVisited[node]=0;
     return false;
 }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//   // using cycle detection technique
//     // if we start from a particular node and explore different 
//     // paths from that nodes and if any of the path end up at that node again
//     // it means that node will not be a safe node, because a/q to definition
// // A node is a safe node if every possible path starting from that node
//     // leads to a terminal node.
//     // and a terminal node must have no outgoing edges 
//   // if there is a cycle and any other node connected to that cycle
//     // will never be a safe node
//     // 7->1->3->0->1 7 is not a safe node as it's connected to the cycle
//     // any node that leads to a cycle will also not be a safe node 
    
// //   maintain 2 arrays visited ie overall what nodes are visited in graph
// // and pathvisited ie in a particular path what nodes are visited , it will change
// // back to 0 when we backtrack or complete that particular path 
// // 0->1
// // 1->2
// // 2->3
// // 3->4 5
// // 4->6
// // 5->6
// // 6->7
// // 7->
// // 8->1 9
// // 9->10
// // 10->8
// // 11->9
// // 0->1->2->3->4->6->7 all the nodes in this path are safe nodes
// // vis           1 1 1 1 1 0 1 1 0 0 0 0
// // pathvisited   1 1 1 1 1 0 1 1 0 0 0 0
// //               1 1 1 1 0 0 0 0 0 0 0 0 after backtracking
// // now when we retrun as there are no further call to be made from node 7 
// // the pathvisited for that node will be marked to 0 
// // when we reach at 3 then we can't say it as safe node as all the paths
// // linked to 3 must be end to a terminal node hence we explore other paths from node 3
// // 0->1->2->3->5->6->7
// // vis           1 1 1 1 1 1 1 1 0 0 0 0
// // pathvisited   1 1 1 1 0 1 0 0 0 0 0 0
// //               1 1 1 1 0 0 0 0 0 0 0 0
// // now when we follow above path and go from node 5 to 6, 6 is already visited but it's not path visited 
// // hence it is not forming any cycle and 6 has been already checked and
// // hence we will not make any further dfs call from there 
// // hence 5 is a safe node and mark it 0 in path visited and backtrack 
// // and 3 is also a safe node, as both the paths from node 3 leads to 
// // terminal nodes 
// // pathvisited   0 0 0 0 0 0 0 0 0 0 0 0
// // now start from node 8 and follow the same process  
// // 8 has two paths to go, dfs(1) and dfs(9) but 1 is already visited hence no call will be made
// // dfs(9)->dfs(10) 
// // vis           1 1 1 1 1 1 1 1 1 1 1 0
// // pathvisited   0 0 0 0 0 0 0 0 1 1 1 0
// // dfs(10)->dfs(8) 8 is visited as well as path visited hence 8 forms a
// // cycle and it's not a safe node , similarly 10 and 9 are also not safe node
// // they backtrack but path visited will not be marked to 0 it will remain 1 as
// // all of the 3 nodes 8,9,10 are not safe nodes 
// // dfs(11)->dfs(9) 9 is visited as well as path visited hence it forms a cycle
// // 11 is also not a safe node 
int V=graph.size();
vector<int>visited(V,0);
vector<int>pathVisited(V,0);
vector<int>check(V,0);
vector<int>ans;
// for(int i=0;i<V;i++){
//     if(!visited[i]){
//         dfs(i,graph,visited,pathVisited,check);
//     }
// }
// for(int i=0;i<V;i++){
//     if(check[i]==1) ans.push_back(i);
// }
// return ans;
for(int i=0;i<V;i++){
    if(!visited[i]){
        dfs(i,graph,visited,pathVisited);
    }
}
for(int i=0;i<V;i++){
    if(pathVisited[i]==false){
        ans.push_back(i);
    }
}

return ans;
    }
};

// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         //topological sorting
//         // terminal nodes are safe nodes
//         // node is a safe node if every possible path starting from that node leads to a terminal node 
//         // nodes whose outdegree are 0 considered to be terminal nodes
//         // reverse all the edges
//         // get all the nodes with indegree 0
//         // do a removal of edges on adjacent nodes 
//     // terminal nodes will have indegree as 0 
//     // push the node with indegree 0 in q, start traversing through the adjacent
//     // nodes of the node whose indegree is 0, reduce the indegree of adjacent nodes by 1 and remove the edge 
//     // if doing so make the indegree of adjacent nodes to 0 then push the adjacent node into queue
//     // if indegree of adjacent nodes become 0 it means all the incoming paths are removed
//     // repeat this until queue becomes empty 
// int V=graph.size();
//     vector<int>adjRev[V];
//     vector<int>indegree(V,0);
// for(int i=0;i<V;i++){
//     for(auto it:graph[i]){
//         adjRev[it].push_back(i);
//         indegree[i]++;
//     }
// }
// queue<int>q;
// vector<int>safeNodes;
// for(int i=0;i<V;i++){
//     if(indegree[i]==0) q.push(i);
// }
// while(!q.empty()){
// int node=q.front();
// q.pop();
// safeNodes.push_back(node);
// for(auto it: adjRev[node]){
//     indegree[it]--;
//     if(indegree[it]==0) q.push(it);
// }
// }

// sort(safeNodes.begin(),safeNodes.end());
// return safeNodes;
//     }
// };


// if there is cycle then all the nodes in the cycle can't be a terminal node
