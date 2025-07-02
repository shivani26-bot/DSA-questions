class Solution {
public:
// "" "b" "b" true
// "a" "b" "a" false
// "a" "" "a" true
// "a" "" "c" false
//  int s1Len,s2Len,s3Len;
//  bool solve(string s1, string s2, string s3,int i, int j, int k){
//     if(k>=s3Len ) return true;

//     if( s3[k]!=s1[i] && s3[k]!=s2[j]) return false;
//  bool ans1=false,ans2=false;
//     if(s3[k]==s1[i]){
//       ans1= solve(s1,s2,s3, i+1, j, k+1);
//     }
//         if(s3[k]==s2[j]){
//       ans2= solve(s1,s2,s3, i, j+1, k+1);
//     }

//     return ans1||ans2;

//  }
    // bool isInterleave(string s1, string s2, string s3) {
    //     // if s1.length()+s2.length()<s3.length() then its not possible to make s3 from s1 and s2 return false in this case
        
    //  s1Len=s1.length();
    //  s2Len=s2.length();
    //  s3Len=s3.length();
    //  cout<<s1Len<<s2Len<<s3Len;
    //          if(s1Len+s2Len != s3Len) return false;
    //     return solve(s1,s2,s3, 0,0,0);
    // }
//  int s1Len,s2Len,s3Len;
//  bool solve(string s1, string s2, string s3,int i, int j, int k,vector<vector<vector<int>>>&dp){
//     if(dp[i][j][k]!=-1) return dp[i][j][k];
//     if(k>=s3Len ) return true;

//     if( s3[k]!=s1[i] && s3[k]!=s2[j]) return false;
   
//  bool ans1=false,ans2=false;
//     if( s3[k]==s1[i]){
//       ans1= solve(s1,s2,s3, i+1, j, k+1,dp);
//     }
//         if(s3[k]==s2[j]){
//       ans2= solve(s1,s2,s3, i, j+1, k+1,dp);
//     }

//     return dp[i][j][k]=ans1||ans2;

//  }
//     bool isInterleave(string s1, string s2, string s3) {
//         // if s1.length()+s2.length()<s3.length() then its not possible to make s3 from s1 and s2 return false in this case
        
//      s1Len=s1.length();
//      s2Len=s2.length();
//      s3Len=s3.length();
//   vector<vector<vector<int>>>dp(s1Len+1, vector<vector<int>>(s2Len+1,vector<int>(s3Len+1,-1)));
//              if(s1Len+s2Len != s3Len) return false;
//         return solve(s1,s2,s3, 0,0,0,dp);
//     }


 int s1Len,s2Len,s3Len;
 bool solve(string s1, string s2, string s3,int i, int j,vector<vector<int>>&dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if((i+j)>=s3Len ) return true;

    if( s3[i+j]!=s1[i] && s3[i+j]!=s2[j]) return false;
   
 bool ans1=false,ans2=false;

    if(s3[i+j]==s1[i]){
      ans1= solve(s1,s2,s3, i+1, j,dp);
    }
        if(s3[i+j]==s2[j]){
      ans2= solve(s1,s2,s3, i, j+1,dp);
    }
    return dp[i][j]=ans1||ans2;
 }

    bool isInterleave(string s1, string s2, string s3) {
        // if s1.length()+s2.length()<s3.length() then its not possible to make s3 from s1 and s2 return false in this case
     s1Len=s1.length();
     s2Len=s2.length();
     s3Len=s3.length();
  vector<vector<int>>dp(s1Len+1,vector<int>(s2Len+1,-1));
             if(s1Len+s2Len != s3Len) return false;
        return solve(s1,s2,s3, 0,0,dp);
    }
};