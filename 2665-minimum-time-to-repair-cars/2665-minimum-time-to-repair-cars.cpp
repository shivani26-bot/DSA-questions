class Solution {
public:
int n;
bool isPossible(long long  t,vector<int>& ranks, int cars ){
    long long actualCars=0;
    for(int i=0;i<n;i++){
         int car=sqrt(t/ranks[i]*1LL);
         actualCars+=car;
    }
    return actualCars>=cars;
}
    long long repairCars(vector<int>& ranks, int cars) {
        n=ranks.size();
        int minm=*min_element(ranks.begin(),ranks.end());
        // The worst-case time — assign all cars to the slowest mechanic (highest rank)
  long long low = 1;
long long high = 1LL * minm * cars * cars;
        long long result=0;
        while(low<=high){
            long long  mid=low+(high-low)/2; //mid represents the minimum possible time, the range of binary search represents time or minutes
            if(isPossible(mid, ranks,cars)) {
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};