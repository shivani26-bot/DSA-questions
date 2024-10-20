class Solution {
public:
// bool checkPalindrome(int i, int j, string &s){
// if(i>=j) return true;
//     if(s[i]==s[j]) return checkPalindrome(i+1,j-1,s);
//     else return false;
// }
//     int countSubstrings(string s) {
//         int n=s.length();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(checkPalindrome(i,j,s)){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

// dp
int dp[1001][1001];
bool checkPalindrome(int i, int j, string &s){
if(i>=j) return 1;
if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j]=checkPalindrome(i+1,j-1,s);
    else return dp[i][j]=0;
}
    int countSubstrings(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkPalindrome(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};