class Solution {
public:
void solve(vector<int>& candidates, int target, int idx, vector<vector<int>>&result,vector<int>temp){
if(target<0) return;
if(target==0){
    result.push_back(temp);
    return;
}

    for(int i=idx;i<candidates.size();i++){
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i,result,temp);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        solve(candidates,target, 0,result,vector<int>());
        return result;
    }
};