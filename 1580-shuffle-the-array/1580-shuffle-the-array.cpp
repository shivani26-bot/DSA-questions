class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     ans.push_back(nums[i]);
        //     ans.push_back(nums[i+n]);
        // }
        // return ans;

        // vector<int>ans;
        // int i=0,j=n;
        // while(i<n && j<2*n){
        //     ans.push_back(nums[i++]);
        //     ans.push_back(nums[j++]);
        // }
        // return ans;

        // without extra space 

        // encode the nums array 
        // this will encode the nums array from index 0 to n-1 , from 0 to n-1 the ecoded form will have nums[i] and nums[i+n] in it
//         for(int i=0;i<n;i++){
//             // (we use 10000 because nums[i] ≤ 1000, so no overlap)
//             nums[i]=nums[i]+nums[i+n]*10000;
//         }
// // decode the array and replace the elements with correct y and x pair 
// int idx=2*n-1;//start from last of the array
// // start from the half of the array and go till start of the array because in this range encoded form exists
// for(int i=n-1;i>=0;i--){
//     // extract y and x from the encoded form 
//     int y=nums[i]/10000;
//     int x=nums[i]%10000;

// // first put y and then x
//     nums[idx--]=y;
//     nums[idx--]=x;
// }
//     return nums;

// using bit manipulation 
// We can use bit shifts instead of 10000 encoding (more efficient).
// Since nums[i] ≤ 1000 (< 2¹⁰), we only need 10 bits to store each number.
// Constraint: 0 <= nums[i] <= 1000.
// \U0001f449 Needs at most 10 bits to represent.
// So we can pack two numbers (x and y) into one integer:
// nums[i] = x | (y << 10)
// Lower 10 bits store x.
// Upper bits (shifted left by 10) store y.
// // Later we decode:
// // y = nums[i] >> 10
// // x = nums[i] & ((1 << 10) - 1) → mask lower 10 bits.
// ## \U0001f4cc Dry Run Example
// Input:

// nums = [2, 5, 1, 3, 4, 7], n = 3
// We want -> [2, 3, 5, 4, 1, 7]
// ### Step 1: Pack values

// Loop `i = 0 → n-1`.
// #### i = 0
// nums[0] = nums[0] | (nums[0+3] << 10)
//          = 2 | (3 << 10)
//          = 2 | 3072
//          = 3074
// #### i = 1
// nums[1] = 5 | (4 << 10)
//          = 5 | 4096
//          = 4101
// #### i = 2
// nums[2] = 1 | (7 << 10)
//          = 1 | 7168
//          = 7169
// Now `nums = [3074, 4101, 7169, 3, 4, 7]`
// ### Step 2: Decode in reverse order
// We start filling from the back (`idx = 5`).
// #### i = 2 (nums\[2] = 7169)
// y = nums[2] >> 10 = 7169 >> 10 = 7
// x = nums[2] & ((1 << 10) - 1)
//   = 7169 & 1023
//   = 1
// nums[5] = y = 7
// nums[4] = x = 1
// Now nums = `[3074, 4101, 7169, 3, 1, 7]`

// #### i = 1 (nums\[1] = 4101)
// y = 4101 >> 10 = 4
// x = 4101 & 1023 = 5
// nums[3] = y = 4
// nums[2] = x = 5
// Now nums = `[3074, 4101, 5, 4, 1, 7]`

// #### i = 0 (nums\[0] = 3074)
// y = 3074 >> 10 = 3
// x = 3074 & 1023 = 2
// nums[1] = y = 3
// nums[0] = x = 2
// Now nums = `[2, 3, 5, 4, 1, 7]`
// ## ✅ Final Output

// [2, 3, 5, 4, 1, 7]

for(int i=0;i<n;i++){
    nums[i]=nums[i]| (nums[i+n]<<10);
}
int idx=2*n-1;
for(int i=n-1;i>=0;i--){
    int y= nums[i]>>10; //upper , right shift nums[i],upper bits (the y-value)
    int x= nums[i] & ((1<<10)-1);//lower, left shift , lower 10 bits (the x-value)
    nums[idx--]=y;
    nums[idx--]=x;
}
return nums;
    }
};


// ## \U0001f4cc Step 1: What is `(1 << 10) - 1`?

// * `1 << 10` = `2¹⁰` = `1024`
// * `(1 << 10) - 1 = 1023`

// In **binary (10 bits)**:

// 1023 = 1111111111   (10 ones)

// So `(1<<10)-1` creates a **mask of the lowest 10 bits set to 1**.

// ## \U0001f4cc Step 2: Why `nums[i] & mask` keeps lower bits?

// The **AND (`&`) operator** keeps a bit only if both are `1`.

// Example:
// Suppose `nums[i]` has:

// ```
// nums[i] = 3074   = 110000000010 (binary)
// ```

// Mask:

// ```
// 1023           = 0000111111111111 (binary, 10 ones)
// ```

// Perform AND:

// ```
//    110000000010   (nums[i])
// &  000011111111   (mask)
// =  000000000010   = 2
// ```

// \U0001f449 That’s the **lower 10 bits** of `nums[i]`.

// ---

// ## \U0001f4cc Step 3: Intuition

// * `(1 << k) - 1` = lowest `k` bits as `1`.
// * `X & ((1 << k) - 1)` = extracts only the **last k bits** of `X`.
// * Shifting (`>> k`) extracts the **upper bits**.

