class Solution {
public:
    int arrangeCoins(int n) {
        // approach1: start from step =1, and for every step check n >= step, for that steps decrement the coin coint as well 
    //   int step=1;//step will contain that amount of coins, if step=1, 1 coin, step=2, 2 coin and so on...
     
    //   int result=0;
    //   while(n>=step){
    //     n-=step;
    //     result++;
    //     step++;
    //   }
    //   return result;
// approach2: binary search 
// for every mid, find mid*(mid+1)/2<=n
long l=0,h=n;
while(l<=h){
   long mid=l+(h-l)/2;
    if(n>=(mid*(mid+1)/2)) l=mid+1;
    else h=mid-1;
}
return (int)l-1;
    }
};