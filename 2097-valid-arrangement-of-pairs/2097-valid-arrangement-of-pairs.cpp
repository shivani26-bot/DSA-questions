class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Hierholzer's algorithm -> for find euler path
        // choose starting point
        // visit all edge once

// euler path already exists as it's given in the question 
// directed graph
// here in the final valid arrangement all the edges are visited once 
// starting node for euler path is the node where outdegree[node]-indegree[node]==1 for directed graph 
// We use hierholzers algorithm for euler path
// Build adjacency list
// Build indegree and outdegree (for directed graph)
// Find start node of euler path
// Take a vector which will store all the euler path
// vector<int>eulerPath;

// Input: pairs = [[5,1],[4,5],[11,9],[9,4]];
// 5->{1}
// 4->{5}
// 11->{9}
// 9->{4}
// 11->9->4->5->1
// indegree => 1 4 5 9 11
//             1 1 1 1 0 
// outdegree=> 1 4 5 9 11
//             0 1 1 1 1

// start point= outdegree[node]-indegree[node]=1
// end point= indegree[node]-outdegree[node]=1
// choose the startnode=11
// start=11, end=1
// then traverse the array using dfs via adjList, when we go back in  dfs we get the path
// 1,5,4,9,11
// o(v+e) complexity of dfs 
unordered_map<int,vector<int>>adj;

unordered_map<int,int>indegree,outdegree;
// key=node, value=indegree/outdegree

for(auto it: pairs){
    int u=it[0];
    int v=it[1];
    adj[u].push_back(v); //u->v
    outdegree[u]++;
    indegree[v]++;
}
int startNode=pairs[0][0];
for(auto it: adj){
    int node=it.first;
    if(outdegree[node]-indegree[node]==1){
        startNode=node;
        break;
    }
}

vector<int>Eulerpath;
stack<int>st; //to perform dfs;
st.push(startNode);

while(!st.empty()){
    int curr=st.top();
    if(!adj[curr].empty()){
        int ngbr=adj[curr].back();
        adj[curr].pop_back();
        st.push(ngbr);
    }
    else{
        Eulerpath.push_back(curr);
        st.pop();
    }
}

// build your result 
reverse(begin(Eulerpath),end(Eulerpath));
vector<vector<int>>result;
for(int i=0;i<Eulerpath.size()-1;i++){
result.push_back({Eulerpath[i],Eulerpath[i+1]});
}
return result;
    }
};