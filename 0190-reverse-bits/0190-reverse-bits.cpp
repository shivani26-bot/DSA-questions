class Solution {
public:
    int reverseBits(int n) {
//      Reversing the bits means flipping the order of all 32 bits.
// So the first bit becomes the last bit, the second becomes the second-to-last, and so on.   
// The least significant bit should become the most significant, and vice versa.
// int res=0;
// for(int shift=31;shift>=0;shift--){
//     // find the right most bit first 
//     int bit= n & 1;
//     res=res+(bit<<shift);//shift the bit to the left by shift times
//     n=n>>1; //right shift by 1 to get the next bit
// }
// return res;

// Dry Run Example

// Let’s take n = 13 (binary: 000...0001101) for simplicity (not full 32 bits, I’ll just track the lower bits).
// Initial:
// res = 0 (0000)
// n = 1101

// Iteration 1 (i=0)
// bit = n & 1 = 1101 & 0001 = 1
// res = (0 << 1) | 1 = 0 | 1 = 1 → (0001)
// n = n >> 1 = 1101 >> 1 = 0110

// Iteration 2 (i=1)
// bit = n & 1 = 0110 & 1 = 0
// res = (0001 << 1) | 0 = (0010) | 0 = 0010 → (2)
// n = 0110 >> 1 = 0011

// Iteration 3 (i=2)
// bit = 0011 & 1 = 1
// res = (0010 << 1) | 1 = (0100) | 1 = 0101 → (5)
// n = 0011 >> 1 = 0001

// Iteration 4 (i=3)
// bit = 0001 & 1 = 1
// res = (0101 << 1) | 1 = (1010) | 1 = 1011 → (11)
// n = 0001 >> 1 = 0000

// Rest of iterations (i=4..31)
// Now n = 0, so bit = 0 always.
// Each time, res just shifts left (adds zeros).
int res=0;
for(int i=0;i<32;i++){
     int bit= n & 1; // extract last bit of n
     res=res<<1 | bit; // shift res left, insert extracted bit
     n=n>>1; // shift n right
}
return res;
    }
};