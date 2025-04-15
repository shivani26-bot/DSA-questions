class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int l=0,h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(mid>=1 && mid<=n-1){
if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]) return mid;
else if(arr[mid]<arr[mid+1]) l=mid+1;
else h=mid-1;
            }
            else if(mid==0){
                //start can also be the peak element
                if(arr[mid]>arr[mid+1]) return mid;
                else l=mid+1;
            }
            else if(mid==n-1){
                //end can also be the peak
                if(arr[mid]>arr[mid-1]) return mid;
                else h=mid-1;
            }
        }
        return l;

}
// we use the condition while (low < high) instead of while (low <= high) because we want to narrow down the search range until we find the peak element. When low becomes equal to high, it means we have found the peak element or the search range has been narrowed down to a single element.

//Regarding the return value, it should be the index of the peak element. However, the original implementation returned low instead. To fix this, we need to update the code to return the correct index of the peak element.
//   the binary search continues until low becomes greater than or equal to high, which means the search space is reduced to a single element. In this case, the function returns low, which represents the index of a potential peak element.
    

  
};