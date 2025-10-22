class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // brute force 
        // take a temporary matrix 
          int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>temp=matrix;//temp 2d matrix will be equal to matrix
        // loop through the matrix
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // if current cell is 0 then update the entire row and entire columnn that aligns for that cell , make the update in temp 2d array
if(matrix[i][j]==0){
    for(int k=0;k<n;k++){
        //this covers the row
        temp[i][k]=0;
    }
      for(int k=0;k<m;k++){
        //this covers the column
        temp[k][j]=0;
    }
}
            }
        }
//reassign the temp to matrix
        matrix=temp;


        // 2nd approach 
        // just store the row and column of cell where it's 0
        // maintain a linear array of row and column size each
        // row= f f f 
        // col= f f f
        // for cell 1,1 row[1] and col[1] will be true
        // row= f t f 
        // col= f t f
        // now loop through the matrix, and if for current cell if row[i] or row[j] is true then mark the cell as 0
//         int m=matrix.size();
//         int n=matrix[0].size();
//         vector<bool>row(m,false);
//         vector<bool>col(n,false);
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     row[i]=true;
//                     col[j]=true;
//                 }
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(row[i] || col[j]){
// matrix[i][j]=0;
//                 }
//             }
//         }
       
    }
};

// 1 1 1       0 1 1
// 0 1 1   =>  0 0 0
// 1 1 1       0 1 1

// [1][0] => 0
// [i][0]=> first ele of ith row
// [0][j]=> first ele of jth col
// mark them as 0
// 0 1 1
// 0 1 1
// 1 1 1
// now if we iterate through matrix and go to cell (0,1) and check whether it's impacted by row or column ie [i][0] and [0][j] then mark the cell (0,1) by 0
// but it's a corner case we cannot mark it as 0, as it will not match the final result, hence leave the first row and first column and traverse on rest matrix ie (1,1) (1,2) (2,1) (2,2)

// (1,1) (1,2) find the first element of ith row ie [i][0] it's 0 then mark both the cell as 0
// (2,2) find the first element of ith row and jth column ie [i][0] it's not 0 or [0][j] is also not 0 hence the current cell is neither impacted by row or column hence leave it as it is


// at last traverse first row and first column which we left

// traverse first row and first column and check impacted
// start from excluding first row and first column
// finally if first row and first column is impacted make it 0


// consider first row/coulmn as marker or security guard , because they will tell that either that row or column is impacted or not
