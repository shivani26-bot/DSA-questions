class Solution {
public:

//     vector<int> searchRange(vector<int>& arr, int target) {
//      int n=arr.size();
//      if(n==0) return {-1,-1};

//      int low=0;
//      int high=n-1;
//      vector<int>ans;
//      while(low<=high){
//         int mid=low+(high-low)/2;
//         if(arr[mid]<target){
//             low=mid+1;
//         }
//         else if(arr[mid]>target){
//             high=mid-1;
//         }
//         else{
//             if(mid==0 || arr[mid-1]!=target) {
//                 ans.push_back(mid);
//                 break;
//             }
//             else
//                 high=mid-1;
//         }
//      }
//       low=0;
//     high=n-1;
//  while(low<=high){
//         int mid=low+(high-low)/2;
//         if(arr[mid]<target){
//             low=mid+1;
//         }
//         else if(arr[mid]>target){
//             high=mid-1;
//         }
//         else{
//             if(mid==n-1 || arr[mid+1]!=target) {
//                 ans.push_back(mid);
//                 break;
//             }
//             else low=mid+1;
//         }
//      }
//      if(ans.size()==0){
//         return {-1,-1};
//      }
//      return ans;
//     }

int leftMost(vector<int>& arr, int target,int n){
int left_most_index=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            left_most_index=mid;
            high=mid-1;
        }
    }
    return left_most_index;
}
int rightMost(vector<int>& arr, int target,int n){
int right_most_index=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            right_most_index=mid;
            low=mid+1;
        }
    }
    return right_most_index;
}
  vector<int> searchRange(vector<int>& arr, int target) {
     int n=arr.size();
     if(n==0) return {-1,-1};
     int leftmostIndex= leftMost(arr,target,n);
     int rightmostIndex= rightMost(arr,target,n);
     return {leftmostIndex,rightmostIndex};
    }
};