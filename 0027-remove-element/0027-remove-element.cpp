class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
     
      nums.erase(remove(nums.begin(), nums.end(), val), nums.end());

        return nums.size();
    //      int i = 0;
    // while (i < nums.size()) {
    //     if (nums[i] == val) {
    //         nums.erase(nums.begin() + i);
    //     } else {
    //         i++;
    //     }
    // }
    // return nums.size();
    int k=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            // nums[k]=nums[i];
            k++;
        }
        return k;
    }
    }
};