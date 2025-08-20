class Solution {
public:
int n;
int solve( int idx,string &s, set<string>st){
if(idx>=n) return st.size();
int maxi=INT_MIN;
    for(int j=idx;j<n;j++){
        string substr=s.substr(idx,j-idx+1);
        if(st.find(substr)==st.end()){
            st.insert(substr);
            maxi=max(maxi,solve(j+1,s,st));
            st.erase(substr);
        }
    }
    return maxi;
}
    int maxUniqueSplit(string s) {
        n=s.length();
        set<string>st;
       return solve(0,s,st);
    }
};