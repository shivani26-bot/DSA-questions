class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n=nums.length;
        int i=0,j=0;
        int ans=0;
        int countOdd=0;
        int countSubArray=0;
        while(j<n){

            if(nums[j]%2==1) {countOdd++; ans=0;}

            while(countOdd==k){
                ans++;
                if(nums[i]%2==1) countOdd--;
                i++;
            }
            countSubArray+=ans;

            j++;
        }
        return countSubArray;
        
    }
}