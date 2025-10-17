class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      
// initially we can start with drinking all the numBottles
// ans contains how many water we can drink 
int ans=numBottles;
int emptyBottles=numBottles;//when all bottles are drunk then all are empty
// now we need to exchnage these emtpty bottles 
  // we can exchange bottles only when emptybottles are >= numExchange
while(emptyBottles>=numExchange){
    //find how many bottles out of empty bottles are exchanged
    int exchangeBottles= emptyBottles/numExchange; //we get these many bottles after exchanging empty bottles
    // find remaining bottles out of empty bottles which cannot be exchanged 
    int remainingBottles= emptyBottles%numExchange;
    // answer will add the exchnageBottles
    ans+=exchangeBottles; // because we drink the bottle full of water which we got after exchange

// update the emptybottles, which will be bottle which couldn't be exchanged and number of bottles we got after exchange
emptyBottles= remainingBottles+exchangeBottles;
}
return ans;
    }
};