// class Solution {
// public:
// // int getLCS(int i,string &s1,int j,string &s2, vector<vector<int>>&dp){
// //      if(i<0 || j<0) return 0;
// //   if(dp[i][j]!=-1) return dp[i][j];
// //   if(s1[i]==s2[j])
// //   dp[i][j]=1+getLCS(i-1,s1,j-1,s2,dp);
// //   else
// //   dp[i][j]=max(getLCS(i,s1,j-1,s2,dp),getLCS(i-1,s1,j,s2,dp));
// //   return dp[i][j];
// // }
// //     int longestCommonSubsequence(string &text1, string &text2) {
// //     vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
// //       return  getLCS(text1.size()-1,text1,text2.size()-1,text2,dp);
// //     }
// //     int longestPalindromeSubseq(string s) {
// //         string revs= s;
// //         reverse(revs.begin(),revs.end());
// //         return longestCommonSubsequence(s,revs);
// //     }

// // recursive
// // int getLPS(string &s, int i, int j){
// //     if(i>j) return 0;
// //     if(i==j) return 1;
// //     if(s[i]==s[j]) return 2+getLPS(s,i+1,j-1);
// //     return max(getLPS(s,i,j-1),getLPS(s,i+1,j));
// // }
// // // top down
// // int getLPS(string &s, int i, int j,vector<vector<int>>&dp){
// //     if(i>j) return 0;
// //     if(i==j) return 1;
// //     if(dp[i][j]!=-1) return dp[i][j];
// //     if(s[i]==s[j]) dp[i][j]=2+getLPS(s,i+1,j-1,dp);
// //     else
// //     dp[i][j]= max(getLPS(s,i,j-1,dp),getLPS(s,i+1,j,dp));
// //     return dp[i][j];
// // }
// //     int longestPalindromeSubseq(string s) {
// //         vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));

// //        return getLPS(s,0,s.length()-1,dp);
// //     }
// // bottom top
// int getLPS(string &s,vector<vector<int>>&dp){
//    for(int i=0;i<s.length();i++){
//        dp[i][i]=1;
//    }
//    for(int d=1;d<s.length();d++){
//        int i=0,j=d;
//        while(i<s.length() && j<s.length()){
//            if(s[i]==s[j])
//            dp[i][j]=2+dp[i+1][j-1];
//            else
//            dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
//            i++;
//            j++;
//        }
//    }
//    return dp[0][s.length()-1];
// }
//     int longestPalindromeSubseq(string s) {
//         vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));

//        return getLPS(s,dp);
//     }
// };

class Solution {
public:
int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //   for(int i=0;i<=n;i++) dp[i][0]=0;
        // for(int j=0;j<=m;j++) dp[0][j]=0;
             vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
        
        
        for(int index1=1;index1<=n;index1++){
            for(int index2=1;index2<=m;index2++){
             if(s1[index1-1]==s2[index2-1])   
            dp[index1][index2]=1+dp[index1-1][index2-1];
        else
          dp[index1][index2]=max(dp[index1-1][index2],dp[index1][index2-1]);
    
            }
        }
      return dp[n][m];
        
    }
    int longestPalindromeSubseq(string s) {
        string s1= s;
        reverse(s.begin(),s.end());
        int n=s.length();
        int m=s1.length();
        return lcs(n,m,s,s1);
    }
};