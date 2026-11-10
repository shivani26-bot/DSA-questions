class Solution {
    public int maxSubArray(int[] nums) {
        int n=nums.length;
                // int maxSum=Integer.MIN_VALUE;
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        //     maxSum= Math.max(maxSum, sum);
        //       if(sum<0){
        //         sum=0;
        //     }
        // }
        // return maxSum;

        int currentMax=nums[0];
        int maxSoFar=nums[0];
        for(int i=1;i<n;i++){
            currentMax= Math.max(nums[i], currentMax+nums[i]);
            maxSoFar= Math.max(maxSoFar, currentMax);
        }
        return maxSoFar;


    }
}