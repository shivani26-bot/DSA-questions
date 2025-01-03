class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>preCount(n+1,0);
        unordered_set<char>st{'a','e','i','o','u'};
        
        // st.insert('a');
        // st.insert('e');
        // st.insert('i');
        // st.insert('o');
        // st.insert('u');
        for(int i=0;i<n;i++){
            int n=words[i].length();
            char firstChar=words[i][0];
            char lastChar=words[i][n-1]; 
            if(st.find(firstChar)!=st.end() && st.find(lastChar)!=st.end()){
                preCount[i+1]=1+preCount[i];

            }
            else preCount[i+1]=preCount[i];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int start_index=queries[i][0];
            int last_index=queries[i][1];
            int count= preCount[last_index+1]-preCount[start_index];
          ans.push_back(count);
        }
        return ans;
    }
};