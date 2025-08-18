class Solution {
public:
void phonepad(string temp, string& digits, int i, vector<vector<string>>& digitMap,vector<string>&result) {
    // cout<<i<<endl;
    // if (i == digits.length()) {
        if(digits[i]==NULL){
  result.push_back(temp);
        return;
    }
 for (int j = 0; j < digitMap[digits[i] - '2'].size(); j++) {
  phonepad(temp + digitMap[digits[i] - '2'][j], digits, i + 1, digitMap,result);

 }
}
    vector<string> letterCombinations(string digits) {
        vector<string>result;
         vector<vector<string>> digitMap;
    digitMap.push_back({"a", "b", "c"});
    digitMap.push_back({"d", "e", "f"});
    digitMap.push_back({"g", "h", "i"});
    digitMap.push_back({"j", "k", "l"});
    digitMap.push_back({"m", "n", "o"});
    digitMap.push_back({"p", "q", "r", "s"});
    digitMap.push_back({"t", "u", "v"});
    digitMap.push_back({"w", "x", "y", "z"});

    if (digits.length() == 0) {
        return {};
    }
    phonepad("", digits, 0, digitMap,result);
    return result;
}
    
};