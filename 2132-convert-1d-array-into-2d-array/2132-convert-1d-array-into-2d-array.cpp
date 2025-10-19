class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n));

        // if orginal array doesn't have m*n element then it's not possible to convert from 1d array to 2d array not enough elements 
        if(m*n!=original.size()) return {};

        //run a for loop for 2d matrix, because we need to fill each cell, and maintain a k pointer at original array which will point to current element which will go in current cell of 2d matrix
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[k];
                k++;//keep increment the pointer pointing to original array
            }
        }
        return ans;
    }
};