class Solution {
public:
#define P pair<int,pair<int,int>>
int m, n;
bool isSafe(int x, int y){
  return x>=0 && x<m && y>=0 && y<n;
}
    int minCost(vector<vector<int>>& grid) {
//         A cell is marked as visited (visitedCell.insert({x, y})) as soon as it is processed. This prevents revisiting the cell even if a cheaper path is found later. However, Dijkstra's algorithm (used here) requires updating the cost if a better path is found to a previously visited cell.

// Solution:
// Remove the visitedCell set and rely on a 2D cost matrix to track the minimum cost to reach each cell. Only update the cell if a smaller cost is found.
//wrong approach
//         priority_queue<P,vector<P>, greater<P>>minHeap;
//        minHeap.push({0,{0,0}}); //cost , {x,y}
// set<pair<int,int>>visitedCell;
// vector<pair<int,pair<int,int>>>directions={{1,{1,0}},{2,{-1,0}},{3,{0,-1}},{4,{0,1}}};
//  m=grid.size();
// n=grid[0].size();
//        while(!minHeap.empty()){
//         int cost=minHeap.top().first;
//         auto [x,y]=minHeap.top().second;
//         minHeap.pop();
//         if(x==m-1 && y==n-1) return cost;
//         //  if (visitedCell.find({x, y}) != visitedCell.end()) continue;
//         // visitedCell.insert({x,y});
//         int nextDirection=grid[x][y];
//         for(auto &dir: directions){
//               int direction=dir.first;
//               int adjX=x+dir.second.first;
//               int adjY=y+dir.second.second;
//               if(isSafe(adjX,adjY) && visitedCell.find({adjX,adjY})==visitedCell.end()){

//  if(direction==nextDirection){
//                 minHeap.push({cost,{adjX,adjY}});
//               }
//               else {
//                     minHeap.push({1+cost,{adjX,adjY}});
//               }
//               }
             
//         }
//        }
//        return -1;

        priority_queue<P,vector<P>, greater<P>>minHeap;
       minHeap.push({0,{0,0}}); //cost , {x,y}

vector<vector<int>>directions={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//  vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
 m=grid.size();
n=grid[0].size();
// to find the minimum cost, using dijkstra make a 2d cost array which will keep track of minimum cost to reach a particular cell in the 2d matrix
vector<vector<int>>cost(m,vector<int>(n, INT_MAX));
cost[0][0]=0;

while(!minHeap.empty()){
    int currCost=minHeap.top().first;
    auto [x,y]=minHeap.top().second;
    minHeap.pop();
//    if(cost[x][y]<currCost) continue;
    for(int i=0;i<4;i++){
        int adjX=x+directions[i][0];
        int adjY=y+directions[i][1];
        if(isSafe(adjX,adjY)){
            int gridDir= grid[x][y];
        int dirCost=(gridDir-1!=i)? 1:0;
        int newCost=currCost+dirCost;
        if(newCost<cost[adjX][adjY]){
            cost[adjX][adjY]=newCost;
            minHeap.push({newCost,{adjX,adjY}});
        }
        }
    }
}
return cost[m-1][n-1];
    }
};