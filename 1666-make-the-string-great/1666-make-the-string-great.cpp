class Solution {
public:
    string makeGood(string s) {
    //    stack<char>st;
    //    st.push(s[0]);
    //    for(int i=1;i<s.length();i++){
     
    //        if(!st.empty() && (st.top()-s[i]==32 || st.top()-s[i]==-32)) st.pop();
    //        else st.push(s[i]);
    //    } 
    // //    if(st.empty()) return "";
    //    string result="";
    // //    while(!st.empty()){
    // //        result.push_back(st.top());
    // //        st.pop();
    // //    }
    // //    reverse(result.begin(),result.end());
    // //    return result;
    //    while(!st.empty()){
    //        result=st.top()+result;
    //        st.pop();
    //    }
      
    //    return result;

    stack<char>st;
    st.push(s[0]);
int n=s.length();
    for(int i=1;i<n;i++){
          if(!st.empty() && (st.top()-s[i]==32 || st.top()-s[i]==-32))
               st.pop();
        else st.push(s[i]);
    }

    string result="";
    while(!st.empty()){
        result= st.top()+result;
        st.pop();
    }

    return result;
    
    }
};

// input: "Pp"
// output: ""