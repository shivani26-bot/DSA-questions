class Solution {
public:
// we can burst balloon in any order 
// if we have the array like [b1,b2,b3,b4,b5,b6]
// and b4 is the balloon to burst       k
// then b3xb4xb5 + f(b1,b3)+ f(b5,b6) , but this will not work!
// solving them independently will not work 
// because from b1 to b3 if we burst b3 then it will depend on b5
// similaly from b5 to b6 if we burst b5 then it will depend on b3

// [3,1,5,8]=> [3,5,8] =>[3,8] =>[8] instead of going in this direction
// go in the reverse direction 
// last element is 8 , then 3 then 5 then 1
// add 1 to begining and end of array
// [1,3,1,5,8,1]  decide the last element to burst instead of first element
// cost will be 1*8*1
// range we remain with [3,1,5]
// [3,8] => if we burst 3 then cost will be 1*3*8
// range we remain with [1,5] 
// [3,5,8] if we burst 5 then cost 3*5*8
// anyone not in the range is burst in the next step
// [3,1,5] if we burst 1 then cost 3*1*5

// [b1,b2,b3,b4,b5,b6] if we burst b4 as the last element then it's 
// guranteed that it was present in 2nd last burst
// hence it can be [b1,b4] or [b2,b4] or [b3,b4] or [b4, b5] or [b4,b6] in second last step
// int solve(int i, int j, vector<int>&nums){
//     if(i>j) return 0;
//     int maxi=INT_MIN;
//     for(int k=i;k<=j;k++){
//         int cost=nums[i-1]*nums[k]*nums[j+1]+ solve(i,k-1,nums)+solve(k+1,j,nums);
//         maxi=max(maxi, cost);
//     }
//     return maxi;
// }

   
//     int maxCoins(vector<int>& nums) {
//          int n=nums.size();
//          nums.push_back(1);
//          nums.insert(nums.begin(),1);
//          return solve(1,n,nums);
//     }

// top down 
// int solve(int i, int j, vector<int>&nums,vector<vector<int>>&dp){
//     if(i>j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int maxi=INT_MIN;
//     for(int k=i;k<=j;k++){
//         int cost=nums[i-1]*nums[k]*nums[j+1]+ solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
//         maxi=max(maxi, cost);
//     }
//     return dp[i][j]=maxi;
// }

   
//     int maxCoins(vector<int>& nums) {
//          int n=nums.size();
//          nums.push_back(1);
//          nums.insert(nums.begin(),1);
//          vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//          return solve(1,n,nums,dp);
//     }

// bottom top 

int solve(int i, int j, vector<int>&nums,vector<vector<int>>&dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi=INT_MIN;
    for(int k=i;k<=j;k++){
        int cost=nums[i-1]*nums[k]*nums[j+1]+ solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
        maxi=max(maxi, cost);
    }
    return dp[i][j]=maxi;
}

   
    int maxCoins(vector<int>& nums) {
         int n=nums.size();
         nums.push_back(1);
         nums.insert(nums.begin(),1);
         vector<vector<int>>dp(n+2,vector<int>(n+2,0));

         for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
 int maxi=INT_MIN;
    for(int k=i;k<=j;k++){
        int cost=nums[i-1]*nums[k]*nums[j+1]+ dp[i][k-1]+dp[k+1][j];
        maxi=max(maxi, cost);
    }
    dp[i][j]=maxi;
            }
         }
         return dp[1][n];
    }
};