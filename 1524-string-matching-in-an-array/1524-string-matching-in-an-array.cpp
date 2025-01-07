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
                    //searches for str2 in str1.
//                     If str1 is found, it returns the starting index of str1 in str2.
// If str1 is not found, it returns std::string::npos.
// std::string::npos is a constant defined in the std::string class in C++ that represents a value indicating "no position." It is used to signal that a substring or character was not found in a string operation.
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