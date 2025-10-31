class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         Approach 1: Sorting
// Intuition
// We can consider simulating a sequence of reversals on arr to see if it can be turned into target. Consider the following reversal strategy:

// First, we iterate through each element target[i] from left to right. For each target[i], we locate the same element in arr, if it exists. If it does not exist, we can immediately return false as it is not possible to do any number of reversals for arr to match target. If the element arr[j] is found, but not in the same position as target[i], (i.e. j > i), we repeatedly swap arr[j] with the element in front of it, arr[j-1], until j == i. This effectively pushes arr[j] forward to the same position as target[i]. Note that this swapping is equivalent to repeatedly reversing the subarray arr[j-1:j] in which j is decremented at each step.
// This swapping strategy demonstrates that arr can be rearranged in any possible order. As long as arr contains the same elements as target, the ordering of arr does not matter because it can always be reordered into target using the swapping strategy mentioned above.

// Thus, the problem boils down to whether or not arr and target contain the same elements. In order to determine this, we can sort both arrays. If the arrays have the same elements, then their sorted versions should be identical. If they don't have the same elements, then their sorted versions will have at least one differing value at some index i
// o(nlogn)
sort(target.begin(),target.end());
sort(arr.begin(),arr.end());
for(int i=0;i<arr.size();i++){
    if(arr[i]!=target[i]) return false;
}
return true;
    }
};