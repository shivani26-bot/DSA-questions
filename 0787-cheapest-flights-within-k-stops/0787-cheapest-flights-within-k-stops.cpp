class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
    queue<pair<int,pair<int,int>>>q;
    // {stops,{src,cost}};
    q.push({0,{src,0}});
    // storing min cost for a particular node
    vector<int>cheapPriceDist(n,1e9);
    cheapPriceDist[src]=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int node=it.second.first;
        int cost=it.second.second;
        if(stops>k)
         continue;

        for(auto i: adj[node]){
            int adjNode=i.first;
            int edgeWeight=i.second;
            if(cost+edgeWeight<cheapPriceDist[adjNode] && stops<=k){
                cheapPriceDist[adjNode]=cost+edgeWeight;
                q.push({stops+1,{adjNode,cost+edgeWeight}});
            }
        }
    }
    if(cheapPriceDist[dst]==1e9) return -1;
    return cheapPriceDist[dst];

    }
};