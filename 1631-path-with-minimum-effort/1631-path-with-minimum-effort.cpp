class Solution {
public:
bool isValid(int adjRow,int adjCol,int n,int m,vector<vector<int>>&heights){
    return adjRow>=0 && adjRow<n && adjCol>=0 && adjCol<m;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        // when source or destination is involved , use dijkstra algorithm 
        // initial configuration 
    //     use priority queue, store {difference, {row, col}}
    //     use 2d distance or difference array , initialize with infinite and source with 0,
    // for a path, effort is maximum of all the differences in that path
    // and result is minimum effort out of all the path
    // initially (0,0,0) will be in priority queue
    
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
int n=heights.size();
int m=heights[0].size();
vector<vector<int>>difference(n,vector<int>(m,1e9));
    difference[0][0]=0;
    pq.push({0,{0,0}});
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};

    while(!pq.empty()){
        int currRow=pq.top().second.first;
        int currCol=pq.top().second.second;
        int diff= pq.top().first;
        pq.pop();
        // if we reach the destination then it means that this is the answer and we 
        // will not get better answer than this in future, because priority queue always
        // gives the minimum value
        if(currRow==n-1 && currCol==m-1) return diff;
        for(int i=0;i<4;i++){
            int adjRow=currRow+dr[i];
            int adjCol=currCol+dc[i];
            if(isValid(adjRow,adjCol,n,m,heights) ){
                // always take the maximum difference in the path
int newEffort=max(abs(heights[currRow][currCol]-heights[adjRow][adjCol]), diff);
if(newEffort<difference[adjRow][adjCol])
{
    // the difference for the adjacent row and column will be updated only
    // when it has new value is less than existing value, as we want minimum effort out 
    // of all path
    difference[adjRow][adjCol]=newEffort;
    pq.push({newEffort,{adjRow,adjCol}});
}
            }
        }
    }
    return 0;
    }
};