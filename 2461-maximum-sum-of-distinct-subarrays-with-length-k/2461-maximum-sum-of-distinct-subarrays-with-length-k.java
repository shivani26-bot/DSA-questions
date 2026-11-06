class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        Map<Integer,Integer>mp = new HashMap<>();

        int i=0,j=0;
        int n=nums.length;
        long sum=0;
        long maxSum=0;

        while(j<n){
            
            sum+=nums[j];
            mp.put(nums[j], mp.getOrDefault(nums[j],0)+1);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(mp.size()==k){
                    maxSum= Math.max(maxSum, sum);
                }
                mp.put(nums[i],mp.get(nums[i])-1);
                if(mp.get(nums[i])==0) mp.remove(nums[i]);
                
                sum-=nums[i];
                i++;
                j++;


            }

        }
        return maxSum;

    }
}