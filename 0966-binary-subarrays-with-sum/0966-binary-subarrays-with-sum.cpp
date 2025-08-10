class Solution {
public:
int atMost(vector<int>& nums, int goal){
     int n=nums.size();
       int i=0,j=0;
       int count=0;//count all the subarray with sum =goal
       int sum=0;
       if(goal<0) return 0;
       while(j<n){
        sum+=nums[j];
        while(sum>goal){
            
            sum-=nums[i];
            i++;
        }

        //subarray ending at j
        count+=(j-i+1);
        j++;
       } 
       return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
  return atMost(nums,goal)-atMost(nums,goal-1);
    }
};