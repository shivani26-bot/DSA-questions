class Solution {
public:
    bool canJump(vector<int>& nums) {
  
   int n=nums.size();
   if(n==1) return true;
   int maxReachable=0;
   for(int i=0;i<n;i++){
       if(maxReachable<i) return false;
       maxReachable=max(maxReachable, i+nums[i]);
       if(maxReachable>=(n-1)) return true;
   }
   return false;
    }
};