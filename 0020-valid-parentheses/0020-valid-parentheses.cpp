class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ch:s){
            if(!st.empty() && ch==')' && st.top()=='(') st.pop();
                else if(!st.empty() && ch==']' && st.top()=='[') st.pop();
                else if(!st.empty() && ch=='}' && st.top()=='{') st.pop();
            else{

                st.push(ch);
               
            }
        }
        return st.empty();
    }
};