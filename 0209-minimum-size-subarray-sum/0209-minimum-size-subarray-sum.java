class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int i=0,j=0,n=nums.length;
        int sum=0;
        int minWindow=Integer.MAX_VALUE;
        while(j<n){
            sum+=nums[j];

            if(sum<target) j++;
            else if(sum>=target){
             
                while(sum>=target){
                minWindow= Math.min(minWindow, j-i+1);
                sum-=nums[i];
                i++;
                }
                
                j++;

            }
        }
        return minWindow==Integer.MAX_VALUE ? 0 :minWindow;
    }
}