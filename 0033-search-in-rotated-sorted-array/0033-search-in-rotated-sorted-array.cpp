class Solution {
public:
// int pivot(vector<int>&arr,int n){
//     int low=0;
//     int high=n-1;
//     while(low<=high){
//         int mid=low+(high-low)/2;
//         // two parts
//         // mid can lie either in first increasing part or second increasing part 
//         // if mid lies in second part
//         if(arr[mid]<=arr[n-1])  high=mid-1; //pivot lies in first part
//         else{
//            if(arr[mid]>arr[mid+1]) return mid;
//            low=mid+1;
//         }
//     }
//     return -1;
// }
// int binarySearch(int low, int high, vector<int>& arr, int target,int n){

   
    // while(low<=high){
    //     int mid=low+(high-low)/2;
    //     if(arr[mid]<target){
    //         low=mid+1;
    //     }
    //     else if(arr[mid]>target){
    //         high=mid-1;
    //     }
    //     else{
    //        return mid;
    //     }
    // }
    // return -1;
// }
    // int search(vector<int>& nums, int target) {
        int search(vector<int>& arr, int target){
        // int n=nums.size();
        // int pivotIndex=pivot(nums,n);
        // int index= binarySearch(0,pivotIndex,nums,target,n);
        // if(index!=-1) return index;
        // index= binarySearch(pivotIndex+1,n-1,nums,target,n);
        // return index;
        int n=arr.size();
        int low=0,high=n-1;
         while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target) return mid;
        if(arr[low]<=arr[mid]){
            if(target>=arr[low] && target<=arr[mid]) high=mid-1;
            else low=mid+1;
        }
        else if(arr[low]>arr[mid]){
             if(target<=arr[high] && target>=arr[mid]) low=mid+1;
            else high=mid-1;
        }
    
    }
    return -1;
    }
};