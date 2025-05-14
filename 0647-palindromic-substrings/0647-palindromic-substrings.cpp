class Solution {
public:
//recursive+bruteforce
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
//memoization
// int dp[1001][1001];
// bool checkPalindrome(int i, int j, string &s){
// if(i>=j) return 1;
// if(dp[i][j]!=-1) return dp[i][j];
//     if(s[i]==s[j]) return dp[i][j]=checkPalindrome(i+1,j-1,s);
//     else return dp[i][j]=0;
// }
//     int countSubstrings(string s) {
//         int n=s.length();
//         memset(dp,-1,sizeof(dp));
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


//bottom up o(n^2)
//blueprint 
// 2 states are changing i, j, 
// dp[i][j] will tell substring from i to j is palindrome or not
// all the substring of 1 length are palindrome in itself, i==j ie diagonal element in the 2d dp array will be true
// substring of length 2, just check s[i] is equal to s[j] where j=i+1 or not
// if substring is of length >2 then follow generic method
// if we have to find for index (i,j) and s[i]==s[j] then try to 
// find the answer of i+1, j-1 recursively whether they 
// are palindrome or not

// _,_,_,_,_,_,_
// 0 1 2 3 4 5 6
// length 1 ka substring: (i,i) (0,0) (1,1) (2,2)....so on
// length 2 ka substring: (0,1)....
// length 3 ka substring: (0,2)....
// length of substring can be maximum = size of given string, n
// for(L=1;L<=n;L++){
//     // for every length we will start i from 0, hence we can find j, if 
//     // given i and L
//   for(i=0;i+L-1<=n;i++){
//     // if L=2,i=0, j= i+L-1 //0+2-1=1
//     // hence range is from 0,1
//     if(i==j) dp[i][i]=true;
//     else if(i+1==j){
//         //2 length string
//         dp[i][j]= (s[i]==s[j])
//     }
//     else{
//         //generic for substring > length 2
//         dp[i][j]= ((s[i]==s[j] && dp[i+1][j-1]))
//     }
//     if(dp[i][j]==true) count++;
//   }
// }
    int countSubstrings(string s) {
       int n=s.length();
       vector<vector<bool>>dp(n,vector<bool>(n,false));
       int count=0;
       //for every length of substring, find the substring
       for(int L=1;L<=n;L++){//length of substring

        for(int i=0;i+L-1<n;i++){ //start index of substring
            int j=i+L-1; //end index of substring
            if(i==j){
                //for one character
                dp[i][j]=true;
            }
            else if(i+1==j){
                // for 2 characters 
                dp[i][j]=(s[i]==s[j]);
            }
            else{
                // for substring having more than 2 characters , generic 
                dp[i][j]= (s[i]==s[j] && dp[i+1][j-1]);
            }
            if(dp[i][j]==true){
                count++;
            }
        }
       }
        return count;
    }
   
};



