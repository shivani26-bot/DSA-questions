class Solution {
public:
bool matchesPattern(string& num, string &pattern){
    int n=pattern.size();
    for(int i=0;i<n;i++){
        if(pattern[i]=='I' && num[i]>=num[i+1]) return false;
        else if(pattern[i]=='D' && num[i]<num[i+1]) return false;
    }
    return true;
}
    string smallestNumber(string pattern) {
//         Input: pattern = "IIIDIDDD"
// Output: "123549876" (lexicographically smallest)
// other possible answers are 245639871,135749862
// brute force: create all lexicographically smallest permutations, check if it follows the  pattern 
// c++ utility: next_permutation() : ensures that permutation is generated lexicographically
// if pattern length is n, then result lenght will be n+1
// permutation of n+1 digits (n+1)!*o(n), for every permutation check if its the valid answer or not 
// sc=o(n)
int n=pattern.length();//n=3
string num="";
for(int i=1;i<=n+1;i++){
    num.push_back(i+'0');//convert integer to char
}
//num="1234"
while(!matchesPattern(num,pattern)){
    next_permutation(begin(num),end(num));
}
return num;

    }
};