class Solution {
public:
    int getSum(int a, int b) {
//     XOR (^) gives the sum without carry.
// AND (&) + left shift gives the carry. 
// a ^ b: Adds bits without carry
// (a & b) << 1: Finds carry and shifts it to left (to be added in next step)
// Repeat until no carry remains (b == 0)
// 1            0            0             1
// 1            1            0             0
// ---         ----         ----          ----
// 0, carry 1   1 carry=0    0 carry=0     1 carry=0
// if we do xor of two bits , a^a=0 (for similar bits), a^b=1 (for different bits);
// in order to find the carry, a&b, because only when 1 & 1 then 1 but we need to left shift this carry by 1 position to use in next bit 

// a=9, b=11 
while(b!=0){
    int carry= (a&b)<<1;
    a=a^b;
    b=carry;
}
return a;
    }
};