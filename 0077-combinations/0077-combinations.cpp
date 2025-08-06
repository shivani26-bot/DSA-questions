class Solution {
public:
void solve(vector<vector<int>>&result,int idx,int n , int k, vector<int>temp){
    if(temp.size()==k){
        result.push_back(temp);
        return;
    }
    for(int i=idx;i<n;i++){
        temp.push_back(i+1);
        solve(result,i+1,n,k,temp);
        temp.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        solve(result,0,n,k,vector<int>());
        return result;
    }
};