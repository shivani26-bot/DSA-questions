class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
string ans="";
int carry=0;
        while(i>=0 || j>=0 || carry){
if(i>=0){
    carry+= a[i]-'0';//char-char=number, 49-48=1, char converts to ascii number
    i--;
}
if(j>=0){
    carry+=b[j]-'0';
    j--;
}

ans+= carry%2+'0';//+'0' to convert the number to char;
carry=carry/2;

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};