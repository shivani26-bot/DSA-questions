class Solution {
public:
const int MOD=1000000007;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        vector<int>powerOf2(n,1);
for(int i=1;i<n;i++){
    powerOf2[i]= (powerOf2[i-1]*2)%MOD;
}
int l=0, r= upper_bound(nums.begin(),nums.end(),target-nums[0])-nums.begin()-1;

while(l<=r){
    if(nums[l]+nums[r]<=target){
        ans+=powerOf2[r-l];
        ans%=MOD;
        l++;
    }
    else{
        r--;
    }
}
return ans;
    }
};