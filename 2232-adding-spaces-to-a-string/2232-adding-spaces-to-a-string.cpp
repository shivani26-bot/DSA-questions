class Solution {
public:
    // o(n+m)
    // string addSpaces(string s, vector<int>& spaces) {
    //     // each insertion takes o(1)
    //     unordered_set<int>st(spaces.begin(),spaces.end());//o(m)
    //     int n=s.length();
    //     int m=spaces.size();
    //     // vector<char>ans(n+m);
    //     string ans;
    //     for(int i=0;i<n;i++){//o(n)
    //         if(st.find(i)!=st.end()){//o(1)
    //             // ans.push_back(' ');
    //             ans+=' ';
    //         }
    //         // ans.push_back(s[i]);
    //         ans+=s[i];
    //     }
    //     return ans;
    // }


// o(n+m)
     string addSpaces(string s, vector<int>& spaces) {
int n=spaces.size(),m=s.length();
//we can also take a string result of size n+m and then perform the same logic
stringstream result;
int j=0;//points to index in spaces array
for(int i=0;i<m;i++){
    // first insert the space and then the character present at s[i]
   if(j<n && spaces[j]==i){
    result<<' ';//insert space in result stream
    j++;

   }
//    insert the character in the string to result stream
result<<s[i];
}
return result.str();
//convert the stream to string;
    }
};