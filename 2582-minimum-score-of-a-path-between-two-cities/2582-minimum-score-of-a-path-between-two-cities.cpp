class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adjList(n);
        for(int i=0;i<roads.size();i++){
          int u=roads[i][0];
          int v=roads[i][1];
          int dist=roads[i][2];
          adjList[u].push_back({v,dist});
          adjList[v].push_back({u,dist});
        }
queue<pair<int,int>>q;
q.push({1,1e9}); //node, distance
int result=1e9;
vector<int>visited(n+1,0);
visited[1]=1;
while(!q.empty()){
    auto [node, dist]= q.front();

    q.pop();
    for(auto it: adjList[node]){
     
        int distance= it.second;
        int adj_node= it.first;
           result= min(result, distance);
        if(!visited[adj_node]){
            visited[adj_node]=1;

q.push({adj_node, distance});
}

    }

}
return result;
    }

};