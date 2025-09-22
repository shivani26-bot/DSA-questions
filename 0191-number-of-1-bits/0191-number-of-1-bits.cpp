class Solution {
public:
    int hammingWeight(int n) {
        // int count=0;
        // while(n){
        //     if(n&1){
        //         count++;
        //     }
        //     n=n>>1;
        // }
        // return count;

        // make a mask shift 1 to left side by 32 position
        // long long mask=1L<<32;
        // int count=0;
        // while(mask){
        //     if(mask & n) count++;
        //     mask>>=1;//right shift the mask by 1 bit
        // }
        // return count;

int count=0;
        while(n){
            n=(n&(n-1));//remove the lowest set bit.
            count++;
        }
        return count;
    }
};