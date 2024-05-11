class Solution {
public:

// ex: s1="?ay"
// s2="ray"    true

// s1="ab*cd"
// s2="abdefcd"  true

// s1="**abcd"
// s2="abcd"  true

// s1="ab?d"
// s2="abcc"   false

// f(n-1,m-1) in string s from 0 to n-1 and in string p from 0 to m-1 are they matching
// for * we can match 0 or more than 0 number of characters

// basecase: either string s or p gets exhausted
// if p gets exhausted j<0 then i must be <0 in order for the comparison to be true
// if p gets exhausted and s is not exhausted 
// if s gets exhuasted and p is not exhausted then s is "" if p has only * remaining then it can match otherwise it will not match

// bool solve(int i, int j, string s, string p){
//  if (j < 0 && i<0 ) {
//         return true; 
//     }
//     if (j < 0 && i>=0 ) {
//         return false; 
//     }
//     if (i < 0 && j>=0) {
//         // Check if all remaining characters in p are '*'
//         for (int k = 0; k <= j; ++k) {
//             if (p[k] != '*') {
//                 return false;
//             }
//         }
//         return true;
//     }
//     if(s[i]==p[j] ||p[j]=='?') return solve(i-1,j-1,s,p);
//     if(p[j]=='*')
//             return solve(i-1,j,s,p) || solve(i,j-1,s,p);
//         // s=abc
//         // p=aec
//        return false;
// }
//     bool isMatch(string s, string p) {
//         int n=s.length();
//         int m=p.length();
//         return solve(n-1,m-1,s,p);
//     }

// top down 
// bool solve(int i, int j, string s, string p, vector<vector<int>>&dp){
//  if (j < 0 && i<0 ) {
//         return true; 
//     }
//     if (j < 0 && i>=0 ) {
//         return false; 
//     }
//     if (i < 0 && j>=0) {
//         // Check if all remaining characters in p are '*'
//         for (int k = 0; k <= j; ++k) {
//             if (p[k] != '*') {
//                 return false;
//             }
//         }
//         return true;
//     }
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s[i]==p[j] ||p[j]=='?') return dp[i][j]=solve(i-1,j-1,s,p,dp);
//     if(p[j]=='*')
//             return dp[i][j]= solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
//         // s=abc
//         // p=aec
//        return dp[i][j]=false;
// }
//     bool isMatch(string s, string p) {
//         int n=s.length();
//         int m=p.length();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1,s,p,dp);
//     }



// top down 
// in order to make sure it doesn't go to negative indexing we follow one based indexing 
// bool solve(int i, int j, string s, string p, vector<vector<int>>&dp){
//  if (j == 0 && i==0 ) {
//         return true; 
//     }
//     if (j == 0 && i>0 ) {
//         return false; 
//     }
//     if (i == 0 && j>0) {
//         // Check if all remaining characters in p are '*'
//         for (int k = 1; k <= j; k++) {
//             if (p[k-1] != '*') 
//                 return false;
//         }
//         return true;
//     }
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s[i-1]==p[j-1] ||p[j-1]=='?') return dp[i][j]=solve(i-1,j-1,s,p,dp);
//     if(p[j-1]=='*')
//             return dp[i][j]= solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
//         // s=abc
//         // p=aec
//        return dp[i][j]=false;
// }
//     bool isMatch(string s, string p) {
//         int n=s.length();
//         int m=p.length();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return solve(n,m,s,p,dp);
//     }


// bottom top 


    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        dp[0][0]=true;

    for(int i=1;i<=n;i++) dp[i][0] =false;
     
     
     for(int j=1;j<=m;j++) {
        int flag=true;
        for(int k=1;k<=j;k++) {
         if (p[k-1] != '*'){
flag = false;
break;
         } 
        }
          dp[0][j] = flag;
     }
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
  if(s[i-1]==p[j-1] ||p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
   else if(p[j-1]=='*')
          dp[i][j]= dp[i-1][j] || dp[i][j-1];
        // s=abc
        // p=aec
    else dp[i][j]=false;
    }
  }
  return dp[n][m];
    }


    
};