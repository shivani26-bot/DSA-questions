class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));

        int num=0;
        int top=0,left=0,right=n-1,bottom=n-1;
        vector<int>temp;
        while(top<=bottom && left<=right){
        
        for(int i=left;i<=right;i++){
            num=num+1;

            matrix[top][i]=num;
        }
         
            top++;
            if(top>bottom) break;

            for(int i=top;i<=bottom;i++){
             num=num+1;

            matrix[i][right]=num;
            }
            
            right--;
            if(left>right) break;

            for(int i=right;i>=left;i--){
               num=num+1;
       
matrix[bottom][i]=num;
            }
           
            bottom--;
             if(top>bottom) break;

            for(int i=bottom;i>=top;i--){
                num=num+1;
        
            matrix[i][left]=num;
            }
          
           left++;
            if(left>right) break;
        }

        return matrix;
    }
};