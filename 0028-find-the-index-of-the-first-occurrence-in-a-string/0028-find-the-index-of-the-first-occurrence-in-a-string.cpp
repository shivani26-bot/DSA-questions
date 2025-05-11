
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



// //rabin karp algo , single hashing
// class Solution {
// public:
// typedef long long ll;
// const ll MOD =1e9+7;
  
//   ll computeHash(string str , ll radix, ll m){
      
//       ll factor=1, hash=0;
//       for(ll i=m-1;i>=0;i--){
//           hash+=((str[i]-'a')*factor)%MOD;
//           factor=(factor*radix)%MOD;
//       }
//       return hash%MOD;
//   }
//     int strStr(string haystack, string needle) {
//         string pattern= needle;
//         string text= haystack;
//      int n=text.length(),m=pattern.length();
//      if(n<m) return -1;
//         ll radix=26,maxWeight=1;
//         for(ll i=1;i<=m;i++){
//             maxWeight= (maxWeight* radix)%MOD; // 26^m
//         }
//         //compute hash of pattern
//         ll hashPattern =computeHash(pattern, radix, m);
//         ll hashText= 0;
        
//         //compare hashes of s with pattern
//         for(ll i=0;i<=n-m;i++){
//             if(i==0)  hashText= computeHash(text,radix, m);
//         else {
//             // In modular arithmetic, subtraction can cause negative numbers, which are not valid modulo results (since mod should always return a value in the range [0, MOD-1]).
//             // This ensures that even if subtracting the old character causes a negative result, adding MOD makes it non-negative before taking % MOD again.
//             hashText=((hashText*radix)%MOD - ((text[i-1]-'a')*maxWeight)%MOD +(text[i+m-1]-'a') +MOD)%MOD;
//             //  hashText = (hashText * radix - (haystack[i - 1] - 'a') * maxWeight % MOD + MOD) % MOD;
//             // hashText = (hashText + (haystack[i + m - 1] - 'a')) % MOD;
//             }

            
//         if(hashPattern==hashText){
//            bool match = true;
// for (ll j = 0; j < m; j++) {
//     if (pattern[j] != text[i + j]) {
//         match = false;
//         break;
//     }
// }
// if (match) return i;
            
//         }
//         }
//         return -1;
//     }
// };





//rabin karp algo , double hashing
class Solution {
public:
typedef long long ll;
const ll MOD1 =1e9+7;
const ll MOD2 =1e9+33;
const ll RADIX1=26;
const ll RADIX2=27;

  pair<ll,ll> computeHash(string str , ll m){
      
      ll factor1=1, hash1=0, factor2=1, hash2=0;
      for(ll i=m-1;i>=0;i--){
          hash1+=((str[i]-'a')*factor1)%MOD1;
          factor1=(factor1*RADIX1)%MOD1;
            hash2+=((str[i]-'a')*factor2)%MOD2;
          factor2=(factor2*RADIX2)%MOD2;
      }
      return {hash1%MOD1,hash2%MOD2};
  }
    int strStr(string haystack, string needle) {
        string pattern= needle;
        string text= haystack;
     int n=text.length(),m=pattern.length();
     if(n<m) return -1;
        ll maxWeight1=1,maxWeight2=1;
        for(ll i=1;i<=m;i++){
            maxWeight1= (maxWeight1* RADIX1)%MOD1; // 26^m
             maxWeight2= (maxWeight2* RADIX2)%MOD2;//  27^m
        }
        //compute hash of pattern
        pair<ll,ll> hashPattern =computeHash(pattern, m);
        pair<ll,ll> hashText= {0,0};
        
        //compare hashes of s with pattern
        for(ll i=0;i<=n-m;i++){
            if(i==0)  hashText= computeHash(text, m);
        else {
      
hashText.first=((hashText.first*RADIX1)%MOD1 - ((text[i-1]-'a')*maxWeight1)%MOD1 +(text[i+m-1]-'a') +MOD1)%MOD1;
hashText.second=((hashText.second*RADIX2)%MOD2 - ((text[i-1]-'a')*maxWeight2)%MOD2 +(text[i+m-1]-'a') +MOD2)%MOD2;
            }

            
        if(hashPattern.first==hashText.first && hashPattern.second==hashText.second){
          return i;
        }
        }
        return -1;
    }
};