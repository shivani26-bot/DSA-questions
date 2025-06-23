class Solution {
public:
    string reverseParentheses(string s) {
       stack<int>st;

       int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push(i);
        if(s[i]==')'){
            int x=st.top();
            st.pop();
            reverse(s.begin()+x,s.begin()+i);
        }
    }
    string result="";
    for(int i=0;i<n;i++){
        if(s[i]==')'|| s[i]=='(') continue;
        else result+=s[i];
    }
    return result;
    }
};