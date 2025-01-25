class Solution {
public:
// keep track of previous edge color also
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
     
        vector<vector<pair<int,int>>>adjList(n);
        for(auto it: redEdges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back({v,1}); 
        }
          for(auto it: blueEdges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back({v,2}); 
        }
        vector<vector<int>>dist(n,vector<int>(3,1e9));
//         dist[i][1] stores the shortest distance to node i using a red edge as the last edge in the path.
// dist[i][2] stores the shortest distance to node i using a blue edge as the last edge in the path.
// dist[i][0] (used only for initialization) tracks distances starting at node 0 with no edge color constraint.
        
     
        queue<pair<int,int>>q;
        // 1->red, 2->blue
        q.push({0,0}); //initially 0 color it means the node 0 has no previous edge
        dist[0][0]=0; //dist[0][0] = 0; // Distance to node 0 with no edge is 0.

                while(!q.empty()){
                 
 auto [node,prevEdgeCol] =q.front();
            q.pop();
      
                    
           
            for(auto it:adjList[node]){
                
                // auto [adjNode, col]=it
                int adjNode=it.first;
                int currEdgeCol=it.second;
    
                    if( currEdgeCol!=prevEdgeCol && dist[adjNode][currEdgeCol]==1e9)
                    {
                    q.push({adjNode,currEdgeCol});           
                    // ans[adjNode]=ans[node]+1;
                 dist[adjNode][currEdgeCol]=dist[node][prevEdgeCol]+1;

}
                   
                
               
            
                    }
     
            
        }
//         After BFS, the shortest distance to each node is the minimum of dist[i][1] (red last edge) and dist[i][2] (blue last edge).
// If no valid path exists, the result is set to -1.
        vector<int>ans(n,0);
        for(int i=1;i<n;i++){
            ans[i]=min(dist[i][1],dist[i][2]);
            if(ans[i]==1e9) ans[i]=-1;
        }

        return ans;
    }
};