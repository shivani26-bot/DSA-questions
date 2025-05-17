class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        string str1,str2;
        for(auto word:word1){
            str1+=word;
        }
        for(auto word:word2){
            str2+=word;
        }
        return str1==str2;
        
    }
};