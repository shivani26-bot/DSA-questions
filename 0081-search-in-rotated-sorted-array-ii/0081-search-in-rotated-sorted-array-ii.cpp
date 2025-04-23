class Solution {
public:
int n;
int pivotIndex(vector<int>& arr){
    int low=0, high=n-1;
    while(low<high){

//skip the duplicates
while(low<high && arr[low]==arr[low+1])
low++;
while(low<high && arr[high]==arr[high-1])
high--;
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[high]) low=mid+1;//pivot lies in right part
        else{
           high=mid; //it can be the possible answer, pivot lies in left part
        }
    }
    return high; //pivot doesn't exists
}
bool binarySearch(int low, int high,vector<int>& arr, int target ){
   while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target) return true;
       else if(arr[mid]<target){
            low=mid+1;
        }
        else
            high=mid-1;
       
    }
    return false;
}
    bool search(vector<int>& nums, int target) {
     //    0 1 2 3 4 5 6
        // 1 1 1 1 2 1 1 
        // find the minimum element as pivot ie index=5  and skip the repeating elements 
n=nums.size();
int pivot=pivotIndex(nums);

if(binarySearch(0,pivot-1,nums,target)) return true;

return binarySearch(pivot,n-1, nums,target);

    }
};