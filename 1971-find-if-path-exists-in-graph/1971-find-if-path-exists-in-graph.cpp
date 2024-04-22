class Solution {
public:
vector<bool>visited;
vector<vector<int>>adjList;

void dfs(int node){
    if(visited[node]) return;
visited[node]=true;
for(auto it: adjList[node]){
    if(!visited[it]){
        dfs(it);
    }
}

}

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//    start traversal from source node and check whether we can reach to destination node or not
visited=vector<bool>(n,false);
adjList=vector<vector<int>>(n);

        // o(n)
for(auto edge: edges){
    adjList[edge[0]].push_back(edge[1]);
    adjList[edge[1]].push_back(edge[0]);
}
// o(m)
dfs(source);
return visited[destination];
        
        // total time complexiy: o(n+m )
        // space: o(n)
        
        // we can also solve the question using dsu 
    }
};