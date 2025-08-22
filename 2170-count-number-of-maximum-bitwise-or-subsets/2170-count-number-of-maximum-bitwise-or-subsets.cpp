class Solution {
public:
int n;
int solve(vector<int>&nums, int idx,int currOr,int targetOr){
if(idx==n){
    return currOr==targetOr?1:0;
}

int take=solve(nums,idx+1,currOr|nums[idx],targetOr);
int notTake=solve(nums,idx+1,currOr, targetOr);
return take+notTake;
}
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int maxOr=0;
        for(int num:nums){
            maxOr|=num;
        }
        return solve(nums,0,0,maxOr);
    }
};