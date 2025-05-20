class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    
    //    first two elements can be equal
    // start from 2nd index 
    int i=2;
    int n=nums.size();
    int count=0;
    for(int j=2;j<n;j++){
          if(nums[j]!=nums[i-2]){
            swap(nums[i],nums[j]) ;
            i++;
          }
          else{
            count++;
          }
    }
    return n-count;
    }
};