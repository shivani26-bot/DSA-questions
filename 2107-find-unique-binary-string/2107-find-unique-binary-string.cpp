class Solution {
public:
int n;
string solve(set<string>&st, string temp){
if(temp.length()==n){
    if(st.count(temp)) return "";
    return temp;
}

for(char ch='0';ch<='1';ch++){
    temp.push_back(ch);
    string res=solve(st,temp);
    if(!res.empty()) return res;
    temp.pop_back();
}
return "";
}
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st;
        n=nums.size();
        for(string& s:nums){
            st.insert(s);
        }
return solve(st,"");
    }
};