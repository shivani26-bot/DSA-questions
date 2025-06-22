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
// int endIndex=0;
// for(int i=ans.size()-1; i>=0; i--){
//     if(ans[i]!= '0'){
//         endIndex=i;
//         break;
//     }
// }

// ans=ans.substr(0, endIndex+1);
// reverse(ans.begin(),ans.end());
// if(ans == "") ans="0";
// return ans;
reverse(ans.begin(),ans.end());
int startIndex;
for(int i=0; i<ans.size(); i++){
    if(ans[i]!= '0'){
        startIndex=i;
        break;
    }
}

ans=ans.substr(startIndex);

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


// ❌ ans = st.top() + ans → O(n²) → MLE
// ✅ Use ans += st.top() + reverse() → O(n) time + better memory efficiency

// while (!st.empty()) {
//     ans = st.top() + ans; // prepending at the beginning
//     st.pop();
// }
// Step-by-step:
// Again, suppose stack contents: 1 2 1 9

// Iteration 1: ans = "9"

// Iteration 2: ans = "1" + "9" = "19"

// Iteration 3: ans = "1" + "19" = "119"

// Iteration 4: ans = "2" + "119" = "2119"

// At each step, a new string is created:

// Step 1: 1 character copied

// Step 2: 2 characters copied

// Step 3: 3 characters copied

// Step 4: 4 characters copied

// \U0001f9e0 Memory: Each step copies all previous characters, costing O(1 + 2 + 3 + ... + n) = O(n²)
// \U0001f501 Time: Also O(n²)
// \U0001f4a5 If num has 10⁵ digits, this approach creates many temporary strings, quickly exhausting memory → MLE