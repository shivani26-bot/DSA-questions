class Solution {
public:
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
//         vector<pair<int,double>>adj[n];
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
//             adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
//         }

// for(int i=0;i<n;i++){

// for(auto it: adj[i]){
//     cout<<it.first<<" "<<it.second<<endl;
// }
// }
// // probability from going start_node to start_node will be 1, 
//      vector<double>dist(n,0.0);
//      dist[start_node]=1.0;
//     //  here we will use maxheap , because we are trying to maximize the probability of success, we always want the node with maximum product
//      priority_queue<pair<int,double>>pq;
//     pq.push({start_node,1.0});
//     while(!pq.empty()){
//         double distance=pq.top().second;
//         int node=pq.top().first;
//         pq.pop();
//         for(auto it: adj[node]){
//             int adjNode= it.first;
//             double edgeWeight=it.second;
//             if(distance*edgeWeight>dist[adjNode]){
//                 dist[adjNode]=distance*edgeWeight;
//                 pq.push({adjNode,dist[adjNode]});
//             }
//         }
//     }
//         return dist[end_node];
//     }


    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<double,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }

for(int i=0;i<n;i++){

for(auto it: adj[i]){
    cout<<it.first<<" "<<it.second<<endl;
}
}

     vector<double>dist(n,0.0);//finds distance from start node to every other node
     dist[start_node]=1.0;
  
     priority_queue<pair<double,int>>pq;
    pq.push({1.0,start_node});
    while(!pq.empty()){
        double distance=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(node==end_node) return distance;
        for(auto it: adj[node]){
            int adjNode= it.second;   
            double edgeWeight=  it.first;
            if(distance*edgeWeight>dist[adjNode]){
                dist[adjNode]=distance*edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
        // return dist[end_node];
          return 0;
    }
};