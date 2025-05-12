class Solution {
public:
    bool isPalindrome(string s) {
       string newString="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]+32;
                cout<<s[i]<<endl;
            }
            if((s[i]>='a' && s[i]<='z')||( s[i]>='0' && s[i]<='9')){
       
                newString+=s[i];
            }
        }
cout<<newString;
        int m=newString.length();
        int i=0, j=m-1;
        while(i<=j){
            if(newString[i]!=newString[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};