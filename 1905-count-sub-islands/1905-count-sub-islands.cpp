class Solution {
public:
bool flag;
void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&visited, int n, int m, int row, int col){
if(row<0 || row>=m || col<0 || col>=n || visited[row][col] ||grid2[row][col]==0) return;

visited[row][col]=1;
 if(grid1[row][col] != grid2[row][col]){
        flag=false;
        
    }

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
for(int i=0;i<4;i++){
    int adjRow=row+dx[i];
    int adjCol=col+dy[i];
   
        dfs(grid1,grid2,visited,n,m,adjRow,adjCol);

  
}

}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size();
        int n=grid2[0].size();
vector<vector<int>>visited(m, vector<int>(n, 0));
int count=0;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if( grid2[i][j]==1 && !visited[i][j]){
              flag=true;
               dfs(grid1,grid2,visited,n,m,i,j);
               if(flag)
                count++;
        }
    }
//   maintain a flag to keep track whether the current island in grid2 is a valid subisland or not, initially it's true, means it's a valid subisland
}
       
        return count;
    }
};