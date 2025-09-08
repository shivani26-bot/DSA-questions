class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we can use binary search 
        int n=nums.size();
        int low=1;
        int high=n;
        while(low<=high){
            int mid=(low+high)/2;
            int countEle=0;
            for(auto it:nums){
                if(it<=mid) countEle++;

            }
            if(countEle<=mid) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};