class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int n=arr.size();
        // int low=0,high=n-1;
        // while(low<=high){
        // int mid=(low+high)/2;
        // if (mid==0){
        //   if(arr[mid+1]!=arr[mid]) return arr[mid];
        // else 
        // low=mid+1;
        // }
        // else if(mid==n-1){
        //     if(arr[mid-1]!=arr[mid]) return  arr[mid];
        //     else high=mid-1;
        // }
        // else if(arr[mid]!=arr[mid+1] && arr[mid-1]!=arr[mid]) return arr[mid];
        // else{
        //     int fo,so;
        //     if(arr[mid]==arr[mid+1])
        //           {  fo=mid; so=mid+1;}
        //     else
        //           { fo=mid-1;so=mid;}
        //     if(fo%2==0) low=mid+1;
        //     else 
        //     high= mid-1;
        // }
        // }
        // return -1;
      
       int n = nums.size();
        
        // apply binary search
        
        int low = 0;
        
        int high = n - 1;
        if(nums.size()==1) return nums[0];
        
        while(low <= high)
        {
            // find mid
            
            int mid = (high + low) / 2;
            
            // if the mid is even then it is the 1st instance
            
            if(mid % 2 == 0)
            {
                if(nums[mid] == nums[mid + 1])
                {
                    low = mid + 1;
             }
                else
                {
                      high = mid - 1;
                }
            }
            
            // if the mid is odd then it is the second instance
            
            else if(mid % 2 == 1)
            {
                if(nums[mid] == nums[mid - 1])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        
        return nums[low];
    }
};