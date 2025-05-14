class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//         1st element will always be unique ie. nums[0];
// start from i=1, j=1, move the j pointer such that it points to next unique element
// if we are at jth index and it's equal to i-1th index it means we have duplicates keep incrementing j till the time we find the next unique element
// once it's found at nums[i] store nums[j] and increment i++,
int n=nums.size();
int i=1;
for(int j=1;j<n;j++){
    if(nums[j]!=nums[i-1]){
        //unique element is found
        nums[i]=nums[j];
        i++;
    }
}
return i;  //total size of unique elements
    }
};