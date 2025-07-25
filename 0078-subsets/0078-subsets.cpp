class Solution {
public:
int n;
 vector<vector<int>>ans;
void solve(int i,vector<int>subset,vector<int>& nums){
if(i>=n){
    ans.push_back(subset);
    return;
}
subset.push_back(nums[i]);
solve(i+1, subset, nums);
subset.pop_back();
solve(i+1,subset,nums);


}
    vector<vector<int>> subsets(vector<int>& nums) {
         n=nums.size();
        solve(0,{},nums);
        return ans;
    }
};