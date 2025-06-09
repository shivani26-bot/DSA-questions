class Solution {
public:
    int minLength(string s) {
//         int n=s.length();
//         string result="";
// for(int i=0;i<n-1;){
//     cout<<i<<endl;
//     if((s[i]=='A' && s[i+1]=='B')|| (s[i]=='C' && s[i+1]=='D')){
//          i=i+2;
//          continue;
//            }
//            else{
//            result+=s[i];
//  result+=s[i+1];
//  i+=2;
//            }
//            cout<<result<<endl;
//     }
// return result.length();


//In C++, st.top() + s[i] adds the ASCII values of the two characters, not concatenates them into a string.

// So:

// 'A' + 'B' is actually 65 + 66 = 131, not "AB"

// Comparing it with "AB" (const char*) is meaningless and leads to incorrect logic


int n=s.length();

stack<char>st;
st.push(s[0]);
for(int i=1;i<n;i++){
    if(!st.empty()){
    string combo="";
    combo+=st.top();
    combo+=s[i];
   if (combo=="AB" || combo=="CD")
         { 
            st.pop();
            continue;
            }
        
}
st.push(s[i]);
}
return st.size();
    }
};


