class Solution {
public:
int n;
void solve(vector<int>& nums,vector<vector<int>>&result,int idx){
if(idx==n){
    result.push_back(nums);
    return;
}

    for(int j=idx;j<n;j++){
        swap(nums[idx],nums[j]);
        solve(nums,result,idx+1);
        swap(nums[idx],nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>result;
        solve(nums,result,0);
        return result;
    }
};