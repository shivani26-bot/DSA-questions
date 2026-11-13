class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans= new ArrayList<>();
        int n=matrix[0].length; //column
        int m=matrix.length; //row

        int top=0, left=0, right=n-1, bottom=m-1;

        while(top<=bottom && left<=right){

            for(int i=left; i<=right; i++){
                ans.add(matrix[top][i]);
            }
            top++;
            if(top>bottom) break;
            for(int i=top; i<=bottom;i++){
                ans.add(matrix[i][right]);
            }
            right--;
            if(left>right) break;
            for(int i=right;i>=left;i--){
                ans.add(matrix[bottom][i]);
            }
            bottom--;
            if(top>bottom) break;
            for(int i=bottom;i>=top;i--){
                ans.add(matrix[i][left]);
            }
            left++;
        }
        return ans;

    }
}