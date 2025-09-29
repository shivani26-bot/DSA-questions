class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    //    k value will lie in range of 0 to 2^maximumBit
    // find totalxor of current nums array 
    //    after finding best possible k such that total xor is maximized for each query, remove the last element from the nums array
    // brute force: try on each value of k for each element fo nums

    int n=nums.size();
    vector<int>result(n);
    int total_xor=nums[0];
    for(int i=1;i<n;i++){
        total_xor^=nums[i];
    }
// in order to get max value, total_xor ^ k= max value
// k must be the inverted version of total_xor 
// only invert the bits which is required to represent the total_xor
// because we have 32 bits in which remaining 0's other than total_xor are also converted to 1
// to make a inverted number, xor the number with mask of total bits to represent the number and set all the bits to 1
// to make a mask of n=3 bits , all set to 1, 2^n-1
// 2^maxbit-1 will give the total number of bits to represent the number
// because in the constraints it's given that nums[i]<2^maxBits 
int mask= (1<<maximumBit)-1; //all bits are set
for(int i=0;i<n;i++){
    int possiblek= total_xor^mask; //flip of any number
    result[i]=possiblek;
    total_xor^=nums[n-i-1];
}
return result;
    }
};