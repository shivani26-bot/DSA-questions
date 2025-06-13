class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        st.push(n-1);
        vector<int>ans(n,0);
    
        for(int i=n-2;i>=0;i--){

while(!st.empty() && temperatures[st.top()]<=temperatures[i]) 
{
    st.pop();
}
//temperatures[st.top()]>temperatures[i]
if(!st.empty() ){
  ans[i]=st.top()-i;
}


            st.push(i);
        }
        return ans;
    }
};