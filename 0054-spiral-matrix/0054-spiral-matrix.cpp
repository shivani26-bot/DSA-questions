class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        // right bottom left top we move in this fashion
        // first we will move from left to right with top as fixed 
        // a[top][i]  i->varies from left to right
        // initally top=0, left=0, bottom=n-1, right=m-1
        // when we have moved in the right direction we will increase top by 1
        // because next we will move in  bottom direction
        // in bottom direction a[right][j] j->varies from top to bottom 
        int n=matrix.size();
        int m=matrix[0].size();
int top=0,left=0,bottom=n-1,right=m-1;
while(top<=bottom && left<=right){
    for(int i=left;i<=right;i++){
        ans.push_back(matrix[top][i]);
    }
    top++;
    if(top>bottom) break;
    for(int i=top;i<=bottom;i++){
        ans.push_back(matrix[i][right]);
    }
    right--;
    if(left>right) break;
    for(int i=right;i>=left;i--){
        ans.push_back(matrix[bottom][i]);
    }
    bottom--;
    if(top>bottom) break;
    for(int i=bottom;i>=top;i--){
        ans.push_back(matrix[i][left]);
    }
    left++;
}
return ans;
    }
};