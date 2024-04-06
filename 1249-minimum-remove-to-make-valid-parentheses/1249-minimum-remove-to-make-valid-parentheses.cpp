class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n=s.size();
   vector<bool>indicesToRemove(n,1);
        for(int i=0;i<n;i++){
            // if(s[i]>='a' && s[i]<='z') continue;
            if(s[i]=='(')  st.push(i);
            else if(s[i]==')') {
                 if(!st.empty() && s[st.top()] == '(') st.pop();
                 else 
                indicesToRemove[i]=0;
            }
        }
        

        while(!st.empty()){
            indicesToRemove[st.top()]=0;
            st.pop();
        }

        // string ans="";
          string ans;
       for (int i =0; i< n; i++) {
        if(indicesToRemove[i]==1) 
        // ans.push_back(s[i]);
        ans+=s[i];
    }

    return ans;
    }
};