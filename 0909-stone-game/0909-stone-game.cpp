class Solution {
public:
// bool solve(int i, int j,int a,vector<int>&piles){
// if(i>=j) return 0;

// int alice=0,bob=0;

// if(a==1){
//     alice= max(piles[i]+solve(i+1,j,0,piles),piles[j]+solve(i,j-1,0,piles));
// }
// else{
//     bob= max(piles[i]+solve(i+1,j,1,piles),piles[j]+solve(i,j-1,1,piles));
// }

// return alice>bob;
// }
//     bool stoneGame(vector<int>& piles) {
//         int n=piles.size();
//        return  solve(0,n-1,1,piles);
//     }



//top down
//o(n^2)
// i ∈ [0, n-1]
// j ∈ [0, n-1], with i ≤ j
// a ∈ {0, 1}
// total valid states are n^2
// int dp[500][500][2];
// bool solve(int i, int j,int a,vector<int>&piles){
// if(i>=j) return 0;

// if(dp[i][j][a]!=-1) return dp[i][j][a];
// int alice=0,bob=0;

// if(a==1){
//     alice= max(piles[i]+solve(i+1,j,0,piles),piles[j]+solve(i,j-1,0,piles));
// }
// else{
//     bob= max(piles[i]+solve(i+1,j,1,piles),piles[j]+solve(i,j-1,1,piles));
// }

// return dp[i][j][a]=alice>bob;
// }
//     bool stoneGame(vector<int>& piles) {
//         int n=piles.size();
//         memset(dp, -1,sizeof(dp));
//        return  solve(0,n-1,1,piles);
    
// }
//maths
 bool stoneGame(vector<int>& piles) {
//  as alice is first one to make move alice will always choose 0, 2 4, 6 , n-2 even indexes, bob always choose 1,3,5,7,...n-1 odd indexes given: sum(piles) is odd, piles.length is even  
//  If sum(piles[even]) > sum(piles[odd]), Alex just picks all evens and wins.
// If sum(piles[even]) < sum(piles[odd]), Alex just picks all odds and wins.
return true;
    }
};