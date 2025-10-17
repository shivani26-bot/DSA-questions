class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        int n=grid.size();
                vector<vector<int>>maxLocal(n-2,vector<int>(n-2));
                // for every cell in answer matrix, we need to go through 3x3 matrix in grid 
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int maxm=INT_MIN;
                 for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                       maxm =max(maxm, grid[k][l]);
                    }
                 }
                 maxLocal[i][j]=maxm;
            }
        }
return maxLocal;
    }
};