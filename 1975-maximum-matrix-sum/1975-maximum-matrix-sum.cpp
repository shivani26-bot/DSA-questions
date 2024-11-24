class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // for every cell i,j the adjacent cells sharing the border are
        // (i+1,j),(i-1,j),(i,j+1),(i,j-1)
        // [[-3,10],[5,2]]
        // 16
        // [[2,-5],[-3,9]]
        // 19
        // -1,-2,-3, we try largest negatives to make it positive 
        // -1,2,3 and make the smallest number as negative
        // if we have odd negative numbers, then make the smallest number as negative, then propagate it to the smallest positive number to maximize the sum
        // if we have even negative numbers, then propagate -ve sign such that they come close to each other and cancel each other to form positive number
        int m=matrix.size();
        int n=matrix[0].size();
        long long total_sum=0;
        int count_negatives=0;
        int min_ele=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
        
                 total_sum+=abs(matrix[i][j]);
                 if(matrix[i][j]<0) count_negatives++;
                 min_ele=min(min_ele,abs(matrix[i][j]));
            }
        }
        cout<<count_negatives<< " "<<min_ele<<endl;
        if(count_negatives%2==1) {
            //odd
            total_sum-=(2*min_ele);
        }
    
        return total_sum;
    }
};