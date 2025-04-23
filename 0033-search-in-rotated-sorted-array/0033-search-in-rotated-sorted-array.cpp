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
    // int n=nums.size();
     // int pivotIndex=pivot(nums,n);
     // int index= binarySearch(0,pivotIndex,nums,target,n);
  // if(index!=-1) return index;
    // index= binarySearch(pivotIndex+1,n-1,nums,target,n);
     // return index;

// }
    //     int search(vector<int>& arr, int target){
    
    //     int n=arr.size();
    //     int low=0,high=n-1;
    //      while(low<=high){
    //     int mid=low+(high-low)/2;
    //     if(arr[mid]==target) return mid;
    //     // ans lies in first part
    //     if(arr[low]<=arr[mid]){
    //         if(target>=arr[low] && target<=arr[mid]) high=mid-1;
    //         else low=mid+1;
    //     }
    //     // answer lies in second part
    //     else if(arr[low]>arr[mid]){
    //          if(target<=arr[high] && target>=arr[mid]) low=mid+1;
    //         else high=mid-1;
    //     }
    
    // }
    // return -1;
    // }


// approach 1: find the pivot element, pivot element is arr[pivot-1]<arr[pivot]<arr[pivot+1], then apply two times binary search on each part
// also the sorted rotated array means it will have two parts as sorted, 
// the target will lie in either of the parts

// now pivotIndex can be either the minimum element in the array or maximum element in the array 
int n;
//to find the maximum element as pivot
// int pivotIndex(vector<int>& arr){
//     int low=0, high=n-1;
//     while(low<=high){
//         int mid=low+(high-low)/2;
//          // two parts
// //         // pivot or mid can lie either in first increasing part or second increasing part 
// //         // if mid lies in second part
      
//         if(arr[mid]<=arr[n-1]) high=mid-1;//pivot lies in left part
//         else{
//             if(arr[mid]>arr[mid+1]) return mid;//pivot element;
//             else low=mid+1; //pivot lies in right part;
//         }
//     }
//     return -1; //pivot doesn't exists
// }

//to  find minimum element as pivot
int pivotIndex(vector<int>& arr){
    int low=0, high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;

        if(arr[mid]>arr[high]) low=mid+1;//pivot lies in right part
        else{
           high=mid; //it can be the possible answer, pivot lies in left part
        }
    }
    return high; //pivot doesn't exists
}
int binarySearch(int low, int high,vector<int>& arr, int target ){
   while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
           return mid;
        }
    }
    return -1;
}
        int search(vector<int>& arr, int target){
n=arr.size();
// int pivot=pivotIndex(arr);
// int index;
//  index=binarySearch(0,pivot,arr,target);
// if(index!=-1) return index;
// index=binarySearch(pivot+1,n-1, arr,target);
// return index;

int pivot=pivotIndex(arr);
int index;
 index=binarySearch(0,pivot-1,arr,target);
if(index!=-1) return index;
index=binarySearch(pivot,n-1, arr,target);
return index;
    }
};