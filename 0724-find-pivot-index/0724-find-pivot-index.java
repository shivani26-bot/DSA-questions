class Solution {
    public int pivotIndex(int[] nums) {
        // int n=nums.length;
        // int[] prefixSum = new int[n];
        // int[] suffixSum= new int[n];
        // prefixSum[0]=nums[0];
        // suffixSum[n-1]=nums[n-1];

        // for(int i=1;i<n;i++){
        //     prefixSum[i]= nums[i]+prefixSum[i-1];
        // }
        //  for(int i=n-2;i>=0;i--){
        //     suffixSum[i] = nums[i]+suffixSum[i+1];
        // }

        // for(int i=0;i<n;i++){
        //     if(suffixSum[i]==prefixSum[i]) return i;
        // }

        // return -1;

        int n=nums.length;
        int totalSum=0;

        for(int num: nums){
            totalSum+=num;
        }

        int leftSum=0;

        for(int i=0;i<n;i++){
            int rightSum=totalSum-leftSum-nums[i];
            if(leftSum==rightSum){
                return i;
            }
            leftSum+=nums[i];
        }

        return -1;
        
    }
}