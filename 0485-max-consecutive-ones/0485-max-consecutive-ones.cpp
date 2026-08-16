class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        int count=0;
        while(j<n){
            if(nums[j] == 0){
                
                j++;
                i=j;
            }
            else if(nums[j] !=0){
                count= max(count, j-i+1);
                j++;
            }
        }
        return count;
    }
};