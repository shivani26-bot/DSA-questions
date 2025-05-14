class Solution {
public:
// s=babad
// try all the possible substrings, and check whether they are palindromic substrings or not
// b, ba, bab, baba, babad, a, ab, aba, abad, b, ba, bad, a, ad, d

// b    abad    b  a  bad
// i,j          i  j
// b a bad  bab ad  baba d
// i   j    i   j   i    j
// b a   bad b a bad  b a b ad  b a b ad
//  i,j        i j      i   j     i    j
// store maxLength and starting point
// maxLength=-1, sp=0
// if you find a palindromic substring anywhere then update starting point accordingly
// for that palindromic substring ,sp=i
// s="aaaaaaa"
// solve(0,5)
// (0,5)->(1,4)->(2,3)
// solve(1,4)
// (1,4)->(2,3) repeating subproblems
// we can store in dp array for (0,5) that (0,5) is true, (1,4) is true, (2,3) is true
// when we call (1,4) no need to check further and we can directly return true 
// bool checkPalindrome(int i, int j, string &s){
//     while(i<=j){
//         if(s[i]!=s[j]) return false;
//         i++;
//         j--;
//     }
//     return true;
// }
//recursive
// o(n^3)
bool checkPalindrome(int i, int j, string &s){
   if(i>=j) return true;
        if(s[i]==s[j]) return checkPalindrome(i+1,j-1,s);
return false;
}
    string longestPalindrome(string s) {
        int n=s.length();
        
int maxLen=INT_MIN;
// int sp=0; //starting point of the substring
string ans;
        for(int i=0;i<n;i++){//o(n^2)
            for(int j=i;j<n;j++){
                if(checkPalindrome(i,j,s)==true){ //o(n)
                   if(j-i+1>maxLen){
                    maxLen=j-i+1;
                    // sp=i;
                    ans= s.substr(i,maxLen);
                   }
                }
            }
        }
        // return s.substr(sp,maxLen);
            return ans;
    }

//dp
//o(n^3)
// int dp[1001][1001];
// bool checkPalindrome(int i, int j, string &s){
//    if(i>=j) return 1; //true
//    if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==s[j]) return dp[i][j]=checkPalindrome(i+1,j-1,s);
// return dp[i][j]=0; //false
// }
//     string longestPalindrome(string s) {
//         int n=s.length();
//        memset(dp,-1, sizeof(dp)); 
// int maxLen=INT_MIN;
// int sp=0; //starting point of the substring
//         for(int i=0;i<n;i++){ //o(n^2)
//             for(int j=i;j<n;j++){
//                 if(checkPalindrome(i,j,s)){
//                    if(j-i+1>maxLen){
//                     maxLen=j-i+1;
//                     sp=i;
//                    }
//                 }
//             }
//         }
//         return s.substr(sp,maxLen);
//     }


};


// acceptable time complexities 
// O(1)
// O(\log n) (e.g., binary search)
// O(n) (e.g., single-pass algorithms)
// O(n \log n) (e.g., efficient sorting algorithms)
// O(n^2) (e.g., dynamic programming or algorithms involving pairwise comparisons)
// infeasible 
// O(n^3) (e.g., some brute-force algorithms)
// O(2^n) (e.g., recursive backtracking with no pruning)
// O(n!) (e.g., exhaustive combinatorial algorithms)