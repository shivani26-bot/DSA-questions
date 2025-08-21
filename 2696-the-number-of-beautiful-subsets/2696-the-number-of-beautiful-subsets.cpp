class Solution {
public:
int n;

// At every index, we have two choices:
// Skip the number.
// Take the number (but only if it doesn’t break the rules).
// So when we try to include nums[idx], we must check:
// Is nums[idx] - k already in the subset?
// If yes → including nums[idx] would break the rule.
// If no → it’s safe to include.
int res=0;
void solve(vector<int>& nums, int k,int idx, unordered_map<int,int>&mp){
    if(idx>=n) {res++;return;}
    solve(nums,k,idx+1,mp);
    if(!mp[nums[idx]-k] && !mp[nums[idx]+k]){
        mp[nums[idx]]++;
        solve(nums,k,idx+1,mp);
        mp[nums[idx]]--;
    }
}
    int beautifulSubsets(vector<int>& nums, int k) {
      n=nums.size();
    unordered_map<int,int>mp;
     solve(nums,k,0,mp); 
     return res-1;//remove empty subset
    }
};