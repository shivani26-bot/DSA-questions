class Solution {
public:
int n;
vector<vector<string>>result;
bool isPalindrome(int i, int j , string& s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}
void solve(int idx, string& s,vector<string>&palindrome){
if(idx==n){
    result.push_back(palindrome);
    return;
}

    for(int i=idx;i<n;i++){
string temp=s.substr(idx,i-idx+1);
        if(isPalindrome(idx,i,s)){
            palindrome.push_back(temp);
            solve(i+1,s,palindrome);
            palindrome.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
      n=s.length();
      vector<string>palindrome;
      solve(0,s,palindrome);  
      return result;
    }
};