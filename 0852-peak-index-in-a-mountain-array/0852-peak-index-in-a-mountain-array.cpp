class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // linear search 
        // int n=arr.size();
        // if(arr[0]>arr[1]) return 0;
        // if(arr[n-1]>arr[n-2]) return n-1;
        // for(int i=1;i<n-1;i++){
        //     if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
        //         return i;
        //     }
        // }
        // return -1;

        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid= low+(high-low)/2;
        //    here we do low=mid+! because mid+1 can be the answer
           if(arr[mid+1]>arr[mid]) low=mid+1;
            else  high=mid;
            // we are comparing arr[mid] and arr[mid+1] there is chance that arr[mid] can be the answer that's why we do high=mid

        }
        return low;
    }
};

// arr[i-3]<arr[i-2]<arr[i-1]<arr[i]>arr[i+1]>arr[i+2]>arr[i+3]
          //  mid                                 mid