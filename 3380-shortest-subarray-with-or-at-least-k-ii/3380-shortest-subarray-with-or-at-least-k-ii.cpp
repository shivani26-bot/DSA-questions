class Solution {
public:
void update(int number, vector<int>&vec,int val){
    for(int i=0;i<32;i++){ 
        if((number>>i) & 1){
            vec[i]+=val;
        }
    }
}

int getDecimalFromBinary(vector<int>&vec){

    int num=0;
    for(int i=0;i<32;i++){
        if(vec[i]>0){
            //ith position has 1
            num|=(1<<i);
        }
    }
    return num;
}

// We want the minimum subarray length such that the bitwise OR of all elements in that subarray is ≥ k.
// The challenge is that unlike sums, OR is not reversible, meaning a | b | c cannot be "un-ORed" easily if you remove an element.

// Observation: Bitwise OR is cumulative and non-decreasing:
// Adding more numbers will never reduce the OR.
// So, for a subarray [i..j], OR([i..j]) ≥ OR([i..j-1]).

// Sliding Window + Bit Count:
// To handle OR while shrinking the window, we track each bit separately.
// vec[i] stores how many numbers in the current window have the i-th bit set.
// When adding a number: increment counts of its set bits.
// When removing a number: decrement counts of its set bits.
// Reconstruct OR:
// Use getDecimalFromBinary(vec) to reconstruct the OR from bit counts:

// OR = 0;
// for each bit i:
//     if vec[i] > 0 -> OR |= (1 << i)

// Sliding Window Logic:
// Expand j (end of window) one by one.
// After adding nums[j], check if OR ≥ k.
// If yes, shrink from the left (i) as much as possible while OR ≥ k.
// Update min_window for each valid window.
// ✅ This works because tracking each bit count allows us to “remove” a number safely, unlike normal OR.
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // cumulative bitwise or always follows the non decreasing pattern
        // 3|2|1 final result will be greater or equal to 3
        // 3,3,3,2,1,5,5 k=6
        // 3|3|3|2|1|5 =7>=k
        // we can also down size the current size of subarray
        // 3|2|1|5 =7>=k
        // 2|1|5=7>=k
// store for how many elements 0th, 1st, 2nd....and so on bits are set
// in order to remove element while sliding the window , just decrease the respective bit position of that element 

        int i=0,j=0;
        int n=nums.size();
        int min_window=INT_MAX;
        vector<int>vec(32,0);
        while(j<n){
            update(nums[j],vec,1);

                while(i<=j && getDecimalFromBinary(vec)>=k){
 min_window=min(min_window,j-i+1);
 update(nums[i],vec,-1);
 i++;
                }
                j++;
            
        }
        return min_window==INT_MAX?-1:min_window;
    }
};