class Solution {
public:

int evaluate(int a, int b, string& token){
    if(token=="+") return b+a;
     if(token=="0") return b-a;
      if(token=="*") return b*a;
       if(token=="/") return b/a;
       return 0;
}

    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="*" ||tokens[i]=="/"||tokens[i]=="+"||tokens[i]=="-" ){
                int a=st.top(); st.pop();
                int b=st.top();st.pop();
                st.push(evaluate(a,b,tokens[i]));
            }
else
            st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};