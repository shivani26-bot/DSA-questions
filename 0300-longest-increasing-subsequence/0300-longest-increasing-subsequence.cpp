class Solution {
public:
// we have 2 options for each element take or not take , but before picking
// any element make sure that previos element was smaller than the current 
// element in the given subsequence
// carry the prev index that was the part of the subsequence
// prev allows to make a choice that whether we can choose the current index in the subsequence or not
// f(ind,prev_ind) f(0,-1)=>initially length of lis starting from 0
// with no previous element
// f(3,0)=> length of lis starting from 3rd index , whose previous index is 0

// int solve(int ind, int prev, int n,vector<int>& nums ){
// if(ind==n) return 0;

//      int len= solve(ind+1,prev,n,nums);
//     if( prev==-1 || nums[prev]<nums[ind]) 
//      len=max(len, 1+solve(ind+1,ind,n,nums));
   

//     return len;
// }
// int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         return solve(0,-1,n,nums);
//     }

// top down 

// prev index start from -1 goes till n-1 hence take size n+1 , in order to store -1 to n-1
// coordinate change
// -1 0 1 2 ......n-1
//  0 1 2 3       n
int solve(int ind, int prev, int n, vector<int>& nums, vector<vector<int>>&dp){
if(ind==n) return 0;
if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
     int len= solve(ind+1,prev,n,nums,dp);
    if( prev==-1 || nums[prev]<nums[ind]) 
     len=max(len, 1+solve(ind+1,ind,n,nums,dp));
   

    return dp[ind][prev+1]= len;
}
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
    }
};