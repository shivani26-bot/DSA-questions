class Solution {
public:
    string removeStars(string s) {
        //gives memory limit exceeded
//         stack<char>st;
//         int n=s.length();
//         for(int i=0;i<n;i++){
//              if(!st.empty() && s[i]=='*') st.pop();
//              else st.push(s[i]);
//         }

// string result="";
//         while(!st.empty()){
//             result=st.top()+result;
//             st.pop();
//         }
//         return result;

//  int n=s.length();
//  for(int i=0;i<n;i++){
//     if(s[i]=='*'){
//         s.erase(s.begin()+i);
//         s.erase(s.begin()+(i-1));
//         i-=2;
//     }

//  }
//  return s;

string ans="";
for(auto it: s){
    if(it=='*') ans.pop_back();
    else ans.push_back(it);
}
return ans;
    }
};