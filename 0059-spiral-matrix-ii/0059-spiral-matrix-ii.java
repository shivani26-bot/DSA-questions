class Solution {
    public int[][] generateMatrix(int n) {
        int top=0,left=0, right=n-1,bottom=n-1;
        int num=1;
        int[][] ans= new int[n][n];

        while(top<=bottom && left<=right){

            for(int i=left ;i<=right;i++){
                ans[top][i]=num;
                num++;
            }
            top++;
            if(top>bottom) break;
            for(int i=top ;i<=bottom;i++){
                ans[i][right]=num;
                num++;
            }
            right--;
            if(left>right) break;
            for(int i=right ;i>=left;i--){
                ans[bottom][i]=num;
                num++;
            }
            bottom--;
            if(top>bottom) break;
            for(int i=bottom ;i>=top;i--){
                ans[i][left]=num;
                num++;
            }
            left++;
            // if(left>right) break;
     

        }
        return ans;
        
    }
}