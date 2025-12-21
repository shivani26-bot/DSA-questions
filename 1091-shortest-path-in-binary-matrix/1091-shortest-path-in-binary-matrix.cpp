class Solution {
public:
// we can also use dijkstra here
int n;
bool isSafe(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}
//    3
//  0----2
//  1\   /1
//     1 
    // if we want to reach 0 to 2 with shortest path, if we use bfs it shortest path will be 3
    // but if we use dijkstra shortest path will be 2
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


//using dijkstra
// typedef pair<int,pair<int,int>> P;
// int n;
// bool isSafe(int x, int y){
//     return x>=0 && x<n && y>=0 && y<n;
// }
// int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//    n=grid.size();
// //    m=grid[0].size();
    
//         if(n==0 || grid[0][0]!=0) return -1;
//        priority_queue<P,vector<P>,greater<P>>pq;
//        vector<vector<int>>distance(n,vector<int>(n,1e9));//will contain the min distance to reach from 0,0 to all the other cells
//        vector<vector<int>>directions={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
     
//         grid[0][0]=1;         // also mark it as visited, not required as  using minheap will always take the smallest distance first
//          distance[0][0]=0;
//        pq.push({0,{0,0}}); //{distance,{x,y}}

//         while(!pq.empty()){
//           int dist= pq.top().first;
//           int x=pq.top().second.first;
//           int y=pq.top().second.second;
//  pq.pop();
//           for(int i=0;i<8;i++){
          
//   int adj_x= x+directions[i][0];
//   int adj_y= y+directions[i][1];
// // int d=1;
// //     if(isSafe(adj_x,adj_y) && grid[adj_x][adj_y]==0 && d+dist<distance[adj_x][adj_y]){



// //     pq.push({d+dist,{adj_x,adj_y}});
// //     grid[adj_x][adj_y]=1;
// //         distance[adj_x][adj_y]=1+dist;

// //             }


//     if(isSafe(adj_x,adj_y) && grid[adj_x][adj_y]==0 ){

// if(1+dist<distance[adj_x][adj_y]){

//     pq.push({1+dist,{adj_x,adj_y}});
//     grid[adj_x][adj_y]=1;
//         distance[adj_x][adj_y]=1+dist;
// }
//             }
//           }

       
//         }
//         if(distance[n-1][n-1]==1e9) return -1;//not reachable
//         return distance[n-1][n-1]+1;
//     }
};