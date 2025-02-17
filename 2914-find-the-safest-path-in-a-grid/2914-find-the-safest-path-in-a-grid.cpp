class Solution {
public:
int n;
vector<vector<int>>directions={{1,0},{0,-1},{-1,0},{0,1}};
bool isSafe(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}
vector<vector<int>>computeManhattanDistance(vector<vector<int>>& grid){
    queue<pair<int,int>>q;
    vector<vector<int>>distance(n,vector<int>(n,-1));
    vector<vector<bool>>visited(n,vector<bool>(n,false));
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j]==1) {
            visited[i][j]=true;
            q.push({i,j});
            }
    }
}

int level=0;
while(!q.empty()){

int size=q.size();

while(size--){
auto [x,y]= q.front();

q.pop();
  distance[x][y]=level;
for(auto it: directions){
    int adjX=x+it[0];
    int adjY=y+it[1];
    // if(isSafe(adjX,adjY) && !visited[adjX][adjY] )
    // {
    //     visited[adjX][adjY]=true;
    //     q.push({adjX,adjY});
    // }
     if(!isSafe(adjX,adjY) || visited[adjX][adjY] )
    {
      continue;
    }
  visited[adjX][adjY]=true;
        q.push({adjX,adjY});
}



}
level++;
}
return distance;
}

bool check(vector<vector<int>>&distance,int safe_factor){
  queue<pair<int,int>>q;
   vector<vector<bool>>visited(n,vector<bool>(n,false));
  q.push({0,0});

 visited[0][0]=true;
 if(distance[0][0]<safe_factor) return false;
  while(!q.empty()){
    auto [x,y] =q.front();
        //   int x = q.front().first;
        // int y = q.front().second;
    q.pop();
    if(x==n-1 && y==n-1) return true;
 for(const auto& it: directions) {
    int adjx=x+it[0];
    int adjy=y+it[1];
    if(isSafe(adjx,adjy) && !visited[adjx][adjy]){
//    if(adjx >= 0 && adjx < n && adjy >= 0 && adjy < n && !visited[adjx][adjy])
// {
        if(distance[adjx][adjy]<safe_factor) continue; //reject the cell
        q.push({adjx,adjy});
        visited[adjx][adjy]=true;

    }
}
  }
  return false;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
     n=grid.size();
      if (grid[n - 1][n - 1] == 1 || grid[0][0] == 1) return 0;
    //  step1, precalculation of distance of nearest thief- for each cell
    //  multisource bfs
    //   vector<vector<int>>manhattanDistance= computeManhattanDistance(grid);//distance to nearest thief
// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         cout<<manhattanDistance[i][j]<< " ";
//     }
//     cout<<endl;
// }



    queue<pair<int,int>>q;
    vector<vector<int>>manhattanDistance(n,vector<int>(n,-1));
    vector<vector<bool>>visited(n,vector<bool>(n,false));
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j]==1) {
         
            q.push({i,j});
               visited[i][j]=true;
            }
    }
}

int level=0;
while(!q.empty()){

int size=q.size();

while(size--){
auto [x,y]= q.front();

q.pop();
  manhattanDistance[x][y]=level;
for(auto it: directions){
    int adjX=x+it[0];
    int adjY=y+it[1];
    // if(isSafe(adjX,adjY) && !visited[adjX][adjY] )
    // {
    //     visited[adjX][adjY]=true;
    //     q.push({adjX,adjY});
    // }
     if(!isSafe(adjX,adjY) || visited[adjX][adjY] )
    {
      continue;
    }
     q.push({adjX,adjY});
  visited[adjX][adjY]=true;
       
}



}
level++;
}
// apply binary search 
int l=0;
int r=401;
int result=0;
while(l<=r){
    int mid=l+(r-l)/2; //safe factor
// check for the path from 0,0 to n-1,n-1 where safe factor for each cell is >=mid
if(check(manhattanDistance,mid)){
    result=mid;
    l=mid+1;
}
else{
    r=mid-1;
}
}

return result;
    }
};

// choose a path in which every cell is as far as possible from the cell 1
// choose a path in which safeness factor- minimum distance from any cell to any thief in the grid is maximum , ie maximum safeness factor

// if there is a path, in which safeness factor of each cell is 2,3,4,3,2 from the nearest theif cell 1 then safeness factor on this path is  minimum of all the safeness factor, ie 2, we have to maximize this safeness factor

// binary search on ans or safeness factor
// safeness factor can be 1,2,3,.....so on 
// low=1, high=infinity
// mid=low+high/2
// if mid=3, path whose safeness factor <= 3, means the distance of each cell in the path from the nearest thief is less than equal to 3

// in order to find nearest thief to any cell , use bfs
// visit each cell, hit bfs to find nearest thief (m*n)*bfs, it's way too costly, hence need to improve this complexity
// hence start from the thiefs ie cell = 1  and go to the nearest cell with 0
// hit bfs parallely from where cells = 1
// distance of thief from itself is 0,
//   0 1 2 3
// 0 0 0 0 1
// 1 0 0 0 0
// 2 0 0 0 0
// 3 1 0 0 0
// manhattan distance
//   0 1 2 3
// 0 3 2 1 0
// 1 2 3 2 1
// 2 1 2 3 2
// 3 0 1 2 3   => this matrix indicates each cell represent that from any cell nearest manhattan distance to thief
// start from all the cells where value is 1, and find distance to rest of the cells, multi source bfs

// queu.push({i,j}) where cell=1,
// queue => (0,3)(3,0)
// push nearest neighbors
// queue => (2,0)(3,1)(0,2)(1,3) , these all will be processed in one go ie parallely
// while popping the nodes from queue, mark the neighbors visited, just update the minimum manhattan distance from the cell,
// manhattan distance will be equal to level
// start applying binary search on manhattan distance array, l=1, r=infinity
// mid=3, then find the path in which safeness factor is >=3
// if neighbors are less than 3 then that path is not possible
// hence we will go for lower mid value high=mid-1, low=1, ie mid=2, 
//  then find the path in which safeness factor is >=2 from 0,0 to n-1,n-1

// pre calculate manhattan distance of each cells
// safeness factor->binary search
// l=1, h=infinity, mid=x
// (0,0) to (n-1,n-1)  if there is a path which all cells have value>=x

