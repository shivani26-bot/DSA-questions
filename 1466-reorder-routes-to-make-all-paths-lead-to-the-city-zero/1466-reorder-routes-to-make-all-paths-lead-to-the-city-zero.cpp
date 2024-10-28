class Solution {
public:
// void dfs(int node, vector<vector<int>>&adj,int &count, vector<bool>&visited){

// if(visited[node]) return;
//     visited[node]=true;

//     for(auto neighbor: adj[node]){
//         if(!visited[abs(neighbor)])
//             if(neighbor>0) count++;
        
//         dfs(abs(neighbor),adj,count,visited);
//     }
// }
//     int minReorder(int n, vector<vector<int>>& connections) {
//         vector<vector<int>>adj(n);

//         for(int i=0;i<connections.size();i++){
//             int u=connections[i][0];
//             int v=connections[i][1];
//             adj[u].push_back(v);// Forward edge u -> v //real edge
//             adj[v].push_back(-u); // Reverse edge v -> u //fake edge
//         }
//         int count=0;
//         vector<bool>visited(n,false);
//         // start from node 0
//         dfs(0,adj,count,visited);
//         return count;

// //    we should make edges so that we can travel in both the directions 
//     }


void dfs(int node,int parent, unordered_map<int,vector<pair<int,int>>>&adj,int &count){

    for(auto neighbor: adj[node]){
       
        int v=neighbor.first;
        int check=neighbor.second;
      
        if(v!=parent){
              if(check==1) count++; //1->real edge 0-> fake edge 
                dfs(v,node,adj, count);
        }
      
    }
    
}
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back({v,1});// Forward edge u -> v //real edge
            adj[v].push_back({u,0}); // Reverse edge v -> u //fake edge
        }
        int count=0;

        // start from node 0
        dfs(0,-1,adj,count);
        return count;

//    we should make edges so that we can travel in both the directions 
    }
};