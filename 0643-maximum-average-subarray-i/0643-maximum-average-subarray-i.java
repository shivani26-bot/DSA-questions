class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int i=0,j=0, n=nums.length;
        double maxAvg= Integer.MIN_VALUE;
        int sum=0;

        while(j<n){
            sum+=nums[j];
            if(j-i+1<k) j++;
            else if(j-i+1 == k){
                double average= sum/(k*1.0);
                maxAvg= Math.max(average, maxAvg);
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return maxAvg;

    }
}