class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
//          It can’t happen that we get 1 ie 10000 at msb of left and 0 ie 01111 at msb of right. Then left will not be less that right. 
//  Here we try to find out msb bit of l and r if both are equal then it can never happen that bit other than that will appear in between.We can find out that by creating mask until we find msb bit of l and r to be unequal.
// When we move from l to r we observe that there is a prefix section which have same kind of bits in each column.
// When both msb at l and r are 1 then only there is contribution of mask. We keep right shifting mask by 1.
int ans=0;
long long mask= (1L<<31);//create a mask of 32 bits left shift 1 by 31 bits
while(mask){
    if((mask&left)==(mask&right)){
        if(mask&left) ans+=mask;
        // right shift the mask by 1 bit 
        mask>>=1;
    }
    else break;
}
return ans;
    }
};