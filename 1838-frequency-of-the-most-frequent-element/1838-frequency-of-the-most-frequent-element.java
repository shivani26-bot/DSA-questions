class Solution {
    public int maxFrequency(int[] nums, int k) {
        int n=nums.length;
        int i=0,j=0;

        Arrays.sort(nums);
        long currSum=0;
        int maxWindow=0;
        while(j<n){
            currSum+=nums[j];

            // nums[j] always holds the largest element in the window 
            while((long)nums[j]*(j-i+1) - currSum >k){
                currSum-=nums[i];
                i++;
            }


            maxWindow= Math.max(maxWindow, j-i+1);
            j++;
        }

        return maxWindow;
        
    }
}