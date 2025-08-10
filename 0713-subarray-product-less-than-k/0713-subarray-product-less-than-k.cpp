class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         int i=0,j=0;
        int n=nums.size();
        int product=1;
        int countSubArray=0;
        if(k<=1) return 0;
        while(j<n){
            product*=nums[j];
            while(product>=k){
      
                product/=nums[i];
                i++;
            }
            countSubArray+=(j-i+1);
            j++;

        }
        return countSubArray;
    }
};