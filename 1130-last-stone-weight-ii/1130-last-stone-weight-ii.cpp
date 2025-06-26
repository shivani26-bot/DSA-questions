class Solution {
public:
// int solve(int idx, int target,int currSum,int stoneSum,vector<int>& stones ){

// if(currSum>=target || idx==0){
//     // stoneSum-currSum -> this gives the sum of other part
//     // currSum>other part sum, currSum-(other part sum ) gives the weight when two parts smashes with each other
//     return abs(currSum-(stoneSum-currSum));
// }

// int notTake= solve(idx-1, target,currSum,stoneSum, stones);
// int take=solve(idx-1,target,currSum+stones[idx],stoneSum,stones);
//    return  min(take,notTake);
// }
//     int lastStoneWeightII(vector<int>& stones) {
//         // 31 26 33 21 40
//         // choose 31 and 40
//         // 9 26 33 21
//         // choose 26 and 33
//         // 9 7 21
//         // choose 9 and 21
//         // 7 12 [5]

//         // edge case if we have only single stone in array, we can't smash it
//         // hence weight of the stone itself will be an answer 

//         // find the total sum of the array and try to divide the total array into 2 parts, if one part has total weight nearest or equal to totalsumarray/2 and then subtract that totalsum of one part with the total sum of remaining part

//         // at last only 2 stones will be remaining
// // [31,26,33,21,40]
// // total sum=151
// // target = 151+1/2= 76
// // one part must include, 40+33= 73 nearest to 76
// // second part must include, 26+21+31=78
// // now 78-73=5, final weight of the remaining one stone

// int stoneSum= accumulate(stones.begin(),stones.end(),0);
// int target= (stoneSum+1)/2;
// int n=stones.size();
// return solve(n-1,target,0,stoneSum, stones);
//     }

// top down 
int solve(int idx, int target,int currSum,int stoneSum,vector<int>& stones,vector<vector<int>>&dp ){

if(currSum>=target || idx==0){
   
    return abs(currSum-(stoneSum-currSum));
}
if(dp[idx][currSum]!=-1) return dp[idx][currSum];

int notTake= solve(idx-1, target,currSum,stoneSum, stones,dp);
int take=solve(idx-1,target,currSum+stones[idx],stoneSum,stones,dp);
   return  dp[idx][currSum]=min(take,notTake);
}
    int lastStoneWeightII(vector<int>& stones) {


int stoneSum= accumulate(stones.begin(),stones.end(),0);
int target= (stoneSum+1)/2;
int n=stones.size();
vector<vector<int>>dp(n,vector<int>(target+1,-1));
return solve(n-1,target,0,stoneSum, stones,dp);
    }
};