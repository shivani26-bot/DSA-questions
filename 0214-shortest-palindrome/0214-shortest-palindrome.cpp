class Solution {
public:
    string shortestPalindrome(string s) {
        // brute force
        // think what is stopping a string from becoming a palindrome
        // abad => here d is stopping abcd from becoming a palindrome ie dabad
// abadz=> suffix stops from becoming a string a palindrome ,append those letters in front which create problems in becoming a palindrome
// aabba
// s="aabba"
// srev="abbaa"
// aabba!=abbaa
// aabb!=bbaa
// aab!=baa
// aa==aa  
// culprit is bba, reverse it and append to s, abbaabba

// find the largest valid palindrome in the string s, and the remaining will be the culprit which stops the string from becoming a palindrome
// for ex: aacecaaa=> valid palindrome is aacecaa , remaining 'a' is culprit
// abcd=>no valid palindrome, remaining abcd is culprit 

// if we have a string, and we reverse it, if original string and reverse string are same
// it means that original string is already a palindrome, no need to append anything to that string 
// s="aacecaa"
// srev= "aacecaa"

// s= "abaxz"
// srev="zxaba"
// abaxz != zxaba
// abax != xaba
// aba == aba
// culprit is xz add reverse of it and get the palindrome zxabaxz

// s=abac
// srev=caba
// abac!=caba
// aba==aba
// c is the culprit, rev it and append to s, cabac
// string srev=s;
// reverse(srev.begin(),srev.end());
// if(s==srev) return s;
// int n=s.length();
// int i=n-1; //for s
// int j=0; //for srev
//   string culprit;
// while(i>0){
//   string temp=s.substr(0,i+1);
//   cout<<temp<<endl;
//   string temprev=srev.substr(j,n-j);
//   cout<<temprev<<endl;
//   if(temp!=temprev) {
//     i--;
//     j++;
//     }
// else if(temp==temprev) {
//  culprit= srev.substr(0,j);
//  cout<<"culprit "<<culprit;
//  break;
// }
// }
// string ans;
// if(culprit.empty()) ans=srev.substr(0,n-1)+s;
// else ans= culprit+s;
// return ans;

// string srev=s;
// reverse(srev.begin(),srev.end());
// // o(n*n) we are making substring again and again and then comparing
// // how to avoid making substring 
// // we can use memcmp takes three parameters,( first substring, second substring, length of substring)
// // s string starting from 0th index, srev starting from i index, and n-i length of substring
// // mem_cmp(s.c_str()+0,srev.c_str()+i,s.length()-i)
// int n=s.length();
// for(int i=0;i<n;i++){
//     if(s.substr(0,n-i)==srev.substr(i))
//     return srev.substr(0,i)+s;
// }
// // return "";
// return srev+s;
string srev=s;
reverse(srev.begin(),srev.end());
// o(n*n) we are making substring again and again and then comparing
// how to avoid making substring 
// we can use memcmp takes three parameters,( first substring, second substring, length of substring)
// s string starting from 0th index, srev starting from i index, and n-i length of substring
// memcmp(s.c_str()+0,srev.c_str()+i,s.length()-i)
int n=s.length();
for(int i=0;i<n;i++){
    if(!memcmp(s.c_str(),srev.c_str()+i,n-i))
    return srev.substr(0,i)+s;
}
// return "";
return srev+s;
    }
};