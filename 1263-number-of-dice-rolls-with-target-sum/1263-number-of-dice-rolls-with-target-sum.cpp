class Solution {
public:

// o(k^n) , every dice has k possibility
// int mod=1e9+7;
// int solve(int n, int k, int target){
// if(target<0) return 0;
// if(n==0) return (target==0);

// int countWays=0;
//     for(int i=1;i<=k;i++){
//         countWays=(countWays%mod+solve(n-1,k, target-i)%mod)%mod;
//     }
//     return countWays;
// }
//     int numRollsToTarget(int n, int k, int target) {
// //        for every dice we have k possibilities, we can roll a dice and get k faces pointing upwards, 
// //        if k=6, n=2 , target=3
// //        dice 1  
// //     1               2          3   4   5   6
// // dice 2             dice 2
// // 1  2  3  4 5 6     1 2 3 4 5 6

// // if at any point target<=0 return 0, it's not a possible way
// // if n==0 that means all the dices are used, return true or 1 only if target==0
// return solve(n,k,target);
//     }


// int mod=1e9+7;
// int solve(int n, int k, int target,vector<vector<int>>&dp){
// if(target<0) return 0;
// if(n==0) return target==0;
// if(dp[n][target]!=-1) return dp[n][target];
// int countWays=0;
//     for(int i=1;i<=k;i++){
//         countWays=(countWays%mod+solve(n-1,k, target-i,dp)%mod)%mod;
//     }
//     return dp[n][target]=countWays;
// }
//     int numRollsToTarget(int n, int k, int target) {
//         vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
// return solve(n,k,target,dp);

//     }




int mod=1e9+7;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
// if n==0 then for target 1 , 2,3 ,.... it will be 0
// if target==0 then for n=1,2,3,4,5...it will be 0
        for(int dice=1; dice<n+1; dice++){
            for(int t=1 ;t<target+1;t++){
                int countWays=0;
                for(int i=1;i<=k;i++){//faces
                if(t-i>=0) //t>=i
        countWays=(countWays%mod+dp[dice-1][t-i]%mod)%mod;
    }
    dp[dice][t]=countWays;
            }
        }
return dp[n][target];
    }
};