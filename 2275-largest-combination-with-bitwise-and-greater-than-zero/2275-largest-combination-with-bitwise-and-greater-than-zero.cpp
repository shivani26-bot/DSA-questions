class Solution {
public:
    int largestCombination(vector<int>& candidates) {
    //   [1,4,5,9,8,7,2]
    //   largest combination size= 4
    //   [5,9,7,1] bitwise and of all the elements here is >0
    //    0 1 0 0
    //    1 0 1 0 -> 1 in original number is inverted to 0
    //    0 0 0 0 & we must have atleast one 1 in the result so that ans >0

    //    hence we should choose a second number such that atleast one position have 1 as it is there in the first number
    //    0 1 1 0 ->first number
    //    1 0 1 0 , 0 1 0 0-> second number
    //    bit position in which ther is 1 for all numbers 
//     represent each number in binary
//     start from 0th bit and find all the numbers for which bit is set to 1
//         4 3 2 1 0 -> bit position 
//     1-> 0 0 0 0 1
//     4-> 0 0 1 0 0
//     5-> 0 0 1 0 1
//     9-> 0 1 0 0 1
//     8-> 0 1 0 0 0
//     7-> 0 0 1 1 1
//     2-> 0 0 0 1 0
// for 0th bit there are 4 numbers whose bit are set to 1, (1,5,9,7) bitwise and of all these numbers is 1
// for 1st bt there are 2 numbers (7,2)
// for 2nd bit there are 3 numbers ( 4,5,7)
// for 3rd bit ther are 2 number (9,8) 
// max count of all the bits will give the answer 
int n=candidates.size();
int max_count=INT_MIN;
// 1 <= candidates[i] <= 107
// how many bits required to represent 10^7
// number of bits required to represent a number in binary 
// bits= floor(log2(n))+1

// log2(10^7) = log10(10^7)*log2(10)
//               23.25
for(int bitPosition=0;bitPosition<24;bitPosition++){
    int count=0;
    for(int i=0;i<n;i++){
        if((1<<bitPosition) & candidates[i])
        {
            count++;
        }
    }
    max_count=max(max_count,count);
}
 
return max_count;


    }
};