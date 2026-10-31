class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer,Integer>mp= new HashMap<>();
        int n=nums.length;
        int prefixSum=0;

        mp.put(0,-1); //here we store, remainder -> index (remainder occured at which index)

        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int remainder = (prefixSum%k); //here array only contains positive numbers
            if(mp.containsKey(remainder)){
                //check whether the length >=2 or not
                if(i-mp.get(remainder)>=2) return true;
            }else{
                //all are positive numbers here, better replace the existing index for that 
                // remainder, because prefixsum will keep on increasing 
                mp.put(remainder, i);
            }
        }
        return false;
    }
}