class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
stack<int>st;
int i=0,j=0;
       while(i<n){
           if(!st.empty() && popped[j]==st.top()){
            st.pop();
            j++;
           }
else{
        st.push(pushed[i]);
i++;
}
        }
        while(j<n){
               if(!st.empty() && popped[j]==st.top()){
            st.pop();
            j++;
           }
           else break;
        }
        return st.empty();
    }
};