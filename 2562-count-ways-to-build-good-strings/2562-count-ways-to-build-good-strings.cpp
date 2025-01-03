class Solution {
public:
const int M=1e9+7;
// don't make string for every step, as it will require space, hence use length of string for each step 
// start with string of length 0 
// int solve(int low, int high, int zero,  int one, int len){
// if(len>high) return 0;
// bool addOne=false;
// if(len>=low && len<=high)  addOne=true;
// int append_zero= solve(low,high,zero,one, len+zero);
// int append_one= solve(low,high,zero,one, len+one);
// return (addOne+append_zero+append_one)%M;
       
// }
//     int countGoodStrings(int low, int high, int zero, int one) {
// int len=0;
//            return solve(low,high,zero,one,len);
//     }

int dp[100001];
int solve(int low, int high, int zero,  int one, int len){
if(len>high) return 0;
if(dp[len]!=-1) return dp[len];
bool addOne=false;

if(len>=low && len<=high)  addOne=true;
int append_zero= solve(low,high,zero,one, len+zero);
int append_one= solve(low,high,zero,one, len+one);
return dp[len]=(addOne+append_zero+append_one)%M;
       
}
    int countGoodStrings(int low, int high, int zero, int one) {
int len=0;
memset(dp,-1,sizeof(dp));
           return solve(low,high,zero,one,len);
    }
};