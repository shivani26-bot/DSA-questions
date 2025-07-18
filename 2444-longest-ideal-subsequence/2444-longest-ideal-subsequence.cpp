class Solution {
public:
//     int n;
// int solve(int prev, int currIdx,string s, int k)
// {

// if(currIdx>=n) return 0;

// int take=0;
//     if(prev==-1 || abs(s[prev]-s[currIdx])<=k){
//         take= 1+solve(currIdx, currIdx+1,s,k);
//     }
//     int notTake= solve(prev, currIdx+1,s,k);
//     return max(take, notTake);
// }
//     int longestIdealString(string s, int k) {
//         n=s.length();
//         return solve(-1,0,s,k);
//     }

// int n;
// int solve(int prev, int currIdx,string s, int k,  vector<vector<int >>&dp)
// {

// if(currIdx>=n) return 0;
// if(prev!=-1 && dp[prev][currIdx]!=-1) return dp[prev][currIdx];
// int take=0;
//     if(prev==-1 || abs(s[prev]-s[currIdx])<=k){
//         take= 1+solve(currIdx, currIdx+1,s,k,dp);
//     }
// int  notTake= solve(prev, currIdx+1,s,k,dp);
// if(prev!=-1)
//     dp[prev][currIdx]=max(take, notTake);
//  return max(take, notTake);
// }
//     int longestIdealString(string s, int k) {
//         n=s.length();
//         vector<vector<int >>dp(n+1, vector<int >(n+1,-1));
//         return solve(-1,0,s,k,dp);
//     }

//tle because here for every current index we are starting prev from 0 till i, hence we are checking 
// those eleemnt as well whose difference >k
// int n;
//     int longestIdealString(string s, int k) {
//         n=s.length();

//             vector<int>dp(n,1);
// int maxi=1;
// for(int i=0;i<n;i++){
//     for(int prev=0;prev<i;prev++){
//         if(abs(s[prev]-s[i])<=k ){
//             dp[i]=max(dp[i],1+dp[prev]);
//         }
        
//     }
//     maxi=max(maxi, dp[i]);
  
// }
// return maxi;
//     }


// if we are at current index, then  find elements whose difference with current element <=k 
// k=2, for curr element as b, these elements a,b,c,d difference with b <=k
//        b
//  a  b     c d
//  4  3     5 7 =>length of ideal subsequences ending at a,b,c,d
//  add the b with element which has longest ideal subsequence
//  add b with d
int n;
    int longestIdealString(string s, int k) {
        n=s.length();
        vector<int>dp(26,0);
int result=0;
//o(n)
        for(int i=0;i<n;i++){
            int curr=s[i]-'a'; //gives idx for curr element in dp of size 27
            int left=max(0,curr-k);
            int right=min(curr+k,25);

            int longest=0;
            //in worst case left=0, right=25 constant
            for(int j=left;j<=right;j++){
                longest=max(longest, dp[j]);
            }
            // longest+1 add the current element as well 
            dp[curr]=max(dp[curr],longest+1);
            result=max(result,dp[curr]);
        }
        return result;
  

    }

};