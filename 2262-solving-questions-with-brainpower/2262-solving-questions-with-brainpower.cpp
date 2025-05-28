class Solution {
public:
// int n;
// long long solve(int index,vector<vector<int>>& questions, int n){
// if(index>=n) return 0;

// int points= questions[index][0];
// int brainPower= questions[index][1];
//     int notTake= solve(index+1, questions, n);
//     int take= points+solve(index+brainPower+1, questions,n);
//     return max(take, notTake);
// }
//     long long mostPoints(vector<vector<int>>& questions) {
//         n=questions.size();
//         return solve(0, questions,n);
//     }




// int n;
// long long solve(int index,vector<vector<int>>& questions, int n, vector<long long>&dp){
// if(index>=n) return 0;


// long long points= questions[index][0];
// long long brainPower= questions[index][1];
// if(dp[index]!=-1) return dp[index];
//     long long notTake= solve(index+1, questions, n,dp);
//     long long take= points+solve(index+brainPower+1, questions,n,dp);
//     return dp[index]=max(take, notTake);
// }
//     long long mostPoints(vector<vector<int>>& questions) {
//         n=questions.size();
//         vector<long long>dp(n,-1);
//         return solve(0, questions,n,dp);
//     }


int n;
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<long long>dp(n+1,-1);
        dp[n]=0;
        for(int index=n-1;index>=0;index--){
long long points= questions[index][0];
long long brainPower= questions[index][1];
  long long notTake= dp[index+1];
    long long take= points;
    
    if(index+brainPower+1<n){
       take= points+dp[index+brainPower+1];
    }

    dp[index]=max(take, notTake);
        }
        return dp[0];
    }
};