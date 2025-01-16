class Solution {
public:
// int n,m;
// vector<vector<int>>directions={
//     {0,1},{1,0},{0,-1},{-1,0}
// };
// bool isSafe(int i,int j){
//     return (i>=0 && i<n && j>=0 && j<m);
// }

 int m, n;
    vector<vector<int>> directions = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    
    bool isSafe(int i, int j) {
        return (i < m && i >= 0 && j < n && j >= 0);
    }
     void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int, int>>& visitedCell) {
        if(!isSafe(i, j) || grid[i][j] == 0 || visitedCell.find({i, j}) != visitedCell.end()) {
            return;
        }
        
        visitedCell.insert({i, j});
        
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            dfs(grid, i_, j_, visitedCell);
        }
    }
      int bfs(vector<vector<int>>& grid, set<pair<int, int>>& visitedCell) {
        queue<pair<int, int>> que;
        
        for(auto &it : visitedCell) {
            
            que.push({it});
            
        }
        
        int level = 0;
        
        while(!que.empty()) {
            int L = que.size();
            
            while(L--) {
                pair<int, int> P = que.front();
                que.pop();
                
                for(auto &dir : directions) {
                    int i_ = P.first + dir[0];
                    int j_ = P.second + dir[1];

                    if(isSafe(i_, j_) && visitedCell.find({i_, j_}) == visitedCell.end()) {
                        if(grid[i_][j_] == 1) //found another island
                            return level;
                        
                        visitedCell.insert({i_, j_});
                        que.push({i_, j_});
                    }
                }
                
            }
            level++;
        }
        
        return level;
    }
    
// void dfs(vector<vector<int>>&grid,int i,int j, set<pair<int,int>>&visited){
//     if(!isSafe(i,j) || grid[i][j]==0 ||  visited.find({i,j})!=visited.end())

//     return;

// visited.insert({i,j});//unvisitedcell with value 1


// for(auto it: directions){
//     int i_=i+it[0];
//     int j_=j+it[1];
//     dfs(grid,i_,j_,visited);
// }
// }
// int bfs(vector<vector<int>>& grid,set<pair<int,int>>&visited){
//     queue<pair<int,int>>q;
//     for(auto it:visited){
//         q.push(it);
//     }
//     int level=0;
//     while(!q.empty()){
//         int sz=q.size();
//         while(sz--){
//         //   auto [x,y]=q.front();
//           int x=q.front().first;
//           int y=q.front().second;
//            for(auto it: directions){
//             int x_= x+it[0];
//             int y_=y+it[1];
//             if(isSafe(x_,y_) && visited.find({x_,y_})== visited.end()){
//                 if(grid[x_][y_]==1)  //we found 2nd island
//                 return level;
                     
                
//                 visited.insert({x_,y_});
//                 q.push({x_,y_});
//             }
//            }
//         }
//         level++;
//     }
//     return level;
// }
    int shortestBridge(vector<vector<int>>& grid) {
        // shortest path- bfs, dijkstra- single source single destination
        // but in this question we have multiple source multiple destination
        //  hene we can use bfs here

        // with dfs first island will be covered and populated visited array
// put elements of visited array into queu, and run bfs, as soon as we encounter a 1 ie not visited already it means its our second island
//  n=grid.size();
//  m=grid[0].size();
//       set<pair<int,int>>visited;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1){
//                     dfs(grid,i,j,visited);
// return bfs(grid,visited);
//                 }
//             }
//         }
   
     
// return -1;
 m = grid.size();
        n = grid[0].size();
        
        set<pair<int, int>> visitedCell;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, visitedCell); //It will mark one island visited
                    return bfs(grid, visitedCell);
                }
                
            }
        }
        
        return -1;

    } 
};