class Solution {
public:
int dfs(unordered_map<int,vector<int>>&adj, int node, int parent, int seats, long long& totalFuels){
    int representative=1; //each city has one representative
    // traverse through neighbors of node
    for(auto it: adj[node]){
        if(it==parent) continue;
        representative+=dfs(adj,it,node, seats,totalFuels);
    }
    if(node!=0) //if current node is node capital node
    {
        // calculate number of cars required :ceil(representative/seats) (representative+seat-1)
        // each car consume 1 litre of fuel
        totalFuels+=(representative+seats-1)/seats;
    }
    return representative;
}
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
       
       unordered_map<int,vector<int>>adj;
       for(auto it: roads){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }

     long long totalFuel=0;
       dfs(adj,0,-1,seats,totalFuel); //start from node 0 and parent -1
       return totalFuel;
    }
};