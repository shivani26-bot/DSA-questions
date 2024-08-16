class Solution {
public:
    void dfs(int n, int m,int i, int j, vector<vector<int>>&visited,
vector<vector<char>> mat,int xdir[],int ydir[]){
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        int adjX=i+xdir[k];
        int adjY=j+ydir[k];
        if(adjX>=0 && adjX<n && adjY>=0 && adjY<m && !visited[adjX][adjY] && mat[adjX][adjY]=='O')
                dfs(n,m,adjX,adjY,visited,mat,xdir,ydir);
    }
}
    void solve(vector<vector<char>>& mat) {
          //   if O's are not surrounded by boundary it means they are bound to be
    //   surrounded by X and those O's can be converted to X's
    //   Anyone O's connected to boundary will never be converted to X
    //   start from the boundaries O's and mark them that will not be 
    //   converted and convert the remaining O's
        int n=mat.size();
        int m=mat[0].size();
    int xdir[]={-1, 0, +1, 0};
    int ydir[]={0, 1, 0, -1}; 
    vector<vector<int>>visited(n,vector<int>(m,0));
    // traverse through the boundaries of matrix, and discover O's
    // and call dfs for that O's to find out the other O's connected to it 
//   for first row and last row
for(int j=0;j<m;j++){
   if(!visited[0][j] && mat[0][j]=='O'){
       dfs(n,m,0,j,visited,mat,xdir,ydir);
   }
   if(!visited[n-1][j] && mat[n-1][j]=='O'){
        dfs(n,m,n-1,j,visited,mat,xdir,ydir);
   }
}
// first column and last column 
for(int i=0;i<n;i++){
   if(!visited[i][0] && mat[i][0]=='O' ){
       dfs(n,m,i,0,visited,mat,xdir,ydir);
   }
   if(!visited[i][m-1] && mat[i][m-1]=='O'){
        dfs(n,m,i,m-1,visited,mat,xdir,ydir);
   }
}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        // if matrix i, j is O but it's not visited it means these O's 
        // can be converted to X's
        if(!visited[i][j] && mat[i][j]=='O'){
            mat[i][j]='X';
        }
    }
}

    }
};