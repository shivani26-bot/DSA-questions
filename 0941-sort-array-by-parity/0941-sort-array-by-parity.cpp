class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
// i will point to odd and j will point to even 
// as we find the j pointing to even number we will swap the numbers and i++, j++
if(nums[j]%2==0){
    swap(nums[i],nums[j]);
    i++;
}
            j++;
        }
        return nums;
    }
};