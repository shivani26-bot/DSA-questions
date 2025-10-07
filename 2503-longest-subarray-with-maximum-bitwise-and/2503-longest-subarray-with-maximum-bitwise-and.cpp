class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxAndValue= *max_element(nums.begin(),nums.end());
        int temp_len=0;
        int maxLength=1;
        for(int i=0;i<n;i++){
            if(nums[i]==maxAndValue){
                   temp_len++;
            }
            else{
                 maxLength=max(maxLength,temp_len);
                 temp_len=0;
            }
        }
         maxLength=max(maxLength,temp_len);
         return maxLength;
    }
};

// a1&a2 is always less than or equal to either a1 or a2
// [5,5,5,1,5]
// what is the streak of  maximum value in the array because 
// when we and two values we always get answer as less or equal to the
// largest element
// for ex: 5&7 =5
// hence the maxAnd value in the array is the maximum element in the entire array 
// now find the maximum length of subarray whose and is maxAnd value 