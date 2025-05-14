class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
    }
};

// move zeros to the end, maintain two pointers i=0, j=0, move i and j such that i always point to 0 and j to a  nonzero element