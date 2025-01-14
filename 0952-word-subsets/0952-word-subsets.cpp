class Solution {
public:
bool isSubset(vector<int>& freq, vector<int>& temp){
    for(int i=0;i<26;i++){
        if(temp[i]<freq[i]){
                  return false;
        }
    }
    return true;
}
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       vector<string>ans;
       vector<int>freq(26);
       for(auto word: words2){
            int temp[26]={0};
            for(auto ch: word){
                temp[ch-'a']++;
                freq[ch-'a']=max(freq[ch-'a'],temp[ch-'a']);
            }
       }
       for(auto word: words1){
        vector<int>temp(26,0);
        for(auto ch: word){
            temp[ch-'a']++;
        }
        if(isSubset(freq,temp)==true){
            ans.push_back(word);
        }
       }
       return ans;
//         always store the maximum count of a character
//         words2=['e','o','oo']
//         words1=["amazon","apple","facebook","google","leetcode"]
// map
// e->1
// o->2
     
    }
};