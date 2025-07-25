class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=INT_MAX;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            minPrice=min(minPrice,prices[i]);
            ans=max(ans,prices[i]-minPrice);
        }
        return ans;//maxprofit
    }
};