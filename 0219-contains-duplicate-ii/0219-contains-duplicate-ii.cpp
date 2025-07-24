class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
int n=nums.size();
        int i=0,j=0;
        while(j<n){
        if(i<j && nums[i]==nums[j]) return true;
            if(j-i<k) j++;
            else{
                i++;
        //   j++;
            }
        }
        return false;
    }
};