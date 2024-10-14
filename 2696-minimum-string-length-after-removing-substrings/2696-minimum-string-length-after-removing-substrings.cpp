class Solution {
public:
// time complexity: o(n)
    int minLength(string s) {
        int n=s.length();
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
         
           if(!st.empty()){
            int topEl=st.top();
            if(s[i]=='B' && topEl=='A'){
                 st.pop();
                
            }
            else if(s[i]=='D' && topEl=='C'){
                st.pop();
              
            }
            else st.push(s[i]);
     
           }
           else st.push(s[i]);
        }
        return st.size();
    }
};