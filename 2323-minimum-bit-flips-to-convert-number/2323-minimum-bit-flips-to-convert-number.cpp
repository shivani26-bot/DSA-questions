class Solution {
public:
    int minBitFlips(int start, int goal) {
        // xor the start and goal, by xoring, the similar bits converts to 0 and disimilar bits converts to 1, disimilar means those bits needed to be converted or flipped to make a goal
        // count the number of set bits in xored number using n=n& (n-1) removes the rightmost set bit in every iteration

        int xorResult=start^goal;
        int count=0;
        while(xorResult){
            xorResult= xorResult & (xorResult-1);
            count++;
        }
        return count;
    }
};