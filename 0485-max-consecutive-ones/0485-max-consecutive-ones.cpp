class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // int i=0,j=0;
        // int n=nums.size();
        // int count=0;
        // while(j<n){
        //     if(nums[j] == 0){
                
        //         j++;
        //         i=j;
        //     }
        //     else if(nums[j] !=0){
        //         count= max(count, j-i+1);
        //         j++;
        //     }
        // }
        // return count;
int maxCount=0;
int count=0;
        for(int num:nums){
            if(num ==1){
                count++;
            }else {
                count=0;
            }
            maxCount= max(maxCount, count);
        }
        return maxCount;
    }
};