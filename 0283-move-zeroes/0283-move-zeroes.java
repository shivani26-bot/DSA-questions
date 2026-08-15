class Solution {
    public void moveZeroes(int[] nums) {
                        int i=0,j=0;
        int n=nums.length;
        while(j<n){
         if(nums[j]!=0){
            if(j!=i){
                nums[i]=nums[j];
                nums[j]=0;
            }
            i++;
         }
         j++;
        }
    }
}