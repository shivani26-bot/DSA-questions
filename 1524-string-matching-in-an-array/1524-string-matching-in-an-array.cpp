class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
       vector<string>ans;
       int n=words.size();
       for(int i=0;i<n;i++){
        string str1=words[i];
        for(int j=0;j<n;j++){
            string str2=words[j];
                if(j!=i){
 if (str2.find(str1) != string::npos) {
        ans.push_back(str1);
        break;
    }
                }
        }
       } 
       return ans;
    }
};