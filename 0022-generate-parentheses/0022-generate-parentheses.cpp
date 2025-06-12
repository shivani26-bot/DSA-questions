class Solution {
public:
// vector<string>result;
//o(2*n) to check the validity
// bool isValid(string s){
//     // stack<char>st;

//     // for(int i=0;i<s.length();i++){
//     //     if(!st.empty() && s[i]==')' && st.top()=='(') st.pop();
//     //           else st.push(s[i]);

//     // }
//     // return st.empty();

//     int count=0;
//     for(auto it: s){
//         if(it=='(') count++;
//         else count--;
//         if(count<0) return false;
//     }
//     return count==0;
// }
// // every index has 2 options  total possibilities 2^2n where 2n is the length of s
// //o(2^2n)
// void solve(string s, int n){
// if(s.length()==2*n){
//     if(isValid(s)) result.push_back(s);
//     return;
// }
//     s.push_back('(');
//     solve(s, n);
//     s.pop_back();
//     s.push_back(')');
//     solve(s,n);
//     s.pop_back();
// }
//     vector<string> generateParenthesis(int n) {
//         // initially we have "" empty  string, we need to make string of size 2*n
//         // for every index in the string we have 2 options ie. '(' or')'
//     // n=2, ie total length will be 4
// //                                                                    ""
// //                          "("                                                                                      ")"
// //              "(("                                          "()"
// //        "((("              "(()"                  "()("                 "())"  
// //    "(((("   "((()"  "(()("     "(())"        "()()"    "()(("   "())("      "())("
   
//    solve("",n);
//    return result;
//     }
    //total time: o(2^2n * 2n)
    // space: recursion tree depth o(2n)



    // approach 2: n==2 means 2 open and 2 close 
    // hence the case '((()' this is invalid, 
    // if open> n invalid, 
//  ' ( ) ) )' close<open invalid
    //    i at this point we have 1 open and 2 close this is invalid
    // ')()(' open=0, close=0
    //  i at this point, close=1 and open=0, invalid
    // for valid cases , open >close then only put ')' and open<n then only put '('
    //   in this way invalid paranthesis will not be formed 
    // time complexity will be reduced with safety check , every time we will get the valid ans
    // valid paranthesis is equal to catalan number 
vector<string>result;
void solve(string& s, int open, int close, int n){
if(s.length()==2*n) {
    result.push_back(s);
    return ;
}
    if(open<n){
        s.push_back('(');
        solve(s,open+1, close, n);
        s.pop_back();
    }

    if(close<open){
     s.push_back(')');
     solve(s,open, close+1,n);
     s.pop_back();
    }
}
        vector<string> generateParenthesis(int n) {
   int open=0, close=0;
   string s="";
   solve(s,open, close, n);
   return result;
    }
};