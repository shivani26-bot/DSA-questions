class Solution {
public:
//top down approach
// int solve(int n,vector<int>&nums,int index,vector<int>&dp){
//      if(index>=n) return 0;
//      if(dp[index]!=-1) return dp[index];
//      int include=solve(n,nums,index+2,dp)+ nums[index];
//      int exclude= solve(n,nums,index+1,dp);
//    dp[index]=max(include,exclude);
//    return dp[index];
// }
//     int rob(vector<int>& nums) {
//        int n = nums.size();
//     if (n == 1)
//         return nums[0];
    
//     vector<int> dp(n + 1, -1);
//     int x = solve( n - 1,nums, 0, dp);
    
//     fill(dp.begin(), dp.end(), -1);
//     int y = solve(n,nums, 1,  dp);
    
//     return max(x, y);
//     }

// bottom top approach
 int solve(vector<int>&arr){
     int n=arr.size();
      vector<int>dp(n,0);
      dp[0]=arr[0];
    
      for(int i=1;i<n;i++){
          int incl=(i-2>=0)?dp[i-2]+arr[i]: arr[i];
          int excl=dp[i-1];
          dp[i]=max(incl,excl);
      }
     
      return dp[n-1];
    }
    int rob(vector<int>& nums) {
       int n = nums.size();
    if (n == 1)
        return nums[0];

   vector<int>temp1,temp2;
   for(int i=0;i<n;i++){
       if(i!=n-1) temp1.push_back(nums[i]);
       if(i!=0)temp2.push_back(nums[i]);
   }
   return max(solve(temp1),solve(temp2));
    }




};