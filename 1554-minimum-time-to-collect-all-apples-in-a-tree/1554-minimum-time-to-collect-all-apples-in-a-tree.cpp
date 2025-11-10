class Solution {
public:
// every root will ask it's child to calculate the edges 
// only consider the edge when u get some value from child, which means 
// only if child has found the apple below it
// case 1: child se time ka value mila, 2+2
//       parent ->2+2
//    child ->2
// apple
// case 2: child k paas hi apple tha,0+2
//     parent  ->0+2
// child  ->apple,0
// case 3: khi se koi apple nhi mila
//         parent 0
//      child
//  node

// if(child ne apple collect kra niche se ya toh child ke paas hi apple hai)
// time =2+child ka time
// return time
//   tree->no cycle, no need of visited array  
// don't go back to the parent 

    // dfs
//    o(v+e)
int dfs(int node,int parent, vector<vector<int>>&adjList, vector<bool>& hasApple){
 int time=0;

for(auto child: adjList[node]){

    if(child==parent) continue;
     int time_from_child= dfs(child,node, adjList,hasApple);
   if(time_from_child>0 || hasApple[child]){
    time+=(time_from_child+2);
   }
}
return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    
        vector<vector<int>>adjList(n);
//         each edge adds two entries:
//         O(E) time, where E = n - 1 for a tree.
// → So this part = O(n).
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
//    DFS visits every node once, and iterates over its adjacency list.
// In total, across the whole recursion, each edge is processed once (since you skip the parent edge).
// So, DFS = O(V + E) = O(n).
        return dfs(0, -1,adjList,hasApple);
      
    }
};

// space:
// 1. Adjacency list storage:
// Each edge stored twice → O(2E) = O(n).
// 2. Recursion stack:
// In worst case (a skewed tree), recursion depth = O(n).