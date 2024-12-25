class Solution {
public:
unordered_map<int,vector<int>> buildAdj(vector<vector<int>>& edges){
unordered_map<int,vector<int>>  adj;
for(auto it: edges){
    int u=it[0];
    int v=it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
return adj;
}

pair<int,int>BFS(unordered_map<int,vector<int>>adj, int source){
    queue<int>q;
    q.push(source);

    unordered_map<int,bool>visited;
    visited[source]=true;
    int distance=0;
    int farthestNode=source;

    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int curr= q.front();
            q.pop();
            farthestNode=curr;
            for(auto it: adj[curr]){
                if(visited[it]==false){
                    visited[it]=true;
                    q.push(it);
                }
            }

        }
        if(!q.empty()) distance++;
    }
    return {farthestNode, distance};
}
//diameter of undirected graph
int findDiameter(unordered_map<int,vector<int>>&adj){
// step1 find the farthest node from random node -0
auto [farthestNode,dist]=BFS(adj,0);
// step2: the farthestNOde we got above is nothing but one end of the diameter of adj 

// step3: find the farthestnode from the node we got above, that will be the other end of diameter-diameter 
auto [otherEndNode, diameter]= BFS(adj,farthestNode);
return diameter;
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // prerequistie is how to find diameter of undirected graph
        // diameter-number of edges in the longest path in graph/tree from any
        // node to any other node 
        // 1.if you choose a random node (u) and find the
        // farthest node (v) from (u), then this node (v) will always be one end
        // of the diameter of the graph
      
        // 2.the farthest node from one end of diameter ie. the other end of diameter 
        // combining point first and second, first find one end of the diameter using point 1, then find the second end of the diameter using point 2
        // to find the farthest node: we can do level order traversal, the node at farthest level will be the farthest node choose 0 as random node
        // connect middle of  one tree to middle of the other tree in order to minimize the diameter of the tree 
//      0                   0
//  3   2  1                  1 
//      3------------------------2
//   10                           3
// 11                               4
    //  consider both of them as two differnt tree 
    // middle of first tree=3, middle of second tree=2, diameter will be 6
// try to choose nodes that divides the diameters of tree1 and tree2
// d1=5, d2=4 diameter of both the trees
// find mid of d1 and d2
// ceil(d1/2)~ (d1+1)/2
// (d1+1)/2+(d2+1)/2 + 1

// corner case 
//    a                  
//   b                      
// c   d
//       e                    a
//         f---------------------b
//          g
//            h
//              i
//                j
// d1=8 , d2=1
// d1+1/2= 4, 1+1/2=1
// 4+1+1=6, but diameter is not 6
// after connecting two trees here diameter lie in tree 1 itself
// diameter =8
// hence diameter can be max(d1,d2,d1+1/2,d2+1/2)
// o(v+e) time 
unordered_map<int,vector<int>>adj1=buildAdj(edges1);
unordered_map<int,vector<int>>adj2=buildAdj(edges2);
int d1= findDiameter(adj1);
int d2=findDiameter(adj2);
int combined= (d1+1)/2+(d2+1)/2+1;
return max({d1,d2,combined});
    }
};