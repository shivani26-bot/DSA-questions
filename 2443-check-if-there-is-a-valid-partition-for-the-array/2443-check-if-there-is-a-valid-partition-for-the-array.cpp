class Solution {
public:
// recursion 
// bool checkValid(int i, int index, int n, vector<int>&nums){
//     if(index-i+1==2 && nums[index]==nums[i]) return true;
//      else if(index-i+1==3 && nums[i]==nums[i+1] && nums[i+1]==nums[index]) return true;
// else if (index-i+1==3 && nums[i+1]-nums[i]==1 && nums[index]-nums[i+1]==1 ) return true;
// return false;
// }
// bool solve(int i, int n, vector<int>&nums){
// if(i>=n) return true;
// for(int index=i;index<n;index++){
//      if(index-i+1>3) break;
//     if(checkValid(i,index,n,nums) && solve(index+1, n, nums)){
//         return true;
//     }
// }
//   return false;
// }
//     bool validPartition(vector<int>& nums) {
//         // [2,2,2,3,4,5,5,5]
//         int n=nums.size();
//         return solve(0,n,nums);
//     }
// top down 
// bool checkValid(int i, int index, int n, vector<int>&nums){
//     if(index-i+1==2 && nums[index]==nums[i]) return true;
//      else if(index-i+1==3 && nums[i]==nums[i+1] && nums[i+1]==nums[index]) return true;
// else if (index-i+1==3 && nums[i+1]-nums[i]==1 && nums[index]-nums[i+1]==1 ) return true;
// return false;

// }
// bool solve(int i, int n, vector<int>&nums,vector<int>&dp){
// if(i>=n) return true;

// if(dp[i]!=-1) return dp[i];
// for(int index=i;index<n;index++){
//     if(index-i+1>3) break;
//     if(checkValid(i,index,n,nums) && solve(index+1, n, nums,dp)){
//         return dp[i]=true;
//     }
  
// }
//   return dp[i]=false;
// }
//     bool validPartition(vector<int>& nums) {
//         // [2,2,2,3,4,5,5,5]
//         int n=nums.size();
//         vector<int>dp(n,-1);
//         return solve(0,n,nums,dp);
//     }



// bool solve(int i, int n, vector<int>&nums,vector<int>&dp){
// if(i>=n) return true;

// if(dp[i]!=-1) return dp[i];
// // for(int index=i;index<n;index++){
// //     if(index-i+1>3) break;
// //     if(checkValid(i,index,n,nums) && solve(index+1, n, nums,dp)){
// //         return dp[i]=true;
// //     }
  
// // }
// if(i+1<n && nums[i]==nums[i+1]){
//     if(solve(i+2,n,nums,dp)) return true;
//     if(i+2<n && nums[i]==nums[i+2]) {
//        if(solve(i+3,n,nums,dp)) return true;
//     }
// }
// if(i+2<n && nums[i]==nums[i+1]-1 && nums[i]==nums[i+2]-2){
//     if(solve(i+3,n,nums,dp)) return true;
// }
//   return dp[i]=false;
// }
//     bool validPartition(vector<int>& nums) {
//         // [2,2,2,3,4,5,5,5]
//         int n=nums.size();
//         vector<int>dp(n,-1);
//         return solve(0,n,nums,dp);
//     }



// bottom top 
// bool checkValid(int i, int index, int n, vector<int>&nums){
//     if(index-i+1==2 && nums[index]==nums[i]) return true;
//      else if(index-i+1==3 && nums[i]==nums[i+1] && nums[i+1]==nums[index]) return true;
// else if (index-i+1==3 && nums[i+1]-nums[i]==1 && nums[index]-nums[i+1]==1 ) return true;
// return false;
// }

//     bool validPartition(vector<int>& nums) {
//         // [2,2,2,3,4,5,5,5]
//         int n=nums.size();
        // vector<bool>dp(n+1,false);
        // dp[n]=true;
//         for(int i=n-1;i>=0;i--){
//             for(int index=i;index<n;index++){
//                 if(index-i+1>3) break;
//                 if(checkValid(i,index,n,nums) && dp[index+1]==true){
//                      dp[i]=true;
//                 }
  
//             }
          
//         }
//         return dp[0];
//     }




// bool solve(int i, int n, vector<int>&nums,vector<int>&dp){
// if(i>=n) return true;
// if(dp[i]!=-1) return dp[i];
// if(i+1<n && nums[i]==nums[i+1]){
//     if(solve(i+2,n,nums,dp)) return true;
//     if(i+2<n && nums[i]==nums[i+2]) {
//        if(solve(i+3,n,nums,dp)) return true;
//     }
// }
// if(i+2<n && nums[i]==nums[i+1]-1 && nums[i]==nums[i+2]-2){
//     if(solve(i+3,n,nums,dp)) return true;
// }
//   return dp[i]=false;
// }
    bool validPartition(vector<int>& nums) {
        // [2,2,2,3,4,5,5,5]
        int n=nums.size();
        vector<bool>dp(n+1,false);
        dp[n]=true;

        for(int i=n-1;i>=0;i--){
            if(i+1<n && nums[i]==nums[i+1]){
    if(dp[i+2]) dp[i] =  true;
    if(i+2<n && nums[i]==nums[i+2]) {
       if(dp[i+3]) dp[i] =  true;
    }
}
if(i+2<n && nums[i]==nums[i+1]-1 && nums[i]==nums[i+2]-2){
    if(dp[i+3]) dp[i] =  true;
}


        }
        return dp[0];
    }
};