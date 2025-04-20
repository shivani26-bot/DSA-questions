class Solution {
public:
bool canDistribute(int mid,vector<int>& candies, long long k, long long  total_candies,int n){
long long  actualPiles=0;
// actualPiles=total_candies/mid;
 for (int c : candies) actualPiles += c / mid;
return actualPiles>=k;

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