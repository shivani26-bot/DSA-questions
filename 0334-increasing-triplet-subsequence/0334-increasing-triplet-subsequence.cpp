class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // o(n^3)
        //       int n=nums.size();
        // if(n<3) return false;
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         if(nums[j]>nums[i]){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[j]<nums[k]) return true;
        //         }
        //         }
        //     }
        // }
        // return false;

        int first=INT_MAX;
        int second=INT_MAX;
        for(int num: nums){
            if(num<=first) first=num;
            else if(num<=second) second=num;
            else return true; //found the greater element than first and second
        }
        return false;
    }
};