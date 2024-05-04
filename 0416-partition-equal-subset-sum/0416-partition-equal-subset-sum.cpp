class Solution {
public:
// recursion
// bool solve(int index, int target, vector<int>arr){
//     if(target==0) return true;
//     if(index==0) return arr[0]==target;
    
//     bool notTake= solve(index-1, target, arr);
//     bool take=false;
//     if(target>=arr[index]){
//         take=solve(index-1,target-arr[index],arr);
//     }
//     return (take || notTake);
// }
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int totalSum=0;
//         for(int i=0;i<n;i++) totalSum+=nums[i];
//         // if totalsum is odd then division is not possible we can't have subset with equal sum 
//         if(totalSum%2!=0) return false;
//        return solve(n-1,totalSum/2,nums);
//     }

// top down
// bool solve(int index, int target, vector<int>arr, vector<vector<int>>&dp){
//     if(target==0) return true;
//     if(index==0) return arr[0]==target;
//     if(dp[index][target]!=-1) return dp[index][target];
//     bool notTake= solve(index-1, target, arr,dp);
//     bool take=false;
//     if(target>=arr[index]){
//         take=solve(index-1,target-arr[index],arr,dp);
//     }
//     return dp[index][target]=(take || notTake);
// }
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int totalSum=0;
//         for(int i=0;i<n;i++) totalSum+=nums[i];
//         // if totalsum is odd then division is not possible we can't have subset with equal sum 
//         int k;
//         if (totalSum%2==0){
//             k=totalSum/2;
//         }else{
//             return false;
//         }
//         if(n==1){
//             return false;
//         }
//       // we can't take boolean dp array as -1 here marks the unvisited state
//        vector<vector<int>>dp(n,vector<int>(k+1,-1));
//        return solve(n-1,k,nums,dp);
        
//     }

// bottom top 
// bool solve(int n, int k, vector<int>&arr, vector<vector< bool>>&dp){

//     for(int i=0;i<n;i++) dp[i][0]=true;

//    if (arr[0]<=k) dp[0][arr[0]] = true;
// for(int index=1;index<n;index++){
//       for(int target=1;target<=k;target++){
//        bool notTake= dp[index-1][target];
//     bool take=false;
//     if(target>=arr[index])
//         take=dp[index-1][target-arr[index]];
    
// dp[index][target]=(take || notTake);
//       }
//   }
//   return dp[n-1][k];
// }
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int totalSum=0;
//         for(int i=0;i<n;i++) totalSum+=nums[i];
//         // if totalsum is odd then division is not possible we can't have subset with equal sum 
//          int k;
//         if(totalSum%2==0)  k=totalSum/2;
//         else return false;
//      if(n==1){
//             return false;
//         }

//         vector<vector<bool>>dp(n,vector<bool>(k+1,false));
//        return solve(n,k,nums,dp);
//         }


// space optimization 
bool solve(int n, int k, vector<int>&arr){
vector<bool>prev(k+1,0), curr(k+1,0);
 prev[0]=curr[0]=true;
    if (arr[0]<=k) prev[arr[0]] = true;


for(int index=1;index<n;index++){
      for(int target=1;target<=k;target++){
bool notTake=prev[target];
    bool take=false;
    if(target>=arr[index])
        take=prev[target-arr[index]];
    
        curr[target]=(take || notTake);
      }
      prev=curr;
  }
  return prev[k];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++) totalSum+=nums[i];
        int k;
        if(totalSum%2==0)  k=totalSum/2;
        else return false;
        if(n==1){
            return false;
        }
       return solve(n,k,nums);

    }
};