class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
    
        // try to find  minimum and second minimum o(n)
int minPrice=INT_MAX;
int secMinPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){

          if(prices[i]<minPrice){
            secMinPrice=minPrice;
            minPrice=prices[i];
          }
          else{
            secMinPrice=min(secMinPrice,prices[i]);
          }
        }
        // if sum of min and sec min is > than money then return the money it's not possible to find exactly two chocolates
if(minPrice+secMinPrice>money) return money;
// otherwise return the leftover money
return money-(minPrice+secMinPrice);

    }
};