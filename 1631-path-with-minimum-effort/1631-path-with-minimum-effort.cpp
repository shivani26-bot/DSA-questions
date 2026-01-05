class Solution {
public:
// bool isValid(int adjRow,int adjCol,int n,int m,vector<vector<int>>&heights){
//     return adjRow>=0 && adjRow<n && adjCol>=0 && adjCol<m;
// }
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         // when source or destination is involved , use dijkstra algorithm 
//         // initial configuration 
//     //     use priority queue, store {difference, {row, col}}
//     //     use 2d distance or difference array , initialize with infinite and source with 0,
//     // for a path, effort is maximum of all the differences in that path
//     // and result is minimum effort out of all the path
//     // initially (0,0,0) will be in priority queue
    
//   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
// int n=heights.size();
// int m=heights[0].size();
// vector<vector<int>>difference(n,vector<int>(m,1e9));
//     difference[0][0]=0;
//     pq.push({0,{0,0}});
    // int dr[]={-1,0,1,0};
    // int dc[]={0,1,0,-1};

//     while(!pq.empty()){
//         int currRow=pq.top().second.first;
//         int currCol=pq.top().second.second;
//         int diff= pq.top().first;
//         pq.pop();
//         // if we reach the destination then it means that this is the answer and we 
//         // will not get better answer than this in future, because priority queue always
//         // gives the minimum value
//         if(currRow==n-1 && currCol==m-1) return diff;
//         for(int i=0;i<4;i++){
//             int adjRow=currRow+dr[i];
//             int adjCol=currCol+dc[i];
//             if(isValid(adjRow,adjCol,n,m,heights) ){
//                 // always take the maximum difference in the path
// int newEffort=max(abs(heights[currRow][currCol]-heights[adjRow][adjCol]), diff);
// if(newEffort<difference[adjRow][adjCol])
// {
//     // the difference for the adjacent row and column will be updated only
//     // when it has new value is less than existing value, as we want minimum effort out 
//     // of all path
//     difference[adjRow][adjCol]=newEffort;
//     pq.push({newEffort,{adjRow,adjCol}});
// }
//             }
//         }
//     }
//     return 0;
//     }


typedef pair<int,pair<int,int>> P;
int m,n;
bool isSafe(int adj_x, int adj_y){
    return adj_x>=0 && adj_y>=0 && adj_x<m && adj_y<n;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
     m=heights.size();
 n=heights[0].size();

     vector<vector<int>>difference(m,vector<int>(n,1e9));
     priority_queue<P,vector<P>, greater<P>>q;
     difference[0][0]=0;//to reach from 0 to 0 cost is 0
     q.push({0,{0,0}});
     int dx[]={1,0,-1,0};
     int dy[]={0,-1,0,1};
    //   int dx[]={-1,0,1,0};
    // int dy[]={0,1,0,-1};
     while(!q.empty()){
        int diff=q.top().first;
        int x= q.top().second.first;
        int y=q.top().second.second;
q.pop();
if(x==m-1 && y==n-1) return diff;
        for(int i=0;i<4;i++){
            int adj_x= x+dx[i];
            int adj_y= y+dy[i];

            if(isSafe(adj_x,adj_y)){
               int newEffort= max(abs(heights[x][y]-heights[adj_x][adj_y]), diff);
             if(newEffort<difference[adj_x][adj_y]){
                difference[adj_x][adj_y]=newEffort;
                q.push({newEffort,{adj_x,adj_y}});
             }
            }
        }
     }
     return 0;
    }
};