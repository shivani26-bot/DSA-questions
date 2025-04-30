class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       
        // lower<=pairsum<=upper
    //     if there are x pairs whose sum<lower
    //     y pairs whose sum<=upper
    //              x
    //    --------------------
    //             y
    //    ----------------------------------------
    //    then there will be y-x pairs where lower<=sum<=upper
    // find total pairs having sum<lower
    // find total pairs having sum<=upper
    // {1,4,5,1,7,4,20}
    //     i
    //     for i=0 , arr[i]=1, we never want 1 to be added to number >=7 as it will
    //     produce sum >=lower
    //     hence 1 can pair with 4,5,1,4
    //     1+7,1+8,1+9......>=lower
    //     lower=8, upper=13
    //     upper-nums[0]=12 , hence we  need a number <=12 to form a pair sum <=upper
    //      hence 1 can pair with 4,5,1,7,4
    //      x pairs= 4pairs
    //      y pairs= 5pairs
    //     lower-nums[i] will be the value which will cause sum >=lower when added with nums[i]
    //   upper-nums[i]+1 will be the value which will cause sum>upper
// {1,1,4,4,12,12,12,12,20}
sort(nums.begin(),nums.end());
int n=nums.size();
long long count_pairs=0;
for(int i=0;i<n;i++){
    int index1= lower_bound(nums.begin()+i+1, nums.end(),lower-nums[i])-nums.begin();
    int x_pairs=index1-i-1;
    int index2= lower_bound(nums.begin()+i+1, nums.end(),upper-nums[i]+1)-nums.begin();
    int y_pairs=index2-i-1;
    count_pairs+=(y_pairs-x_pairs);

}
return count_pairs;
    }
};