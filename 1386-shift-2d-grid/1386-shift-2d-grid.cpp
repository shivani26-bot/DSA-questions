class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        while(k){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j+1<n)
                ans[i][j+1]=grid[i][j];
                if(i+1<m)
                ans[i+1][0]=grid[i][n-1];
                ans[0][0]=grid[m-1][n-1];
            }
        }
        grid=ans;
        k--;
        }
        return grid;
    }
};