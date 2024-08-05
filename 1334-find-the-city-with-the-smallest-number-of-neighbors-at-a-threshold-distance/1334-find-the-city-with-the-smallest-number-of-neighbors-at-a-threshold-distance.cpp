class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//for every node check what are the possible node we can travel with distance less than equal to distanceThreshold
//the answer will be smallest number of cities that can be travelled
//if exists multiple cities with same number of smallest cities then answer will be the the node or city with largest value 
//this is floyyd warshal algorithm as we are finding distance considering multiple sources 
//make a adjacency matrix that represent the distance between each node 
// maintain a variable count=0, iterate through the adjacency matrix and if distance <= distanceThreshold then increase the count
// for every row represent a source node and every column as destination node this count will keep track that for a particular source
// how many destination was reached by the source node with distance <= distanceThreshold
// maintain a countmin, and city which indicate the city number with largest value that reach the minimum number of other city
// floyd warshal works for directed graph if undirected graph then change to directed graph 
vector<vector<int>>distance(n,vector<int>(n,1e9));
for(auto it: edges){
    distance[it[0]][it[1]]=it[2];
    distance[it[1]][it[0]]=it[2];
}
for(int i=0;i<n;i++) distance[i][i]=0;
for(int k=0;k<n;k++){
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
    }
 }
}
int countCity=n; //suppose all the n cities can be reached by a particular city with distance <= threshold distance
int cityNo=-1;
for(int i=0;i<n;i++){
    int count=0;
    for(int j=0;j<n;j++){
    if(distance[i][j]<=distanceThreshold){
          count++;
      }
       }
      if(count<=countCity){
        countCity=count;
        cityNo=i;
      }
   
}
return cityNo;
}
};