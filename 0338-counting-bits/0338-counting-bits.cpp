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

vector<int>ans(n+1,0);
for(int i=1;i<=n;i++){
    ans[i]=__builtin_popcount(i);
}
return ans;
    }
};