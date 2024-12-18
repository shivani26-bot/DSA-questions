class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
vector<int>finalPrice(n);
finalPrice[n-1]=prices[n-1];
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(prices[j]<=prices[i]){
            finalPrice[i]=prices[i]-prices[j];
            break;
        }
        else{
            finalPrice[i]=prices[i];
        }
    }
}
return finalPrice;
    }
};