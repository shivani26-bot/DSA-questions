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

int res=0;
for(int i=0;i<32;i++){
     int bit= n & 1;
     res=res<<1 | bit;
     n=n>>1;
}
return res;
    }
};