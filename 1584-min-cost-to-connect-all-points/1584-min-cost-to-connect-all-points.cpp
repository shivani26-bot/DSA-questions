class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
    //    minimum spanning tree- all the points should be connected with minimum weight
    // make a adjlist  from all the points , one node can be connected to rest of all the nodes
    // int n=points.size();
    // unordered_map<int, vector<pair<int,int>>>adj;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n; j++){
    //         int distance= abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
    //         adj[i].push_back({j,distance});
    //         adj[j].push_back({i,distance});
    //     }
    // }
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    // int minCost=0;
    // pq.push({0,0});
    // vector<int>visited(n,0);
    // while(!pq.empty()){
    //     auto it= pq.top();
    //     int node=it.second;
    //     int wt=it.first;
    //     pq.pop();
    //     if(visited[node]) continue;
    //     visited[node]=1;
    //     minCost+=wt;
    //     for(auto it: adj[node]){
    //         int adjNode=it.first;
    //         int edgeWt=it.second;
    //         if(!visited[adjNode]){
    //             pq.push({edgeWt,adjNode});
    //         }
    //     }
    // }
    // return minCost;


    int n=points.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    unordered_map<int,int>cache;
    int min_cost=0;
vector<int>visited(n,0);
    while(!pq.empty()){
        auto [wt,node]=pq.top();
        pq.pop();

if(visited[node]) continue;
visited[node]=1;
min_cost+=wt;
for (int i=0;i<n;i++){ //for ever current node, try to check from 0 to nth node
    if(!visited[i]){
    int dist=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
// agr distance node se i tkk ka less hai than stored distance to reach i in cache , update the cache
if(cache.find(i)==cache.end() || dist<cache[i]){
    cache[i]=dist;
    pq.push({dist, i});
}
    }
}
    }
return min_cost;
    }
};