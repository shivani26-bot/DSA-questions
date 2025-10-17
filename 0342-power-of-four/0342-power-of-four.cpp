class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        // while(n%4==0){
        //     n=n/4;
        // }
        // return n==1;

        // only 1 bit should be set 
//         power of 4 will have only one bit set  
//   1 =0001
//   4 = 0100
//   16 = 10000
// What is 0x55555555?
// 0x55555555 is a hexadecimal number, representing a specific bitmask.
// In binary, it looks like this:
// Hex:    0x5  5  5  5  5  5  5  5
//   Binary: 0101 0101 0101 0101 0101 0101 0101 0101 ///32 bits with even index as set bit
// It has 1s at all even bit positions: 0, 2, 4, 6, ..., 30
// Positions are 0-indexed from the right (least significant bit = position 0)
// (n & (n - 1)) === 0
// That confirms there's only one bit set.
// But powers of 2 include:
// 1 (2⁰) → 0001 ✅ power of 4 (4⁰)
// 2 (2¹) → 0010 ❌ not a power of 4
// 4 (2²) → 0100 ✅ power of 4 (4¹)
// 8 (2³) → 1000 ❌ not a power of 4
// 16 (2⁴) → 0001 0000 ✅ power of 4 (4²)
// check if ony 1 bit is set and bit is set at even position 
// return (n&(n-1))==0 && (n&0x55555555)!=0;
return (n&(n-1))==0 && n&0x55555555;
    }
};