class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // nums = [1,1,2,3,3,4,4,8,8]
                // 0 1 2 3 4 5 6 7 8
        int n=nums.size();
        int l=0, h=n-1;
        if(n==1) return nums[0];
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid%2==0){
                //mid is even;
                if(nums[mid]==nums[mid+1]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            else if(mid%2==1){
                                //mid is odd
                if(nums[mid]==nums[mid-1]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
        }
        return nums[l];
    }
};