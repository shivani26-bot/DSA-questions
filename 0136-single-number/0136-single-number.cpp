class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xoor=nums[0];
        for(int i=1;i<nums.size();i++){
            xoor^=nums[i];
        }

        return xoor;
    }
};