class Solution {
public:
int n;
void solve(vector<int>& nums,set<vector<int>>&result,int idx){
if(idx==n){
    result.insert(nums);
    return;
}

    for(int j=idx;j<n;j++){
       
        swap(nums[idx],nums[j]);
        solve(nums,result,idx+1);
        swap(nums[idx],nums[j]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         n=nums.size();
        set<vector<int>>result;
        solve(nums,result,0);
        vector<vector<int>>ans(result.begin(),result.end());
        return ans;
    }
};