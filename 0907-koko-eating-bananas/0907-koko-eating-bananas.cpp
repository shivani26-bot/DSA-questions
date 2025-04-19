class Solution {
public:
bool canEatAllBananas(int x, vector<int>&piles,int h){
int actualHours=0;
    for(int i=0;i<piles.size();i++){
        actualHours+=piles[i]/x;
        if(piles[i]%x!=0) actualHours++;
        //if bananas in current pile is not divisible by x
        // then 1 hour extra will be required to completely finish the banana in the pile
    }
    return actualHours<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        // if koko eats minimum 4 bananas every hour then he can finish all the bananas within 8 hours
        // if koko eats minimum 30 bananas every hour then he can finish all the bananas within 5 hours 
        //  if koko eats minimum 23 bananas every hour then he can finish all the bananas within 6 hours
        // range will represent the bananas
        int low=1, high= *max_element(piles.begin(),piles.end());
 
        while(low<high){
            int mid=low+(high-low)/2;
            if(canEatAllBananas(mid,piles,h))  high=mid; 
            else low=mid+1;
        }
        return low;
    }
};