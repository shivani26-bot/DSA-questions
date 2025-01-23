class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;// store cells with value 1 ie land
        vector<vector<int>>visited=grid;
        //1->visited, 2->not visited
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==1) {
                    q.push({i,j});
                }
            }
        }
        //edgecase
// if there is no land cells or no water cells
// no water cells, all the cells are land q.size()==n*n
if(q.size()==n*n || q.empty()) return -1;
        vector<pair<int,int>>directions={{1,0},{0,-1},{-1,0},{0,1}};
        int distance=-1;
        while(!q.empty()){
            int size= q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]: directions){
              int x_=x+dx; //adjx
              int y_=y+dy; //adjy
              if(x_>=0 && x_<n && y_>=0 && y_<n && visited[x_][y_]==0 ){
                visited[x_][y_]=1;
                q.push({x_,y_});
              }

                }
            }
            distance++;
        }
        return distance;
    }
};