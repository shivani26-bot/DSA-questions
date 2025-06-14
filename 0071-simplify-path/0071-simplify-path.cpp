class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();

        stack<string>st;

        for(int i=1;i<n;i++){
            if(path[i]=='/') continue;
            string temp="";
            while(i<n && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp==".") continue;
            else if(temp==".."){
                if(!st.empty())
                st.pop();
               
            }
            else
            st.push(temp);
        }
        string result="";
        while(!st.empty()){
       result="/"+st.top()+result;
       st.pop();
        }
        if(result.length()==0) return "/";
        return result;

    }

};