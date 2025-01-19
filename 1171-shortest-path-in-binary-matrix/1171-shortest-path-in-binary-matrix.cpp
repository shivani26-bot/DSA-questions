class Solution {
public:
int n;
bool isSafe(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    n=grid.size();
       
        queue<pair<int,int>>q;
            if(grid[0][0]==1) return -1;
        q.push({0,0});
    vector<vector<int>>directions={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
 set<pair<int,int>>visited;   
    int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
     auto [x,y]=q.front();
            q.pop();
            if(x==n-1 && y==n-1) return level+1;


            for(auto it: directions){
                int adjX=x+it[0];
                int adjY=y+it[1];
                if(isSafe(adjX,adjY) && grid[adjX][adjY]==0 && visited.find({adjX,adjY})==visited.end()){
                    visited.insert({adjX,adjY});
                   q.push({adjX,adjY});
                }
            }
            }
            level++;
       
        }
        return -1;
    }
};