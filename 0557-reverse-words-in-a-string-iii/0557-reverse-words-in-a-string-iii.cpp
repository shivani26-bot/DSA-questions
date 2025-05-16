class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0,j=0;
        string ans;
        while(j<n){
             string newStr;
if(s[j]==' '){
 newStr= s.substr(i,j-i);
  reverse(newStr.begin(),newStr.end());
  ans= ans+newStr+' ';
  i=j+1;
}   
else if(j==n-1){
 newStr= s.substr(i,j-i+1);
  reverse(newStr.begin(),newStr.end());
  ans= ans+newStr;
}
         j++;
        }
        return ans;
    }
};