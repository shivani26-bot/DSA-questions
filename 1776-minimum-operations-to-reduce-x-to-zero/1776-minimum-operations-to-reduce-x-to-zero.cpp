class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // removing elements only from the leftmost or rightmost ends, not from the middle.
//         we have to remove them in such a way that
// 1.remove minimum number of elements and
// 2.sum of all removed element is X
// if successfully remove elements such that sum of removed elements is X , then
// sum of remaining array elements will be (sum-X)
// remaing array will be subarray of original array.
// find subaarray whose sum is (sum - X) and its length is maximum ( because we want to remove minimum number of elements , so we will have to maximise remianing element ) .
        int i=0,j=0;
        
        int n=nums.size();
        int totalSum=0;
        for (auto num:nums){
            totalSum+=num;
        }
        int targetSum=totalSum-x;
        int maxWindow=INT_MIN;
        int currSum=0;
        while(j<n){
            currSum+=nums[j];
                     if(currSum>targetSum){
                while(i<=j && currSum>targetSum){
                    currSum-=nums[i];
                    i++;
                } 
       
            }
      if(currSum==targetSum){
                maxWindow=max(maxWindow, j-i+1);
            
            }
             j++; 
        }
        if(maxWindow==INT_MIN){
            return -1;
        }
        return n-maxWindow;
    }
};