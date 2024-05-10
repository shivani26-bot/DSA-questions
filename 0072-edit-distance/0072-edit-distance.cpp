class Solution {
public:
// one way: we can delete all the characters in s1 and then insert the character present in s2 to s1
// max of  o(n+m) time will be taken
// but we have to do this with minimum operation 
// f(n-1, m-1) minimum operation to convert s1[0...i] to s2[0...j]
// if s1[i]!=s2[j] then you can insert in s1 to match with s2[j] then
// i remain there and j moves because we are inserting in s1 hypothetically f(i,j-1); 
// for ex: horse  => if we insert then horses now end char of s1 matches end char of s2
//             i                           i
//         ros
//           j
// if we delete the character then , f(i-1,j)
// for ex: horse  =>delete e to match s in horse with s in ros
//             i
//         ros
//           j
// if we replace:  f(i-1, j-1)
// for ex: horse =>replace: horss   ros
//             i               i     j
//         ros
//           j
// base case: if(i<0) ie s1 gets exhausted, for ex:  h o r s e
//                                                -1 0 1 2 3 4 
//                                                 i
//                                                 r o s
//                                                 0 1 2
//                                                   j
// we want to make ro, then number of operation to make ro is 2 insert operations ie m-j or j+1
// f(-1,1) => minimum operations to convert empty string to a s2[0...1] "ro"
// if(j<0) return i+1;
// s1= h o r s e   s2=   r o s
//     0 1 2 3 4      -1 0 1 2
//         i           j
//         f(2,-1) minimum operations to convert "hor" to "" empty string, 3 delete operations
// int solve(int i,int j,string word1, string word2 ){
//     if(i<0) return j+1;
//     if(j<0) return i+1;
//     if(word1[i]==word2[j]) return solve(i-1,j-1,word1,word2);
//     else
//     return 1 + min(solve(i,j-1,word1,word2),min(solve(i-1,j-1,word1,word2),solve(i-1,j,word1,word2)));
// }
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         return solve(n-1,m-1, word1, word2);
//     }

// top down 
// int solve(int i,int j,string word1, string word2,vector<vector<int>>&dp){
//     if(i<0) return j+1;
//     if(j<0) return i+1;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(word1[i]==word2[j]) return solve(i-1,j-1,word1,word2,dp);
//     else
//     return 1 + min(solve(i,j-1,word1,word2,dp),min(solve(i-1,j-1,word1,word2,dp),solve(i-1,j,word1,word2,dp)));
// }
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1, word1, word2,dp);
//     }

// bottom top
// to avaoid negative indexing we take 1 based indexing 
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//           for(int i=0;i<=n;i++) dp[i][0]=i;
//     for(int j=1;j<=m;j++)  dp[0][j]=j;
   
//    for(int ind1=1;ind1<=n;ind1++){
//     for(int ind2=1;ind2<=m;ind2++){
//         if(word1[ind1-1]==word2[ind2-1]) dp[ind1][ind2]= dp[ind1-1][ind2-1];
//     else
//     dp[ind1][ind2]= 1 + min(dp[ind1][ind2-1],min(dp[ind1-1][ind2-1],dp[ind1-1][ind2]));  
//     }
//    }
//    return dp[n][m];
//     }

// space optimize
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
       vector<int>prev(m+1,0),curr(m+1,0);
   
    for(int j=0;j<=m;j++)  prev[j]=j;
   
   for(int ind1=1;ind1<=n;ind1++){
    curr[0] = ind1;
    for(int ind2=1;ind2<=m;ind2++){
        if(word1[ind1-1]==word2[ind2-1]) curr[ind2]= prev[ind2-1];
    else
    curr[ind2]= 1 + min(curr[ind2-1],min(prev[ind2-1],prev[ind2]));  
    }
    prev=curr;
   }
   return prev[m];
    }
};