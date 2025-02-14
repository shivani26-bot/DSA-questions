class Solution {
public:
typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // source is given as node k
    unordered_map<int,vector<pair<int,int>>>adjList;
    priority_queue<P,vector<P>, greater<P>>pq;
    for(auto it:times){
          int u=it[0];
          int v=it[1];
          int time=it[2];
          adjList[u].push_back({v,time});
    }
    int src=k;
    vector<int>distance(n+1,1e9);
    distance[src]=0;
    pq.push({0,src});
    int min_time=INT_MIN;
    while(!pq.empty()){
        int time=pq.top().first;
        int node= pq.top().second;
      
        pq.pop();
        for(auto it: adjList[node]){
                int edgeTime=it.second;
                int adjNode=it.first;
         
                if(time+edgeTime<distance[adjNode]){
                    pq.push({time+edgeTime, adjNode});
                    distance[adjNode]=time+edgeTime;
                    
       
                }
        }
    }
    // if(distance[n-1]==1e9) return -1;
    // for(int i=1;i<=n;i++){
    //    min_time=max(min_time,distance[i]);
    // }
    // return min_time==1e9?-1:min_time;

     for(int i=1;i<=n;i++){
        if(distance[i]==1e9) return -1;
       min_time=max(min_time,distance[i]);
    }
    return min_time;
    }
};