class Solution {
public:
// recursive
// This is because for each character in text1, we have two recursive calls, one with the 
// character included and one without. Similarly, for each character in text2, we have two recursive calls. 
// time:o(2^n)
// Space complexity: O(max(length of text1,length of text2))
// the maximum recursion depth is bounded by the maximum of the lengths of the two strings.
// int getLCS(int i,string &s1,int j,string &s2){
//     if(i<0 || j<0) return 0;
//     if(s1[i]==s2[j])
//     return 1+getLCS(i-1,s1,j-1,s2);
//     return max(getLCS(i,s1,j-1,s2),getLCS(i-1,s1,j,s2));
// }
//     int longestCommonSubsequence(string text1, string text2) {
    
//         return getLCS(text1.size()-1,text1,text2.size()-1,text2);
//     }
// // top down
// time:o(n*m)
// space: o(n*m)
// int getLCS(int i,string &s1,int j,string &s2, vector<vector<int>>&dp){
//      if(i<0 || j<0) return 0;
//   if(dp[i][j]!=-1) return dp[i][j];
//   if(s1[i]==s2[j])
//   dp[i][j]=1+getLCS(i-1,s1,j-1,s2,dp);
//   else
//   dp[i][j]=max(getLCS(i,s1,j-1,s2,dp),getLCS(i-1,s1,j,s2,dp));
//   return dp[i][j];
// }
//     int longestCommonSubsequence(string text1, string text2) {
//     vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
//       return  getLCS(text1.size()-1,text1,text2.size()-1,text2,dp);
//     }
// bottom top
// int getLCS(int i,string &s1,int j,string &s2, vector<vector<int>>&dp){
//     for(int i=1;i<=s1.length();i++){
//         for(int j=1;j<=s2.length();j++){
//             if(s1[i-1]==s2[j-1])
//             dp[i][j]=1+dp[i-1][j-1];
//             else
//             dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//         }
//     }
//     return dp[s1.length()][s2.length()];
// }

//     int longestCommonSubsequence(string text1, string text2) {
//     vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
//       return  getLCS(text1.size()-1,text1,text2.size()-1,text2,dp);
//     }

// int getLCS(int n, string &text1, int m, string& text2){
// if(n<0 || m<0) return 0;
//     if(text1[n]==text2[m]) return 1+getLCS(n-1,text1,m-1,text2);

//     return max(getLCS(n-1,text1,m,text2),getLCS(n,text1,m-1,text2));
// }
//     int longestCommonSubsequence(string text1, string text2) {
    
//      return  getLCS(text1.size()-1,text1, text2.size()-1,text2);
//     }


int getLCS(int n, string &text1, int m, string& text2,vector<vector<int>>&dp){
if(n<0 || m<0) return 0;
    if(text1[n]==text2[m]) dp[n][m]= 1+getLCS(n-1,text1,m-1,text2,dp);
if(dp[n][m]!=-1) return dp[n][m];
    dp[n][m]= max(getLCS(n-1,text1,m,text2,dp),getLCS(n,text1,m-1,text2,dp));
    return dp[n][m];
}
    int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>>dp(text1.length(), vector<int>(text2.size(),-1));
     return  getLCS(text1.size()-1,text1, text2.size()-1,text2,dp);
    }
};