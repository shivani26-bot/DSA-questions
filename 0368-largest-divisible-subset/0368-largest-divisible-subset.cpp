class Solution {
public:
// [1,16,7,8,4] => sort it => [1,4,7,8,16]
// 1 divides 4 , 4 divides 8 it means that 1 divides 8 as well because 1
// divides 4, that why we sorted it, as in subsets order doesn't matter.
// and we can think in direction of lis
// we can go with pick and not pick only pick the current element if its 
// divisible by the last element in the sequence
// hence ques translates to longest divisible subsequence

// time: o(n^2)+o(n)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      
        int n=nums.size();
        sort(nums.begin(),nums.end());
vector<int>dp(n,1),hash(n);
int maxi=1;
int lastIndex=0;
for(int i=0;i<nums.size();i++){
    hash[i]=i;
    for(int prev=0;prev<i;prev++){
        if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
            dp[i]=1+dp[prev];
            hash[i]=prev;
        }
       
    }
    if(dp[i]>maxi){
        maxi=dp[i];//not required here as we only have to print the largest subset
        lastIndex=i;
            }
}
     vector<int>temp;
     temp.push_back(nums[lastIndex]);
     while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        temp.push_back(nums[lastIndex]);
     }   
     reverse(temp.begin(),temp.end());
 
     return temp;

    
    }
};