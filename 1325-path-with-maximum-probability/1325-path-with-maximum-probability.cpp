class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

for(int i=0;i<n;i++){

for(auto it: adj[i]){
    cout<<it.first<<" "<<it.second<<endl;
}
}
// probability from going start_node to start_node will be 1, 
     vector<double>dist(n,0.0);
     dist[start_node]=1.0;
    //  here we will use maxheap , because we are trying to maximize the probability of success, we always want the node with maximum product
     priority_queue<pair<int,double>>pq;
    pq.push({start_node,1.0});
    while(!pq.empty()){
        double distance=pq.top().second;
        int node=pq.top().first;
        pq.pop();
        for(auto it: adj[node]){
            int adjNode= it.first;
            double edgeWeight=it.second;
            if(distance*edgeWeight>dist[adjNode]){
                dist[adjNode]=distance*edgeWeight;
                pq.push({adjNode,dist[adjNode]});
            }
        }
    }
        return dist[end_node];
    }
};