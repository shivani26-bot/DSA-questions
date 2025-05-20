class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
 vector<int>result(n);
 int left=0,right=n-1;
 int i=0,j=n-1;
 while(i<n){

    if(nums[i]<pivot){
        result[left]=nums[i];
        left++;
    }
    if(nums[j]>pivot){
        result[right]=nums[j];
        right--;
    }
    i++;
    j--;
 }
 while(left<=right){
    cout<<pivot<<" ";
    result[left]=pivot;
    left++;
 }
 return result;
    }
};