class Solution {
public:
    int minimumDeletions(string s) {
           stack<char>st;
           int count=0;
           for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                st.push('b');
            }
            else{
if(!st.empty() && st.top()=='b'){
    count++;
    st.pop();
}
            }
           }
           return count;
        }
};