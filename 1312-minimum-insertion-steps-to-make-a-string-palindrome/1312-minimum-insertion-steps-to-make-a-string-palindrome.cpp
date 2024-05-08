class Solution {
public:
// operations = len(s);
// we can make a given string as pallindrome , add s+ rev(s)
// s=abcaa reverse of s is aaccba
// abcaa + aacba= abcaaaacba is a pallindrome
// max operations = length(s);
// a abc b aa we add a and b to abcaa then it's a pallindrome
// number of insertion 2, we can insert in so manhy different ways 
// keep the longest pallindromic portion in the original string s intact
// ie abcaa-> we have a, aa aaa, aba, aca are pallindromes
// for ex: lets keep aaa intact that is the longest pallindromic portion
// a bc aa=> a bc a cb a keep a a a intact and whichever is not a portion of it 
// .    ..   .    .    .
// that is bc we can reverse bc ie cb  and keep it in the right half or whereever it's required

// . -> indicates those elements are intact 
// if we keep aca as intact, a b c a a => a b a c a b a
//                           .   .   .    .     .     .
// hence we can keep any of the longest pallindrome intact and perform the similar operation

// ex: codingninjas
// lps: ingni keep it intact, appart from that rest of them get copied
//      codi  sajn  ingni   njas  idoc
//                  .....
// hence number of insertions = s.length()-lps
int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
          for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        
        
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
    int minInsertions(string s) {
        int n=s.length();
        return (n -  longestPalindromeSubseq(s));
    }
};