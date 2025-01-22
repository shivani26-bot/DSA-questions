class Solution {
public:
// edges = [2,2,3,-1], node1 = 0, node2 = 1
//         0   1   2   3
// dist1=  inf inf inf inf
// node1=0  0  inf  1   2
// node2=1 inf  0   1   2
int n;
void dfs(int node, vector<int>&edges,vector<int>&distance,vector<bool>&visited){
visited[node]=true;
int v=edges[node];
if(v!=-1 && !visited[v]){

    distance[v]=1+distance[node];
    dfs(v,edges,distance,visited);
}
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n=edges.size();
      vector<int>dist1(n,INT_MAX); //will store distance of all other nodes from node1
       vector<int>dist2(n,INT_MAX); //will store distance of all other nodes from node1

vector<bool>visited1(n,false);
vector<bool>visited2(n,false);
dist1[node1]=0;
dist2[node2]=0;


      dfs(node1,edges,dist1,visited1);
       
      dfs(node2,edges,dist2,visited2);
int minDistanceNode=-1;
int minDistanceTillNow=INT_MAX;
      for(int i=0;i<n;i++){
        int maxDistance=max(dist1[i],dist2[i]);
        if(minDistanceTillNow>maxDistance){
              minDistanceNode=i;
            minDistanceTillNow=maxDistance;
          
        }
      }
      return minDistanceNode;
    }
};