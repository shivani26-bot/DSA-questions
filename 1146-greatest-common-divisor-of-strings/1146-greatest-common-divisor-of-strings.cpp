class Solution {
public:
bool valid(string str1,string str2, int k){
// first check that length of str1 and str2 is divisible by k or not, this tells whether string of k size can be a valid gcd string or not 
int len1=str1.length();
int len2=str2.length();
if(len1%k>0 || len2%k>0){
    return false;
}else{
    // now check whether the current string of length k can be a gcdbase or not 
    string base= str1.substr(0,k);
    int n1= len1/k, n2=len2/k;
    return str1==joinWords(base,n1) && str2==joinWords(base,n2);

}
}
string joinWords(string str, int k){
    string ans="";
    for(int i=0;i<k;i++){
        ans+=str;
    }
    return ans;
}

    string gcdOfStrings(string str1, string str2) {

// brute force : 
// start with assuming the gcd base with minimum size of either str1 or str2 
// and minimum size of the gdc base could be 1 and max will be min size of str1 or str2 
for(int i=min(str1.length(),str2.length()); i>=1; i--){
    // check whether the current length of the min size string is a valid gcd string or not 
    if(valid(str1,str2,i)){
        return str1.substr(0,i);
    }
}
return "";

        // if 2 numbers have gcd string then for sure if we concat both the strings in either way will give the same final string 
        // if(str1+str2 !=  str2+str1) return "";

        // int gcdBase= gcd(str1.length(),str2.length());
        // return str1.substr(0,gcdBase);
    }
};