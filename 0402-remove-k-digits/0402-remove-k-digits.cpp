class Solution {
public:
    string removeKdigits(string num, int k) {
       int n=num.size();
       stack<char>st;
      for(auto c: num){
        while(!st.empty() && st.top()>c && k>0){
            st.pop();
            k--;
        }
            st.push(c);
      }
      while(k>0){
        st.pop();
        k--;
      }  
      
      string ans="";
      while(!st.empty()){
        ans += st.top();
        st.pop();
      }
int endIndex=0;
for(int i=ans.size()-1; i>=0; i--){
    if(ans[i]!= '0'){
        endIndex=i;
        break;
    }
}

ans=ans.substr(0, endIndex+1);
reverse(ans.begin(),ans.end());
if(ans == "") ans="0";
return ans;
//   string ans="";
//       while(!st.empty()){
    //This is inefficient because strings in C++ are immutable and every time you do ans = st.top() + ans, a new string is created, copying both st.top() and the entire ans each time. If ans has n characters, the copy takes O(n) time and space. Repeating this for all characters in the stack results in O(n²) time and potentially O(n²) memory usage, causing MLE for large inputs.
//         ans = st.top()+ans;
//         st.pop();
//       }
//       cout<<ans;
// int startIndex;
// for(int i=0; i<ans.size(); i++){
//     if(ans[i]!= '0'){
//         startIndex=i;
//         break;
//     }
// }
// cout<<endl;
// cout<<startIndex;

// ans=ans.substr(startIndex);


// if(ans == "") ans="0";
// return ans;


    }
};

// 
❌ ans = st.top() + ans → O(n²) → MLE
// ✅ Use ans += st.top() + reverse() → O(n) time + better memory efficiency