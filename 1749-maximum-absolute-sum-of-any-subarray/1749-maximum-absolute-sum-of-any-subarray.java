class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int n=nums.length;
        int currMax=0, maxSofar=0;
         int currMin=0, minSofar=0;

        for(int i=0;i<n;i++){
             currMax= Math.max(nums[i], currMax+nums[i]);
            maxSofar= Math.max(maxSofar, currMax);

            currMin= Math.min(nums[i], currMin+nums[i]);
            minSofar= Math.min(minSofar, currMin);
        }

        return Math.max(maxSofar, Math.abs(minSofar));
        
    }
}