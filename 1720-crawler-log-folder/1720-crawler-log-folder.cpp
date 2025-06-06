class Solution {
public:
    int minOperations(vector<string>& logs) {
        // int depth=0;
        // for(int i=0;i<logs.size();i++){
        //     string temp=logs[i];
        //     // if(temp[0]=='d') depth++;
        //      if (temp.substr(0,2)=="..") {
        //         if(depth>0)
        //         depth--;
        //         }
        
        //         else if(temp[0]=='.') continue;
        //         else{
        //             depth++;
        //         }
        // }
        // return depth;

        int n=logs.size();
        stack<string>st;
        for(int i=0;i<n;i++){
            string temp=logs[i];
            if(temp.substr(0,2)==".."){
                     if(!st.empty()) st.pop(); 
            }
            else if(temp[0]=='.') continue;
            else{
              st.push(temp);
            }
        }
        return st.size();
    }
};