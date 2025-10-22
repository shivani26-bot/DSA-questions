class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // just store the row and column of cell where it's 0
        // maintain a linear array of row and column size each
        // row= f f f 
        // col= f f f
        // for cell 1,1 row[1] and col[1] will be true
        // row= f t f 
        // col= f t f
        // now loop through the matrix, and if for current cell if row[i] or row[j] is true then mark the cell as 0
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool>row(m,false);
        vector<bool>col(n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
matrix[i][j]=0;
                }
            }
        }
       
    }
};