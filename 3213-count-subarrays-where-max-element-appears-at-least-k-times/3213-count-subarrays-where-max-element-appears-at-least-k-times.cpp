class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int maxEle= *max_element(nums.begin(),nums.end());
        long long int n=nums.size();
        long long int i=0,j=0;
        long long int count=0;
        long long int countSubarray=0;
        while(j<n){
            if(nums[j]==maxEle) count++;
            while(count>=k){
                countSubarray+=(n-j);
                if(nums[i]==maxEle) count--;
                i++;
            }
            j++;
        }
    return countSubarray;
    }
};