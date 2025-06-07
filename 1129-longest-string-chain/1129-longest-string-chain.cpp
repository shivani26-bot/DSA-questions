class Solution {
public:
// similar to lis, difference here is we make sure that current word and previous word differes by one character in the entire subsequence.
// https://leetcode.com/problems/longest-increasing-subsequence/description/
// we form arr[curr] by inserting one character on arr[prev]
// when we compare two words and while comparing each character they both end at the same time then it means they are matching for ex: bdca bda
// but if they don't end simultaneously
// bcda bcd also check the length of the previous word and current word

// we need a  sequence not a subsequence hence its like a subset we can start from anywhere and include any elements
// time n^2 * length of string + o(n)
// bool checkPossible(string &s1, string &s2){
//     if(s1.size() != s2.size()+1) return false;
//     int first=0;
//     int second=0;
//     while(first<s1.size()){
//         if(s1[first]== s2[second]){
//             first++;
//             second++;
//         }
//         else{
//             first++;
//         }
//     }
//     if(first==s1.size() && second==s2.size()) return true;
//     return false;
// }


// bool static comp(string &s1 , string &s2){
//     return s1.size()<s2.size();
// }


//     int longestStrChain(vector<string>& words) {
//         int n=words.size();
//         // sort the array based on lengths 
//         sort(words.begin(),words.end(),comp);
// vector<int>dp(n,1);
// int maxi=1;
// int lastIndex=0;
// // word[i] is the greater and word[prev] is  the smaller
// for(int i=0;i<words.size();i++){
//     for(int prev=0;prev<i;prev++){
//         // if(checkPossible(words[i],words[prev]) && 1+dp[prev]>dp[i]){
//         //     dp[i]=1+dp[prev];
            
//         // }
//            if(checkPossible(words[i],words[prev])){
//     dp[i]=max(dp[i],1+dp[prev]);
            
//         }
//     }
//     if(dp[i]>maxi){
//         maxi=dp[i];
   
//             }
// }
//      return maxi;
//     }


bool checkPossible(string& s1, string&s2){
    if(s1.size()!=s2.size()+1) return false;
    int f1=0, f2=0;//f1 points to s1 and f2 points to s2
    while(f1<s1.size()){
        if(s1[f1]==s2[f2]){
            f1++;
            f2++;
        }
        else{
            f1++;
        }
    }
    if(f1==s1.size() && f2==s2.size()) return true;
    return false;
}
bool static comp(string& s1, string& s2){
    return s1.size()<s2.size();
}

 int longestStrChain(vector<string>& words) {
 int n=words.size();

 sort(words.begin(),words.end(),comp);

vector<int>dp(n,1);
int ans=1; //if words size=1 then only 1 answer will be there, ans denotes the lenght of the longes possible word chain
for(int i=0;i<n;i++){
    for(int j=0;j<i; j++){
        if(checkPossible(words[i], words[j])){
            dp[i]=max(dp[i],1+dp[j]);
        }
    }
    ans= max(ans, dp[i]);
}
return ans;
    }



};