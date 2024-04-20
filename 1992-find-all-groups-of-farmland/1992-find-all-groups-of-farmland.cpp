class Solution {
public:
//connected component
    // vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    //     vector<vector<int>>ans;

    //     // for each cell which is equal to 1 we perform dfs and while performing dfs as we visit the cell we mark it as visited by placing 0, hence we go on each cell at max twice 
    //     // time complexity: o(n*m)
    //     // space: dfs recursive stack space o(m*n)
    //     //rectangular land
    //     // time complexity: o(n*m)
    //     // space: o(1)
    //     for(int r1=0;r1<land.size();r1++){
    //         for(int c1=0;c1<land[0].size();c1++){
    //             if(land[r1][c1]){
    //                     int r2=r1;
    //                     int c2=c1;
    //                 for(r2=r1;r2<land.size() && land[r2][c1];r2++){
    //                     for(c2=c1;c2<land[0].size() && land[r2][c2]; c2++){
    //                         land[r2][c2]=0;
    //                     }
    //                 }
    //                 ans.push_back({r1,c1,r2-1,c2-1});
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // dfs approach 
void dfs(vector<vector<int>>& land,int i,int j, int &r2, int &c2){

    if(i<0 || i>=land.size() || j<0 || j>=land[0].size() || land[i][j]==0) return;

    land[i][j]=0;
    r2=max(r2,i), c2=max(c2,j);
    dfs(land,i+1,j,r2,c2);
    dfs(land,i-1,j,r2,c2);
    dfs(land,i,j+1,r2,c2);
    dfs(land,i,j-1,r2,c2);        
}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
  for(int i=0;i<land.size();i++){
    for(int j=0;j<land[0].size();j++){
        if(land[i][j]==1){
             int r1=i,c1=j, r2=i,c2=j;
            dfs(land,i,j,r2,c2);
            ans.push_back({r1,c1,r2,c2});
        }
    }
  }
  return ans;
  
    }
};