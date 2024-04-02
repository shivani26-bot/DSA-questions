class Solution {
public:
    int lengthOfLastWord(string s) {
int LastWordLength=0;
int flag=false;
int n=s.length();
for(int i=n-1;i>=0;i--){
if(s[i]!=' '){
    flag=true;
    LastWordLength++;
}
else if(flag){
 break;
}
}
return LastWordLength;
    }
};