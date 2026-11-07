class Solution {
    public int longestOnes(int[] nums, int k) {
        int i=0,j=0 , n=nums.length;
        int countOne=0;
        int maxWin=0;

        while(j<n){
            if(nums[j]==1) countOne++;
            while(Math.abs(j-i+1) - countOne >k){
                if(nums[i]==1) countOne--;
                i++;

            }
            maxWin= Math.max(maxWin, j-i+1);
            j++;
           
        }
         return maxWin;

    }
}