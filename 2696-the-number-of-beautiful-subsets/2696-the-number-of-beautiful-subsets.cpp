class Solution {
public:
int n;

vector<vector<int>>result;
int solve(vector<int>& nums, int k,  int idx, int prev){

if(idx==n) return 0;
int pick=0;
int notPick= solve(nums,k,idx+1,prev);
if(prev==-1 || abs(nums[idx]-nums[prev])!=k)
pick=1+solve(nums,k,idx+1,idx);
return pick+notPick;
}
    int beautifulSubsets(vector<int>& nums, int k) {
      n=nums.size();
      sort(nums.begin(),nums.end());
      return solve(nums,k,0,-1); 
    }
};