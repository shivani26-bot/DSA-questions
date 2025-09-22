class Solution {
public:
// int countOnes(int n){
//     int count=0;
//     while(n){
//         n=(n&(n-1));
//         count++;
//     }
//     return count;
// }
    vector<int> countBits(int n) {
        
// vector<int>ans;
//         for(int i=0;i<=n;i++){
//             int ones=countOnes(i);
//             ans.push_back(ones);
//         }
//         return ans;


    //     // any number has log(x) bits, 
    //     // timecomplexity: nlog(i)

// vector<int>ans(n+1,0);
// for(int i=1;i<=n;i++){
//     ans[i]=__builtin_popcount(i);
// }
// return ans;

// Observation about binary numbers:
// Every number can be written as:
// i = 2 * (i/2)   if i is even
// i = 2 * (i/2) + 1 if i is odd
// Example:
// 6 = 2 × 3 → binary 110
// 7 = 2 × 3 + 1 → binary 111
// Set bits relation:
// If i is even:
// Its binary form is just i/2 with one extra 0 at the end.
// Example: 6 (110) = 3 (11) shifted left.
// So number of 1s in i = number of 1s in i/2.

// If i is odd:
// Its binary form is i/2 with an extra 1 at the end.
// Example: 7 (111) = 3 (11) shifted left + 1.
// So number of 1s in i = number of 1s in i/2 + 1.

// Dynamic Programming transition:
// That gives us:
// ans[i] = ans[i/2]        if i is even
// ans[i] = ans[i/2] + 1    if i is odd

vector<int>ans(n+1,0);
for(int i=1;i<=n;i++){
    if(i%2==1)
    ans[i]=ans[i/2]+1;
    else ans[i]=ans[i/2];
}
return ans;
    }
};