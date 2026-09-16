class Solution {
    public int numIdenticalPairs(int[] nums) {
           Map<Integer, Integer> freq = new HashMap<>();
        for(int num: nums){
            freq.merge(num, 1, Integer::sum);
        }
        int total=0;
        for(Map.Entry<Integer, Integer> entry : freq.entrySet()){
             Integer val = entry.getValue();
             if(val>1){
                total += val*(val-1)/2;
             }
        }
        return total;
    }
}