class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer>mp= new HashMap<>();
        int i=0, j=0;
        int n=fruits.length;
        int maxFruit=0;

        while(j<n){
            int rightNum=fruits[j];
            // mp.put(rightNum, mp.getOrDefault(rightNum,0)+1);
            mp.merge(rightNum, 1, Integer::sum);
       
            while(mp.size()>2){
                int leftNum=fruits[i];
                // mp.put(leftNum, mp.get(leftNum)-1);
                mp.merge(leftNum, -1, Integer::sum);
                if(mp.get(leftNum)==0) mp.remove(leftNum);
                i++;
            }


            maxFruit= Math.max(maxFruit, j-i+1);
            j++;
        }

        return maxFruit;
        
    }
}