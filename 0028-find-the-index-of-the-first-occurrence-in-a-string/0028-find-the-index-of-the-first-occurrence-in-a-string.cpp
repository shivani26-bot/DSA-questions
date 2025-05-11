
// //kmp algo 
// class Solution {
// public:
// void computeLPS(string &pattern, vector<int>&LPS, int m){
//     LPS[0]=0;
//     int length=0;//length of lps
//     int i=1;
// while(i<m){
//     if(pattern[i]==pattern[length]){
//         length++;
//         LPS[i]=length;
//         i++;
//     }
//     else{
//         if(length!=0)
//         length=LPS[length-1];
//         else{
//             LPS[i]=0;
//             i++;
//         }
//     }
// }
// }
//     int strStr(string haystack, string needle) {
        
//         int i=0,j=0;
//         int n=haystack.length();
//         int m=needle.length();
//         if(n<m) return -1;
//         vector<int>LPS(m,0);
//         computeLPS(needle, LPS, m);
//         while(i<n){
//           if(haystack[i]==needle[j]){
//             i++;
//             j++;
//           }
//           if(j==m){
//             return i-m;
//             //j=LPS[j-1];//to find multiple occurences
//           }
//           else if(haystack[i]!=needle[j]){
//             if(j!=0)
//             j=LPS[j-1];
//             else i++;
//           }
//         }
//         return -1;
//     }
// };



//rabin karp algo 
class Solution {
public:
typedef long long ll;
const ll MOD =1e9+7;
  
  ll computeHash(string str , ll radix, ll m){
      
      ll factor=1, hash=0;
      for(ll i=m-1;i>=0;i--){
          hash+=((str[i]-'a')*factor)%MOD;
          factor=(factor*radix)%MOD;
      }
      return hash%MOD;
  }
    int strStr(string haystack, string needle) {
        string pattern= needle;
        string text= haystack;
     int n=text.length(),m=pattern.length();
     if(n<m) return -1;
        ll radix=26,maxWeight=1;
        for(ll i=1;i<=m;i++){
            maxWeight= (maxWeight* radix)%MOD; // 26^m
        }
        //compute hash of pattern
        ll hashPattern =computeHash(pattern, radix, m);
        ll hashText= 0;
        
        //compare hashes of s with pattern
        for(ll i=0;i<=n-m;i++){
            if(i==0)  hashText= computeHash(text,radix, m);
        else {
            // hashText=((hashText*radix)%MOD - ((text[i-1]-'a')*maxWeight)%MOD +(text[i+m-1]-'a') +MOD)%MOD;
             hashText = (hashText * radix - (haystack[i - 1] - 'a') * maxWeight % MOD + MOD) % MOD;
            hashText = (hashText + (haystack[i + m - 1] - 'a')) % MOD;
            }

            
        if(hashPattern==hashText){
           bool match = true;
for (ll j = 0; j < m; j++) {
    if (pattern[j] != text[i + j]) {
        match = false;
        break;
    }
}
if (match) return i;
            
        }
        }
        return -1;
    }
};