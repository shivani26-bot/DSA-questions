class Solution {
public:
    long minEnd(int n, int x) {
    //    write the binary representation of x
    //    n=3, x=4 
    //    x=1 0 0 
    //      1 ? ?
    //      intuition
    //      5-> 0 1 0 1
    //     strictly increasing number than 5 such that 
    //     when we and that number with 5 we get 5 
    //     7->  0 1 1 1
    //     5 & 7 we get 5 itself

    //     n=3 x=4
    //     in order to make array of three elements it sure that we have to keep
        // one element as 4 , we can never take element less than x in nums array
// we want numbers greater than 4 but as small as possible 
// 4 5 6
// 4 & 5 =4
// 5 & 6 =4

// n=2 , x=7
// 7-> 0 1 1 1
// it's guranteed that numbers greater than 7 must have 1 at same position as 7
// 7-> 0 1 1 1
//     ? 1 1 1
//     we can't take 8 (1 0 0 0) because 7&8 =0
//     7|8 will give the next increasing number such that and of 7 & next number=7
//     0 1 1 1 ->7
//     1 0 0 0 ->8
//     1 1 1 1 ->or
//     with help of 8 we get to know the next greater number 

// n=3 , x=37
// 37-> 1 0 0 1 0 1
// 38-> 1 0 0 1 1 0
// or-> 1 0 0 1 1 1 -> next greater number to 37 ie 39
// 37&38 =36
// 39 -> 1 0 0 1 1 1
// 40->  1 0 1 0 0 0
// or->  1 0 1 1 1 1 -> next greater number to 39 ie 47
// 39 &40 =32


// n=3,x=1
// long curr_number=x;
// while(n>1){
// // cout<<curr_number<<endl;
// long next_number= curr_number+1;
// if((curr_number & next_number) != x){
//     next_number= x | next_number;
//     curr_number=next_number;
// }
// else{
//     curr_number=next_number;
// }
// n--;
// }
// return curr_number;
// time:o(n)
long long num=x;
while(n>1){
    num= (num+1)|x;
    n--;
}
return num;
    }
};