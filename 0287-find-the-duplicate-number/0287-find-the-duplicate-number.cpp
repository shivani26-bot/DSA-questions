class Solution {
public:
    int findDuplicate(vector<int>& nums) {
// int i=0;
// while(i<nums.size()){
//     if(nums[i]!=nums[nums[i]-1]){
//         swap(nums[i],nums[nums[i]-1]);
//     }
//     else i++;
// }
// int ans;
// for(int i=0;i<nums.size();i++){
//     if(nums[i]!=i+1) {
//           ans=nums[i];
//           break;
//     }
// }
// return ans;
int n=nums.size();
int low=1;
int high=n;
while(low<=high){
    int mid=(low+high)/2;
    int countEle=0;
    for(auto it: nums){
        if(it<=mid){
            countEle++;
        }
    }
    if(countEle<=mid) low=mid+1;
    else high=mid-1;
}
return low;
    }
};