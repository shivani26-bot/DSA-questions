class Solution {
public:
int n;
//we are finding minimum element of array as pivot
int pivotIndex(vector<int>& arr){
    int low=0, high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[high]) low=mid+1;//pivot lies in right part
        else{
           high=mid; //it can be the possible answer, pivot lies in left part
        }
    }
    return high; 
}
    int findMin(vector<int>& nums) {
        n=nums.size();
        int pivot=pivotIndex(nums);
        return nums[pivot];
    }
};