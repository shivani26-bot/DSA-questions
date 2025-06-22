class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.empty()) return "";
        // remove k consecutive duplicate elements 
        stack<pair<char,int>>st;
st.push({s[0],1});
        for(int i=1;i<s.length();i++){

if(!st.empty() && st.top().first==s[i]){
    int count=st.top().second;
if(count+1==k){
    while(!st.empty() && count>0){
        st.pop();
        count--;
    }
 
}
else{
    // count+1<k
    st.push({s[i],count+1});
}
}
// else if(count<k && ch==s[i])
//             st.push({s[i],count+1});
            else {
                //if st.top().first!=s[i]
                st.push({s[i],1});
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};