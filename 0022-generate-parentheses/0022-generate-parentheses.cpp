class Solution {
public:
vector<string>result;
//o(2*n) to check the validity
bool isValid(string s){
    // stack<char>st;

    // for(int i=0;i<s.length();i++){
    //     if(!st.empty() && s[i]==')' && st.top()=='(') st.pop();
    //           else st.push(s[i]);

    // }
    // return st.empty();

    int count=0;
    for(auto it: s){
        if(it=='(') count++;
        else count--;
        if(count<0) return false;
    }
    return count==0;
}
// every index has 2 options  total possibilities 2^2n where 2n is the length of s
//o(2^2n)
void solve(string s, int n){
if(s.length()==2*n){
    if(isValid(s)) result.push_back(s);
    return;
}

    s.push_back('(');
    solve(s, n);
    s.pop_back();
    s.push_back(')');
    solve(s,n);
    s.pop_back();

}
    vector<string> generateParenthesis(int n) {
        // initially we have "" empty  string, we need to make string of size 2*n
        // for every index in the string we have 2 options ie. '(' or')'
    // n=2, ie total length will be 4
//                                                                    ""
//                          "("                                                                                      ")"
//              "(("                                          "()"
//        "((("              "(()"                  "()("                 "())"  
//    "(((("   "((()"  "(()("     "(())"        "()()"    "()(("   "())("      "())("
   
   solve("",n);
   return result;
    }
    //total time: o(2^2n * 2n)
    // space: recursion tree depth o(2n)
};