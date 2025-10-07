class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
//          what makes a subarray "nice" - for any two distinct elements in the subarray, their bitwise AND should be 0. This means no two elements in the subarray can have a common set bit. In other words, each bit position can be set in at most one element within the nice subarray. We can think of this as a "bit usage" problem - once an element uses certain bits (has 1s in certain positions), no other element in our nice subarray can use those same bits.
//     I'll use a sliding window technique with these steps:
// Maintain a variable used_bits that tracks which bits are currently "used" by elements in our window
// For each element:
// If it doesn't share bits with used_bits, add it to our window
// If it shares bits, shrink the window from the left until there's no conflict
// Keep track of the maximum window size seen
// The key operations are:
// used_bits & nums[right] != 0: Checks if the current number shares any bits with our window
// used_bits ^= nums[left]: Removes the leftmost element's bits from our tracking
// used_bits |= nums[right]: Adds the current element's bits to our tracking

    int n=nums.size();
    int max_length=1;//given in ques, that subarrays of length 1 are always considered nice
    int used_bits=0;//00000000....00 32 bits

    int i=0,j=0;
    while(j<n){

        //if used bits and current number doesn't give 0 it means same bits are set
        // remove the elements from left by xor operation , because for xor if same bit its output is 0
        while((used_bits & nums[j]) !=0){
used_bits^=nums[i];
i++;
        }

        // if output is 0 then add the element to window  and set the bits of current element in used_bits
        used_bits|=nums[j];
max_length=max(max_length, j-i+1);
j++;
    }
return max_length;
    }
};