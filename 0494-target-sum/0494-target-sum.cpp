class Solution {
public:
// arr[]->[1,2,3,1]
// target=3
// -1+2+3-1=3
// +1-2+3+1=3
// there are two ways
// assign signs
// dp on subsequences 
// f(index,target) we have two options for each index ie + or -
// similar problem to Partitions with Given Difference

int solve(int index, int target, vector<int>arr, vector<vector<int>>&dp)
{
    if(index==0){
      if(target==0 && arr[0]==0) return 2;
      if(target==0 || target==arr[0]) return 1;
      return 0;
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int notTake= solve(index-1, target, arr,dp);
    int take=0;
    if(target>=arr[index]){
        take=solve(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target]=(take + notTake);
}

int countPartitions(int n, int d, vector<int>& arr) {
  int totalsum=0;
  for(int i=0;i<n;i++) totalsum+=arr[i];
  if(totalsum-d <0 || (totalsum-d)%2) return false;
//   k is target here
  int k=(totalsum-d)/2;
  vector<vector<int>>dp(n,vector<int>(k+1,-1));
  return solve(n-1,k,arr,dp);
}

int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n,target,nums);
}
};