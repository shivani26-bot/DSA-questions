class Solution {
    public int minimumDifference(int[] nums, int k) {
        int i=0,j=0;
        int n=nums.length;
        int minDifference= Integer.MAX_VALUE;
        Arrays.sort(nums);

        while(j<n){

            if(j-i+1<k) j++;
            else if(j-i+1==k){
                int diff= nums[j] - nums[i];
                minDifference= Math.min(minDifference, diff);
         
                i++;
                j++;
            }
        }

        return minDifference;
    }
}