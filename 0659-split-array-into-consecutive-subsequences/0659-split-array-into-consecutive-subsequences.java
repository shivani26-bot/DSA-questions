class Solution {
    public boolean isPossible(int[] nums) {
          Map<Integer, Integer> freq = new HashMap<>();
        Map<Integer, Integer> need = new HashMap<>(); //tells how many subsequence need a particular number in their end

        for(int num: nums){
            // freq.put(num, freq.getOrDefault(num, 0) + 1);
            freq.merge(num, 1, Integer::sum);
        }

        for(int num: nums){
            if(freq.get(num) == 0) continue; //that element is exhausted 
            if(need.getOrDefault(num, 0) > 0){
                need.put(num, need.get(num)-1);
                need.put(num+1, need.getOrDefault(num+1, 0 )+1);
                  freq.put(num, freq.get(num)-1);
            }else{
                boolean canStart=true;
                for(int i=0;i<3;i++){
                    if(freq.getOrDefault(num+i,0)<=0){
                        canStart=false;
                        break;
                    }
                }
                if(!canStart) return false;

                for(int i=0;i<3;i++){
                    freq.put(num+i, freq.get(num+i)-1);
                }
                need.put(num+3, need.getOrDefault(num+3,0)+1);

            }
          
        }
        return true;
    }
}