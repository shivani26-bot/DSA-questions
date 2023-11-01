class Solution {
public:
bool isValidCode(int code, int length){
    if(length==1) return code>=1 && code<=9;
    else
   return  code>=10 && code<=26;
}
//recursion

// int countWays(string&s, int i){
//     //for empty strings
// if(i>=s.length()) return 1;
// int count=0;
//     if(isValidCode(s[i]-'0',1)){
//         count+=countWays(s,i+1);
//     }
//     if(i<s.length()-1 && isValidCode((s[i]-'0')*10+s[i+1]-'0',2)){
//         count+=countWays(s,i+2);
//     }
//     return count;
// }
//     int numDecodings(string s) {
//        return countWays(s,0); 
//     }
//top down approach
// int countWays(string&s, int i, vector<int>&dp){
//     //for empty strings
// if(i>=s.length()) return 1;
// if(dp[i]!=-1) return dp[i];
// dp[i]=0;
//     if(isValidCode(s[i]-'0',1)){
//        dp[i]+=countWays(s,i+1,dp);
//     }
//     if(i<s.length()-1 && isValidCode((s[i]-'0')*10+s[i+1]-'0',2)){
//         dp[i]+=countWays(s,i+2,dp);
//     }
//     return dp[i];
// }
//     int numDecodings(string s) {
//    vector<int>dp(s.length(),-1);
//        return countWays(s,0,dp); 
//     }
// bottom top tabulation
int countWays(string&s, int i){
     vector<int>dp(s.length(),0);
     dp[0]= isValidCode(s[0]-'0',1)?1:0;
     if(s.length()==1) return dp[0];
     dp[1]=0;
     if(isValidCode(s[1]-'0',1))
     dp[1]+=dp[0];
     if(isValidCode((s[0]-'0')*10+s[1]-'0',2)){
         dp[1]++;
     }
     for(int i=2;i<s.length();i++){
         dp[i]=0;
          if(isValidCode(s[i]-'0',1))
     dp[i]+=dp[i-1];
     if(isValidCode((s[i-1]-'0')*10+s[i]-'0',2)){
         dp[i]+=dp[i-2];
     }
     }
    
    return dp[s.length()-1];
}
    int numDecodings(string s) {
 
       return countWays(s,0); 
    }
};

