class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int n=mat.length;
        int m=mat[0].length;

        int[] ans= new int[m*n];
        boolean goup=true;
        int row=0,col=0;
        for(int i=0;i<m*n;i++){
            ans[i]=mat[row][col];
            if(goup){
                if(col==m-1){
                    row++;
                    goup=false;
                }
                else if(row==0){
                    col++;
                    goup=false;
                } else{
                    row--;
                    col++;
                }
            }else{
                if(row==n-1){
                    col++;
                    goup=true;
                } else if(col==0){
                    row++;
                    goup=true;
                }else{
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
}