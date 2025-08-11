class Solution {
public:
void solve(vector<int>& nums,int idx, vector<vector<int>>&result,vector<int>temp){

result.push_back(temp);
for(int i=idx;i<nums.size();i++){
    if(i>idx && nums[i]==nums[i-1]) continue;
    temp.push_back(nums[i]);
    solve(nums,i+1,result,temp);
    temp.pop_back();
}

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
    sort(nums.begin(),nums.end());
        solve(nums,0,result,vector<int>());
     return result;
    }
};