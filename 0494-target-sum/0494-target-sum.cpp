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

// how we will map this problem to partitions with given differnce 
// {1,2,3,1}
//  - + + - (let suppose one of the assignments)
//  3+2-1-1
//  (3+2)-(1+1), here we are assinging some portion to subset 1 and other portion to subset 2
//  s1-s2=target (derived from above )
//  s1+s2=totalSum (in general)
//  s1=totalSum-s2
//  totalSum-s2-s2=target
//  totalSum-2*s2=target
//  s2=totalSum-target/2


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

// d=target here
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






















// class Solution{
// public:

// //   s1-s2=d  and s1>=s2
// // s1+s2= totalsum

// // s1=totalsum-s2
// //   totalsum-s2-s2=d
// //   totalsum-d=2*s2
// //   s2=totalsum-d
// //     ------------
// //         2

// s2 is sum of subsets, hence totalsum-d must be greater than equal to 0,
// all numbers are integer here hence (totalsum-d)/2 must be  divisible by 2
// // looking for subsets which have sum = (totalsum-d) /2
// // count subsets with given targetsum 
// // 0 <= arr[i] <= 50
// // edge cases: totalsum-d >=0 and has to be even 

// // #define mod 1000000007
// // int mod=(int)(1e9+7);
// // int solve(int index, int target, vector<int>arr, vector<vector<int>>&dp){
// //e.g. 
// // arr → 0 4 1 2  
// // Target → 5 
// // ===> possible subset: 0,4,1 and 4,1
// // arr → 0 0 1   
// // Target → 1
// // ===> possible subset: 0,1 and 0,1 and 0,0,1
// //that why for arr[0] if 0 then took 2 answer.
//     // if(target==0) return 1; // this creates a problem because when target is 0 and arr[0] is also 0 then we have 2 options either we take it or not take it 
//   // if arr[0]=5 ans we have target=0 then there is only one way to not take it 
//   // if arr[0]=5 and sum=5 we have one way to take it 
// //     if(index==0){
// //       if(target==0 && arr[0]==0) return 2;
// //       if(target==0 || target==arr[0]) return 1;
// //       return 0;
// //     }
    
// //     if(dp[index][target]!=-1) return dp[index][target];
   
// //     int take=0;
// //     if(target>=arr[index]){
// //         take=solve(index-1,target-arr[index],arr,dp);
// //     }
// //      int notTake= solve(index-1, target, arr,dp);
// //     return dp[index][target]=(take + notTake)%mod;
// // }

// //     int countPartitions(int n, int d, vector<int>& arr) {
// //   int totalsum=0;
// //   for(auto it: arr) totalsum+=it;
// //   if(totalsum-d <0 || (totalsum-d)%2) return 0;
// // //   k is target here
// //   int k=(totalsum-d)/2;
// //          vector<vector<int>>dp(n,vector<int>(k+1,-1));
// //       return solve(n-1,k,arr,dp);

// //     }


// // recursion
// // #define mod 1000000007
// // // int mod=(int)(1e9+7);
// // int solve(int index, int target, vector<int>arr){
// // //e.g. 
// // // arr → 0 4 1 2  
// // // Target → 5 
// // // ===> possible subset: 0,4,1 and 4,1
// // // arr → 0 0 1   
// // // Target → 1
// // // ===> possible subset: 0,1 and 0,1 and 0,0,1
// // //that why for arr[0] if 0 then took 2 answer.
// //     // if(target==0) return 1; // this creates a problem because when target is 0 and arr[0] is also 0 then we have 2 options either we take it or not take it 
// //   // if arr[0]=5 ans we have target=0 then there is only one way to not take it 
// //   // if arr[0]=5 and sum=5 we have one way to take it 
// //     if(index==0){
// //       if(target==0 && arr[0]==0) return 2;
// //       if(target==0 || target==arr[0]) return 1;
// //       return 0;
// //     }
   
// //     int notTake= solve(index-1, target, arr);
// //     int take=0;
// //     if(target>=arr[index]){
// //         take=solve(index-1,target-arr[index],arr);
// //     }
// //     return (take + notTake)%mod;
// // }

// //     int countPartitions(int n, int d, vector<int>& arr) {
// //   int totalsum=0;
// //   for(int i=0;i<n;i++) totalsum+=arr[i];
// //   if(totalsum-d <0 || (totalsum-d)%2) return false;
// // //   k is target here
// //   int k=(totalsum-d)/2;
      
// //       return solve(n-1,k,arr);
// //     }

// // bottom up 

// #define mod 1000000007
// // int mod=(int)(1e9+7);
// int solve( vector<int>num, int tar){
//      int n = num.size();

//     vector<vector<int>> dp(n,vector<int>(tar+1,0));
//   if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
//     else dp[0][0] = 1;  // 1 case - not pick
    
//     if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
//     for(int ind = 1; ind<n; ind++){
//         for(int target= 0; target<=tar; target++){
            
//             int notTaken = dp[ind-1][target];
    
//             int taken = 0;
//                 if(num[ind]<=target)
//                     taken = dp[ind-1][target-num[ind]];
        
//             dp[ind][target]= (notTaken + taken)%mod;
//         }
//     }
//     return dp[n-1][tar];
// }

//     int countPartitions(int n, int d, vector<int>& arr) {
//   int totalsum=0;
//   for(int i=0;i<n;i++) totalsum+=arr[i];
//   if(totalsum-d <0 || (totalsum-d)%2) return false;
// //   k is target here
//   int k=(totalsum-d)/2;
        
//       return solve(arr,k);
//     }


// // space optimization
// }