class Solution {
public:
    string clearDigits(string s) {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && isdigit(s[i])){
                st.pop();
            }
            else st.push(s[i]);
        }
        string result="";
        while(!st.empty()){
           result=st.top()+result;
           st.pop();
        }
        return result;
    }
};