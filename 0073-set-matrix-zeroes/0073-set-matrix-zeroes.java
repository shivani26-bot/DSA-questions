class Solution {
    public void setZeroes(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;

        boolean firstRowImpacted=false;
        boolean firstColImpacted=false;

        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){
                firstRowImpacted=true;
                break;
            }
        }

         for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                firstColImpacted=true;
                break;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0; //mark first column of that row as 0
                    matrix[0][j]=0; // mark first row of that col as 0
                }
            }
        }

         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0; 
                }
            }
        }

        if(firstRowImpacted){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }

         if(firstColImpacted){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }


    }
}