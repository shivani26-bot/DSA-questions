class Solution {
    public int subarraySum(int[] nums, int k) {
Map<Integer,Integer>mp= new HashMap<>();

mp.put(0,1);
int prefixSum=0;
int count=0;
for(int num: nums){
    prefixSum+=num;
    count+=mp.getOrDefault(prefixSum-k,0);
    mp.put(prefixSum, mp.getOrDefault(prefixSum, 0)+1);
}
return count;
    }
}