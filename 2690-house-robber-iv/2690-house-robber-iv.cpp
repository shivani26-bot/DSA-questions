class Solution {
public:
int n;
// int solve(vector<int>& nums, int k, int i){
// if(k==0) return 0;//no more houses to be covered
// if(i>=n) return INT_MAX; //invalid path, when k>0 and i >=n; when atleast k houses are not robbed but i is out of bound



//     int take= max(nums[i],solve(nums, k-1,i+2));
//     int skip= solve(nums, k, i+1);

//     return min(take,skip);
// }


//dp
// int solve(vector<int>& nums, int k, int i, vector<vector<int>>&dp){
// if(k==0) return 0;//no more houses to be covered
// if(i>=n) return INT_MAX; //invalid path, when k>0 and i >=n; when atleast k houses are not robbed but i is out of bound
// if(dp[i][k]!=-1) return dp[i][k];


//     int take= max(nums[i],solve(nums, k-1,i+2,dp));
//     int skip= solve(nums, k, i+1,dp);

//     return dp[i][k]=min(take,skip);
// }
//     int minCapability(vector<int>& nums, int k) {
// //dp
// // here we have multiple options to take or skip the houses
//         //                     i
//         //                    {2,3,5,9}  k=2
//         //                 2(take 2)                 skip 2
//         //                  i                          i  
//         //             {2,3,5,9},k=1                {2,3,5,9},k=2
//         //          5(take 5)          skip 5
//         //              i                    i  
//         //     {2,3,5,9},k=0          {2,3,5,9},k=1
//         // (2,5)              9(take 9)   skip 9
//         //                      i                  i
//         //             {2,3,5,9},k=0      {2,3,5,9},k=1
//         //             (2,9)                invalid
//         //             take= max(nums[i],solve(i+2, k-1));
//         //             skip= solve(i+1,k)
//         //             min(take,skip)

// // not a optimal solution tle
// //  n=nums.size();
// // return solve(nums, k ,0);

// //memoization
//  n=nums.size();
//  vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
// return solve(nums, k ,0,dp);
//     }




//dp and recursion solution is not optimal

bool isPossible(vector<int>& nums, int k, int mid){
    int actualHouses=0;
for(int i=0;i<nums.size();i++){
    if(nums[i]<=mid){
        actualHouses++;
        i+=1;//skip adjacent house if u take current house
    }
}
    return actualHouses>=k; //we managed to rob atleast k houses
}
    int minCapability(vector<int>& nums, int k) {
//here we have to minimize the maximum amout of money- use binary search
// kisi bhi problem mei jb minimize krna pre maximum outcome ko
// aur jb maximize krna pre minimum outcome ko - use binary search on ans
// yha capability ka minimum answer find krna hai , here ans is capability hence findbinary search on capability
    int low=*min_element(begin(nums),end(nums));
    int high=*max_element(begin(nums),end(nums));
    // mid will represent, capability mid ke equal aana chahiye atleast k houses rob krne pr
    // nums={2,3,5,9} k=2
    // l=2, h=9
    // mid=5 , write a function that checks whether capability will be 5 on robbing at least k houses
    // hm ussi house ko rob kr skte hai jiski value <=mid ho taki maximum <=mid aaye
    // choose index=0,index=2, number of house stole=2 >=k then return true, mtlb possible h 2 houses se chori krke capability 5 laana
    // but in order to minimize the answer, h=mid-1; 
    // l=2, h=4
    // mid=3
    // we can choose either index=0 or index=1,  number of houses robbed=1 <=l hence ye possible answer nhi hai toh l=mid+1
    // mtlb atleast k houses rob krke capability mid k equal laana possible nhi hai
    // l=4, h=4
    // mid=4 (not possible)  hence l=mid+1
    // l=5, h=4
    // l>h
    // return l as ans

    // agr nums[i]<=mid hai then we have 2 options we can take or skip that house but we need not to do that
    // because in question it's clearly mentioned that it's always possible to steal from k houses
    // it means agr mid ka value valid hoga toh it'll always be possible to steal from k houses, hence we can check greedily as well, 
int result=0;
// o(log(maxC)*n)
    while(low<=high){
        int mid=low+(high-low)/2; //capability
        if(isPossible(nums,k,mid)){
            result=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return result;
    } 
};