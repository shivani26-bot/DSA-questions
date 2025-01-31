class Solution {
public:
//this is a graph question
// adj list
// a/b=>a->(b,weight)
//     b->(a,1/weight)
// use bfs or dfs 
// query=>a/c=>a=source, c=destination
// product=1
void dfs(string src, string dest,unordered_map<string,vector<pair<string,double>>>&adjList,unordered_set<string>&visited, double product, double &ans ){
    if(visited.find(src)!=visited.end()) return;
visited.insert(src);
if(src==dest){
    ans=product;
    return;
}
for(auto it: adjList[src]){
    string v=it.first;
    double val=it.second;
    dfs(v,dest,adjList,visited,product*val,ans);
}
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       unordered_map<string,vector<pair<string,double>>>adjList;
       
       for(int i=0;i<equations.size();i++){
        string u=equations[i][0];
        string v=equations[i][1];
        adjList[u].push_back({v,values[i]});
         adjList[v].push_back({u,1.0/values[i]});
       }
vector<double>result;

for(auto it: queries){
    string src=it[0];
    string dest=it[1];
    double product=1.0;
    double ans=-1.0;
    if(adjList.find(src)!=adjList.end()){
           unordered_set<string>visited;
    dfs(src,dest,adjList,visited,product,ans);
    }
    result.push_back(ans);
}
return result;
    }
};