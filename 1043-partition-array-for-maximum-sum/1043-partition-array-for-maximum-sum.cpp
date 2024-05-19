class Solution {
public:
// front partitioning
// f(i) maximum sum generated from index i to n in the array
// try out all the partitions from that index i
// 1,15,7,9,2,5,10  k=3
// 1| 15,7,9,2,5,10   1,15|7,9,2,5,10   1,15,7|9,2,5,10
// we cant do the the 4th partition 1,15,7,9|2,5,10 this is wrong
 
//  int solve(int i, int n,vector<int>& arr, int k ){
// if(i==n) return 0;
// int length=0,maxi=INT_MIN,maxAns;
//     for(int j=i;j<min(n,i+k);j++){
//         length++;
//         maxi=max(maxi,arr[j]);
//        int  sum= (length* maxi)+ solve(j+1,n,arr,k);
//         maxAns=max(maxAns,sum);
//     }
//     return maxAns;
//  }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n =arr.size();
//         return solve(0,n,arr,k);
//     }

// top down
// int solve(int i, int n,vector<int>& arr, int k, vector<int>&dp){
// if(i==n) return 0;
// if(dp[i]!=-1) return dp[i];
// int length=0,  maxi=INT_MIN,  maxAns=INT_MIN;
//     for(int j=i;j<min(n,i+k);j++){
//         length++;
//         maxi=max(maxi,arr[j]);
//        int sum= (length* maxi)+ solve(j+1,n,arr,k,dp);
//         maxAns=max(maxAns,sum);
//     }
//     return dp[i]=maxAns;
//  }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n =arr.size();
//         vector<int>dp(n,-1);
//         return solve(0,n,arr,k,dp);
//     }


// bottom top 

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n =arr.size();
        vector<int>dp(n+1,0);
       
        for(int i=n-1;i>=0;i--){
             int length=0,  maxi=INT_MIN,  maxAns=INT_MIN;
              for(int j=i;j<min(n,i+k);j++){
        length++;
        maxi=max(maxi,arr[j]);
       int sum= (length * maxi)+ dp[j+1];
        maxAns=max(maxAns,sum);
    }
 dp[i]=maxAns;
        }
        return dp[0];
    }
};