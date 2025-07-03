class Solution {
public:

// int solve(int i, int j,int a,vector<int>&piles){
// if(i>=j) return 0;

// int result=0;

// if(a==1){
//     result= max(piles[i]+solve(i+1,j,0,piles),piles[j]+solve(i,j-1,0,piles));
// }
// else{
//     result= min(solve(i+1,j,1,piles),solve(i,j-1,1,piles));
// }

// return result;
// }
//     bool stoneGame(vector<int>& piles) {
//         int n=piles.size();
    //     int totalStones= accumulate(piles.begin(),piles.end(),0);
    //   int alice= solve(0,n-1,1,piles);
    //   int bob= totalStones-alice;
    //   cout<<alice<<" "<<bob;
    //   return alice>bob;
//     }



//top down
// Why It Passes All Test Cases?
// Because:
// Even number of piles
// Alice always starts, and
// Alice can always win if both play optimally.

//o(n^2)
// i ∈ [0, n-1]
// j ∈ [0, n-1], with i ≤ j
// a ∈ {0, 1}
// total valid states are n^2
int dp[500][500][2];
int solve(int i, int j,int a,vector<int>&piles){
if(i>=j) return 0;

if(dp[i][j][a]!=-1) return dp[i][j][a];
int result=0;

if(a==1){
     result= max(piles[i]+solve(i+1,j,0,piles),piles[j]+solve(i,j-1,0,piles));
}
else{
     result= min(solve(i+1,j,1,piles),solve(i,j-1,1,piles));
}


return dp[i][j][a]=result;
}
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp, -1,sizeof(dp));
  int totalStones= accumulate(piles.begin(),piles.end(),0);
      int alice= solve(0,n-1,1,piles);
      int bob= totalStones-alice;
      cout<<alice<<" "<<bob;
      return alice>bob;
}
//maths
//  bool stoneGame(vector<int>& piles) {
// //  as alice is first one to make move alice will always choose 0, 2 4, 6 , n-2 even indexes, bob always choose 1,3,5,7,...n-1 odd indexes given: sum(piles) is odd, piles.length is even  
// //  If sum(piles[even]) > sum(piles[odd]), Alex just picks all evens and wins.
// // If sum(piles[even]) < sum(piles[odd]), Alex just picks all odds and wins.
// return true;
//     }


// int dp[500][500];

// vector<int>prefixSum;
//     //we should track the total score of alice and bob based on that i should return my answer
//     int getSum(int i, int j){
//         return prefixSum[j+1]-prefixSum[i];
//     }
//     int solve(int i, int j){
//  if(i>j) return 0;
//  if(dp[i][j]!=-1) return dp[i][j];
// int total= getSum(i,j);
// dp[i][j]=total-(min(solve(i+1,j),solve(i,j-1)));//take minimum of next opponent
// return dp[i][j];
//     }
//      bool stoneGame(vector<int>& piles) {
//     int n=piles.size();
// // At each move, the player can:
// // Take piles[i] → opponent plays next from [i+1..j]
// // Take piles[j] → opponent plays next from [i..j-1]
// // current player gets total - min(opponent gain)
// memset(dp,-1,sizeof(dp));
// prefixSum.assign(n+1,0);


// for(int i=0;i<n;i++){
//   prefixSum[i + 1] = prefixSum[i] + piles[i];
// }
//     int alice= solve(0,n-1);//find optimal moves for alice
//     int totalSum=prefixSum[n];
//     int bob= totalSum-alice;//subtract the totalstones with the stones collected by alice
// cout<<alice<< " "<<bob;
//     return alice>bob;
//      }

};