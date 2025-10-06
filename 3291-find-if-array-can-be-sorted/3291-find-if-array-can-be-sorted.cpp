class Solution {
public:
    bool canSortArray(vector<int>& nums) {
//       adjacent elements
//       swap when setbits are same
//       bubble sort : make n-1 pass on the array having n elements
//       swap adjacent element
//       in every swap, try to place the largest element at the end
//            8 4 2 30   15
// 1st pass   4 2 8 15  |30
// 2nd pass   2 4 8 |15  30
// 3rd pass   2 4 8 15   30   already sorted    
// if we reach at stage where no swap is required, then we need not to 
// do further passes 
// swap only if set bit is equal
//          3,16,8,4,2
// 1st pass 3,8,4,2,|16
// 2nd pass 3,4,2,|8,16
// 3rd pass 3,2,4, 8,16
// 4th pass 3,2,4,8,16  no swap required
// 3>2 but set bits are not equal hence no swap is possible 

// if(arr[j]>arr[j+1] && setbits(arr[j]==setbits(arr[j+1]))) then only swap
int n=nums.size();

for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){//in every pass, the max element bubbles up to right most index
        if(nums[j]<=nums[j+1]) continue; //no swap required
         else{ //if(nums[j]>nums[j+1])
        if(__builtin_popcount(nums[j])== __builtin_popcount(nums[j+1]))
                      swap(nums[j],nums[j+1]);
         else return false;
    }
   

    }
   
}

return true;


    }
};