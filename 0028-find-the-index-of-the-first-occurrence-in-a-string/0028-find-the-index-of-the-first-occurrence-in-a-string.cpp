class Solution {
public:
void computeLPS(string &pattern, vector<int>&LPS, int m){
    LPS[0]=0;
    int length=0;//length of lps
    int i=1;
while(i<m){
    if(pattern[i]==pattern[length]){
        length++;
        LPS[i]=length;
        i++;
    }
    else{
        if(length!=0)
        length=LPS[length-1];
        else{
            LPS[i]=0;
            i++;
        }
    }
}
}
    int strStr(string haystack, string needle) {
        
        int i=0,j=0;
        int n=haystack.length();
        int m=needle.length();
        if(n<m) return -1;
        vector<int>LPS(m,0);
        computeLPS(needle, LPS, m);
        while(i<n){
          if(haystack[i]==needle[j]){
            i++;
            j++;
          }
          if(j==m){
            return i-m;
          }
          else if(haystack[i]!=needle[j]){
            if(j!=0)
            j=LPS[j-1];
            else i++;
          }
        }
        return -1;
    }
};