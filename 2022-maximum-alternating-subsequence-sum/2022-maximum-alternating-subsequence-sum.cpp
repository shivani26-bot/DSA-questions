class Solution {
public:
int n;

//o(2^n)
// long long solve(int idx , bool isEven,vector<int>& nums){
// if(idx>=n) return 0;

//     long long take=0;
//     if(isEven){
//         take=solve(idx+1,!isEven,nums)+nums[idx];
//     }
//     else{
//         take=solve(idx+1,!isEven,nums)-nums[idx];
//     }
//     long long notTake= solve(idx+1, isEven,nums);

//     return max(take,notTake);
// }
//     long long maxAlternatingSum(vector<int>& nums) {
//         // for every index we have two options:either we can take it or not take it
//         // if we decide to take the element then the element sign will be opposite to the previous  element
//         // if we decide to skip the element then the element sign will be similar to the previous element
 
// //  https://www.youtube.com/watch?v=bRk0n5JyXSc
// // start from idx=0, and isEven=true
// n=nums.size();
// return solve(0,true,nums);
//     }


//o(2*n) only these many states will be visited
// long long solve(int idx , bool isEven,vector<int>& nums,vector<vector<long long>>&dp){
// if(idx>=n) return 0;
// if(dp[idx][isEven]!=-1) return dp[idx][isEven];
//     long long take=0;
//     if(isEven){
//         take=solve(idx+1,!isEven,nums,dp)+nums[idx];
//     }
//     else{
//         take=solve(idx+1,!isEven,nums,dp)-nums[idx];
//     }
//     long long notTake= solve(idx+1, isEven,nums,dp);

//     return dp[idx][isEven]=max(take,notTake);
// }
//     long long maxAlternatingSum(vector<int>& nums) {
// n=nums.size();
// vector<vector<long long>>dp(n,vector<long long>(2,-1));
// return solve(0,true,nums,dp);
//     }

long long solve(int idx , bool isEven,vector<int>& nums,vector<vector<long long>>&dp){
if(idx>=n) return 0;
if(dp[idx][isEven]!=-1) return dp[idx][isEven];
    long long take=0;
    if(isEven){
        take=solve(idx+1,!isEven,nums,dp)+nums[idx];
    }
    else{
        take=solve(idx+1,!isEven,nums,dp)-nums[idx];
    }
    long long notTake= solve(idx+1, isEven,nums,dp);

    return dp[idx][isEven]=max(take,notTake);
}
    long long maxAlternatingSum(vector<int>& nums) {
n=nums.size();
vector<vector<long long>>dp(n+1,vector<long long>(2,0));
for(int idx=n-1;idx>=0;idx--){
    for(int isEven=0;isEven<2;isEven++){
long long take=0;
    if(isEven){
        take=dp[idx+1][!isEven]+nums[idx];
    }
    else{
        take=dp[idx+1][!isEven]-nums[idx];
    }
    long long notTake= dp[idx+1][isEven];

    dp[idx][isEven]=max(take,notTake);
    }
    
}
 return dp[0][1];
    }
};