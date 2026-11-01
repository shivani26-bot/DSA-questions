class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
            int[][] matrix = new int[n][n];

// o(q*n)
        for(int[] q: queries){
            int r1=q[0],c1=q[1],r2=q[2], c2=q[3];
            for(int r=r1;r<=r2;r++){
              matrix[r][c1]++;
              if(c2+1 < n){
                matrix[r][c2+1]--;
              }
            }
        }
// o(n^2)
        for(int r=0;r<n;r++){
            for(int c=1;c<n;c++){
                matrix[r][c] += matrix[r][c-1];
            }
        }
        return matrix; 
    }
}