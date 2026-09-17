class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        //    boolean ans= false;
        // Map<Integer,Integer> mp = new HashMap<>();
        // for(int i=0;i<nums.length;i++){
        //     int num= nums[i];
        //     if(mp.containsKey(num) && i-mp.get(num)>k) ans=false;
        //     if(mp.containsKey(num) && i-mp.get(num)<=k) return true;
        //     mp.put(num, i);
        // }
        // return ans;

                   Map<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<nums.length;i++){
        

            int num= nums[i];
            if(mp.containsKey(num)){
                int dist= i-mp.get(num);
                if(dist<=k) return true;
            }
            mp.put(num, i);
        }

        return false;
    }
}