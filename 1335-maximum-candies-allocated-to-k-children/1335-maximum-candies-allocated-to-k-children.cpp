class Solution {
public:
bool canDistribute(int mid,vector<int>& candies, long long k, long long  total_candies,int n){
long long  actualPiles=0;
// actualPiles=total_candies/mid; wrong :This distributes all candies as a single large pile and divides them evenly.

// It assumes you can break and regroup candies across different types, which is usually not allowed in distribution problems.

 for (int c : candies) actualPiles += c / mid;
return actualPiles>=k;
// For candies = {5, 7} and mid = 3:
// From 5: 5 / 3 = 1 pile
// From 7: 7 / 3 = 2 piles
// Total actualPiles = 1 + 2 = 3
}
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int low= 1, high=*max_element(candies.begin(),candies.end());
        long long total_candies=0;
        for(int i=0;i<n;i++){
            total_candies+=candies[i];
        }
        if(k>total_candies) return 0;//not enough candies
        int result=0;
        while(low<=high){
            int mid=low+(high-low)/2;
    
            if(canDistribute(mid,candies, k,total_candies,n)){
                 result=mid;
            low=mid+1;
            }
            else high=mid-1;
        }
        return result;
    }
};