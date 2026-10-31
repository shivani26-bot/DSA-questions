// class NumMatrix {
//     private int[][] matrix;

//     public NumMatrix(int[][] matrix) {
//         this.matrix=matrix;
//     }

//     public int sumRegion(int row1, int col1, int row2, int col2) {
//         // brute force 
//         int sum=0;
//         for(int r=row1;r<=row2;r++){
//             for(int c=col1;c<=col2;c++){
//                 sum+=matrix[r][c];
//             }
//         }
//         return sum;

//     }
// }

class NumMatrix {
    private int[][] rowPrefix;

    public NumMatrix(int[][] matrix) {
        int m=matrix.length;
        int n= matrix[0].length;
        rowPrefix= new int[m][n+1];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowPrefix[i][j+1]= rowPrefix[i][j]+matrix[i][j];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        // brute force 
        int sum=0;
        for(int r=row1;r<=row2;r++){
            sum+=rowPrefix[r][col2+1] - rowPrefix[r][col1];
        }
        return sum;

    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */