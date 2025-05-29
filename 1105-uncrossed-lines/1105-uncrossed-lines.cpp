class Solution {
public:
// int n, m;
// int solve(vector<int>& nums1, vector<int>& nums2,int i1, int j1){
//        if(i1>=n || j1>=m) return 0;
//        if(nums1[i1]==nums2[j1]) return 1+solve(nums1,nums2,i1+1,j1+1);
     
//        int fix_i= solve(nums1,nums2,i1,j1+1);
//        int fix_j= solve(nums1,nums2, i1+1,j1);
//        return max(fix_i, fix_j);
// }
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//     n=nums1.size(),m=nums2.size();
//         return solve(nums1,nums2,0,0);
//     }


int n, m;
int solve(vector<int>& nums1, vector<int>& nums2,int i1, int j1,vector<vector<int>>&dp){
       if(i1>=n || j1>=m) return 0;

       if(dp[i1][j1]!=-1) return dp[i1][j1];
       if(nums1[i1]==nums2[j1]) return 1+solve(nums1,nums2,i1+1,j1+1,dp);
     
       int fix_i= solve(nums1,nums2,i1,j1+1,dp);
       int fix_j= solve(nums1,nums2, i1+1,j1,dp);
       return dp[i1][j1]=max(fix_i, fix_j);
}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    n=nums1.size(),m=nums2.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(nums1,nums2,0,0,dp);
    }
};

// this is dp question as we have options either to fix i or j
// and we have to find optimal answer 
// 1 4 4
// 1 2 4
// one 4 can be matched with only one 4

    //  i
    //  1 4  2
    //  1 2  4
    //  j
    //  as i and j matches move i and j by 1
    //    i
    //  1 4  2
    //  1 2  4
    //    j
    // there are two possibilities: either fix i or fix j
    //    i             i
    //  1 4  2     1 4  2
    //  1 2  4     1 2  4
    //       j       j
    // i+1, j+1     i+1, j+1
    //       i            i
    //  1 4  2     1 4  2
    //  1 2  4     1 2  4
    //         j        j
    // return 0       return 0

