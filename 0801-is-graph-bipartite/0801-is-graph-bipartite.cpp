class Solution {
public:
// if question gives a hint like, dividing or grouping a graph in two parts then it hints toward bipartite 
// by colouring the graph we are dividing graph into two parts consisting of two different colours
bool detectBipartite(int node, vector<int>&color, vector<vector<int>>&graph){
    
    color[node]=0; //start with color 0
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int currNode= q.front();
        q.pop();
        for(auto it: graph[currNode]){
            if(color[it]==-1){
                color[it]=!color[currNode];
                q.push(it);
            }
            else if(color[it]==color[currNode]) return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
     int V=graph.size();
    //  maintain a color node instead of viited node 
    vector<int>color(V,-1); //-1 means no color
    // 0->red, 1->blue
     for(int i=0;i<V;i++){
        if(color[i]==-1){
          if(!detectBipartite(i, color, graph)) return false;
        }
     }
     return true;   
    }
};