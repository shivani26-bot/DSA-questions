class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
//  floyd warshall, shortest path, for multipoint source 
// make a  adjacency matrix for 26 characters 
vector<vector<long long>>adj(26,vector<long long>(26,1e9));
int n=original.size();
// duplicate entries are allowed in original and changed , store the minimum cost for the duplicate entries
// it's a directed graph 
for(int i=0;i<n;i++){
    int sIndex=original[i]-'a';
    int tIndex=changed[i]-'a';
 adj[sIndex][tIndex]=min(adj[sIndex][tIndex],(long long)cost[i]);
}
for(int k=0;k<26;k++){
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
        }
    }
}
long long ans=0;
for(int i=0;i<source.size();i++){
    if(source[i]==target[i]) continue;
    if(adj[source[i]-'a'][target[i]-'a']==1e9) return -1;
    ans+=adj[source[i]-'a'][target[i]-'a'];
}
return ans;
    }
};