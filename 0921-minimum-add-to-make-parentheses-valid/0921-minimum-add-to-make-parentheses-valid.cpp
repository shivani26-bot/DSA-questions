class Solution {
public:
    //o(n)
    int minAddToMakeValid(string s) {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
        if(!st.empty() && s[i]==')' && st.top()=='(') {
               st.pop();
                continue;
           }
         st.push(s[i]);
        }
        return st.size();
    }
};