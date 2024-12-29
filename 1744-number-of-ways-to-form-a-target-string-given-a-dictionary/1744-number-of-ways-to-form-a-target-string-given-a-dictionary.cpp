class Solution {
public:
const int MOD =1e9+7;
int solve(int i, int j, vector<vector<long long>>&freq, string &target, vector<vector<int>>&dp,int k, int m){
    if(i==m) return 1;
    if(j==k) return 0;
if(dp[i][j]!=-1) return dp[i][j];
    int not_taken=solve(i,j+1,freq,target,dp,k,m)%MOD;
    int taken= freq[target[i]-'a'][j]* solve(i+1,j+1,freq,target,dp,k,m)%MOD;

    dp[i][j]= (taken+not_taken)%MOD;
    return dp[i][j];
}
    int numWays(vector<string>& words, string target) {
        // 3rd point of the rule means: if we suppose use 0th index of any string in words array to form a target , then we will not be able to use the same index ie 0th index of any other string further to form a target and also all the charater left to the chosen index ie 0th index in this case can't be use
        // for ex: if we use 3rd index to form a target then 3rd index of remaining strings can't be used further as well all the characters left to the 3rd index of any string in the word array can be used
        // 01234
        // abcde => if we choose 3rd index ie d, then all the characters left to it ie abc can't be choosen for this string as well as other string present in the words array 
    //     0 1 2 3
    //   0 a c c a
    //   1 a b b b
    //   2 c a c a
//     words = ["acca","abba","caca"], target = "aba"
//     if we take 0th index ie a
//     (acca,abba,caca)
// (cca,bba,aca)  (cca,bba,aca) (next states), we have repetative states here
// we can count how many a's at 0th index, we can multiply countofa's*(cca,bba,aca)
// hence store that how many count of characters of each type at each index
// for ex: for index 0-> how many a's , b's, c's etc
//   0 1 2 3 -> index , freq table stores for each index, how many count of each character
// a
// b
// c
// d
// e
// f
// .
// .
// z

// i=0->target index
// j=0->dictionary index

// if we don't take the jth index then we can move forward with j+1
// if we take the jth index then we can take that character as many times that is occuring at that index in all the strings
//            j
// ex: words=[acca,abbb,caca]
// target="aba"
     //    i
// if take character a at 0th index , then we have two option we can take char a at index 0 in first string
// and char a at index 0 in second string in words array
// taken - freq[target[i]-'a'][j]* solve(i+1,j+1);
// nottaken - solve(i,j+1);

//         return not_taken+taken
// base case: if(i==m) return 1;
// if(j==k) return 0;//k= size of each string in words array 
//  int k=words[0].length();
//  int m=target.length();
//  vector<vector<int>>freq(26,vector<int>(k,0));
//  for(int col=0;col<k;col++){
//     for(string &word: words){
//        freq[word[col]-'a'][col]++;
//     }
//  }
//  return solve(0,0,freq,target);

// top-down 
 int k=words[0].length();
 int m=target.length();
 vector<vector<long long>>freq(26,vector<long long>(k,0));
 for(int col=0;col<k;col++){
    for(string &word: words){
       freq[word[col]-'a'][col]++;
    }
 }
 vector<vector<int>>dp(m, vector<int>(k,-1));
 return solve(0,0,freq,target,dp,k,m);
    
}
};