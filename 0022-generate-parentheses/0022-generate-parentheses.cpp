class Solution {
public:
vector<string>result;
bool isValid(string& s){
    stack<char>st;

    for(int i=0;i<s.length();i++){
        if(!st.empty() && s[i]==')' && st.top()=='(') st.pop();
              else st.push(s[i]);

    }
    return st.empty();
}
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
};