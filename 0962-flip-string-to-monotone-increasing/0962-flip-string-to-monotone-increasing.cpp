class Solution {
public:
int n;
// maintain currIdx, prevElement
// if(s[currIdx]=='0'){
//     2 options
//     prev curr
//     0.    0.  => 00 or 01
//     if(prev==0){
//         flip=1+solve(i+1,s[i]);
//         notflip=solve(i+1,s[i]);
//     }
//      prev curr
//       1    0.  => 11
//     else if(prev==1){
//         flip=1+solve(i+1,s[i])
//     }
// }
// else{//currIdx=='1'
//       2 options
//     prev curr
//      0    1  => 00 or 01
//     if(prev==0){
//           flip=1+solve(i+1,s[i]);
//         notflip=solve(i+1,s[i]);
//     }
//     prev curr
//      1    1  => no flip 11
//     else if(prev==1){
//          notflip=solve(i+1,s[i])
//     }
// }
// int solve(int currIdx,int prev,string &s){

// if(currIdx>=n) return 0;
// int flip=INT_MAX;int notflip=INT_MAX;
// if(s[currIdx]=='0'){
//     if(prev==0){
//         flip=1+solve(currIdx+1,1,s);
//         notflip=solve(currIdx+1,0,s);
//     }
//     else if(prev==1){
//         flip=1+solve(currIdx+1,1,s);
//     }
// }
// else{//currIdx=='1'
//     if(prev==0){
//           flip=1+solve(currIdx+1,0,s);
//         notflip=solve(currIdx+1,1,s);
//     }
//     else if(prev==1){
//          notflip=solve(currIdx+1,1,s);
//     }
// }
//     return min(flip,notflip);
// }
//     int minFlipsMonoIncr(string s) {
//         n=s.length();
//         return solve(0,0,s);
//     }
int solve(int currIdx,int prev,string &s,vector<vector<int>>&dp){

if(currIdx>=n) return 0;
if(dp[currIdx][prev]!=-1) return dp[currIdx][prev];
int flip=INT_MAX;int notflip=INT_MAX;
if(s[currIdx]=='0'){
    if(prev==0){
        flip=1+solve(currIdx+1,1,s,dp);
        notflip=solve(currIdx+1,0,s,dp);
    }
    else if(prev==1){
        flip=1+solve(currIdx+1,1,s,dp);
    }
}
else{//currIdx=='1'
    if(prev==0){
          flip=1+solve(currIdx+1,0,s,dp);
        notflip=solve(currIdx+1,1,s,dp);
    }
    else if(prev==1){
         notflip=solve(currIdx+1,1,s,dp);
    }
}
    return dp[currIdx][prev]=min(flip,notflip);
}
    int minFlipsMonoIncr(string s) {
        n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,0,s,dp);
    }
};