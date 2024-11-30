class Solution {
public:
#define P pair<int,pair<int,int>> 
// {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int minimumTime(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        if(grid[0][1] >1 && grid[1][0]>1) return -1;

        // 0     1000  1
        // 1000  20    2
        // 5     4     3


        // 1   1   10 2
        // 50  15  2   5
        // 40  3   8   6 here atleast we can go to next cell (0,1) and then we can move back and forth from (0,1) to (0,0) and can increase the time to be able to move to next cell

// when we are at (0,1) to move to (0,2) we need time =9 at (0,1) for that we keep moving from (0,1) to (0,0) and increase the time

// 0 1 10
// . . .
// . . .  here difference is odd 10-1=9 move back and forth from (1,0) to (0,0) , hence we will reach index (0,2) with value 10 ie grid[0][2]

// 0 1 11
// . . .
// . . .here difference is even 11-1=10  move back and forth from (1,0) to (0,0) , hence we will reach index (0,2) with value 12 ie grid[0][2]+1
//         vector<vector<int>>distance(m,vector<int>(n,INT_MAX));
//         distance[0][0] =0;
//         vector<vector<bool>>visited(m,vector<bool>(n,false));
//         priority_queue<P,vector<P>,greater<P>>pq;
//     //    { time, {i,j}}
//         pq.push({0,{0,0}});
//         while(!pq.empty()){
//              int time=pq.top().first;
//              int r=pq.top().second.first;
//              int c=pq.top().second.second;
//              pq.pop();


// if(r==m-1 && c==n-1) return distance[m-1][n-1];

// if(visited[r][c]==true) continue;
// visited[r][c]=true;
//              for(auto it: directions){
//                 int adjr=r+it[0];
//                 int adjc=c+it[1];
//                 if(adjr<0 || adjr>=m || adjc<0 ||adjc>=n || visited[adjr][adjc]) continue;
               
//                 if(time+1>=grid[adjr][adjc]){
//                      distance[adjr][adjc]=time+1;
//                      pq.push({time+1,{adjr,adjc}});
//                 }
//                 else if((grid[adjr][adjc]-time)%2 ==0){
//                     pq.push({grid[adjr][adjc]+1,{adjr,adjc}});
//                     distance[adjr][adjc]=grid[adjr][adjc]+1;
//                 }
//                 else{
//                     //odd
//                      pq.push({grid[adjr][adjc],{adjr,adjc}});
//                     distance[adjr][adjc]=grid[adjr][adjc];
//                 }
//              }
//         }
//         return -1;


 vector<vector<int>>distance(m,vector<int>(n,INT_MAX));
        distance[0][0] =0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<P,vector<P>,greater<P>>pq;
    //    { time, {i,j}}
        pq.push({0,{0,0}});
        while(!pq.empty()){
             int time=pq.top().first;
             int r=pq.top().second.first;
             int c=pq.top().second.second;
             pq.pop();

if(visited[r][c]==true) continue;
visited[r][c]=true;
             for(auto it: directions){
                int adjr=r+it[0];
                int adjc=c+it[1];
                if(adjr<0 || adjr>=m || adjc<0 ||adjc>=n || visited[adjr][adjc]) continue;
               
                if(time+1>=grid[adjr][adjc]){
                     distance[adjr][adjc]=time+1;
                     pq.push({time+1,{adjr,adjc}});
                }
                else if((grid[adjr][adjc]-time)%2 ==0){
                    pq.push({grid[adjr][adjc]+1,{adjr,adjc}});
                    distance[adjr][adjc]=grid[adjr][adjc]+1;
                }
                else{
                    //odd
                     pq.push({grid[adjr][adjc],{adjr,adjc}});
                    distance[adjr][adjc]=grid[adjr][adjc];
                }
             }
        }
        return distance[m-1][n-1];
    }
};