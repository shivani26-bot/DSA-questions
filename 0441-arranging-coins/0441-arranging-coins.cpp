class Solution {
public:
    int arrangeCoins(int n) {
      int step=1;//step will contain that amount of coins, if step=1, 1 coin, step=2, 2 coin and so on...
      int result=0;
      while(n>=step){
        n-=step;
        result++;
        step++;
      }
      return result;

    }
};