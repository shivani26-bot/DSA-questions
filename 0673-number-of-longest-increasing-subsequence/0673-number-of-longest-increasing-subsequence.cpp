class Solution {
public:
// dp[i] tells length of lis including the ith index, longest increasing subsequence ending at ith indkex
// if we encounter the same length of lis for a particular index 
// for more than 1 time  then we increase the count[i] for dp[i]
// count[i] tells number of lis for the dp[i]
// every index itself is a lis hence dp[i]=1 and count[i]=1 initially
// {1,5,4,3,2,6,7,10,8,9}
// {1,2,2,2,2,3,4}
// {1,1,1,1,1,4,4}
//  1,6  dp[5]=2 when 1 is attached to 6
//  1,5,6  when 5 is attached dp[5]=3
//  1,4,6  when 4 is attached dp[5] remains 3 but count increases by count[2] ie count[5]=2
//  1,3,6  when 3 is attached dp[5] remains 3 but count increases by count[3]  ie count[5]=3
//  1,2,6  when 2 is attached dp[5] remains 3 but count increases by count[4]  ie count[5]=4
// hence  LIS of value 6 is 3 with count 4 {(1,5,6),(1,4,6),(1,3,6),(1,2,6)}

//  for the 7 we can have following lis
//  1,7 dp[6]=2 ie dp[0]+dp[6]
//  if 5 is attached to 7 then the length will be 1,5,7 ie 3
//  now dp[6]=3 and count[1]=1
//  if 4 is attached to 7 then length will be 1,4,7 ie 3
//  we get the length 3 for more than 1 time it means increase the count
//  count[6]=2
//  1,3,7 count[6]=3 
//  1,2,7 count[6]=4
// when we attach 6 to 7 then till 6 lis is already of length 3 hence dp[6]=4 ie dp[6]+dp[5 or prev]
// LIS of value 7 is 4 with count 4 {(1,5,6,7),(1,4,6,7),(1,3,6,7),(1,2,6,7)}.


 int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
            vector<int>dp(n,1),count(n,1);
int maxi=1;
for(int i=1;i<n;i++){
    for(int prev=0;prev<i;prev++){
        if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
            dp[i]=max(dp[i],1+dp[prev]);
            // inherit for the first time
            count[i]=count[prev];
        }
        else if (nums[i]>nums[prev] && 1+dp[prev]==dp[i]){
            // increase the count 
            count[i]+=count[prev];
        }
    }
    maxi=max(maxi, dp[i]);
  
}
int numberOfLIS=0;
for(int i=0;i<n;i++){
    if(dp[i]==maxi) numberOfLIS+=count[i];
}
return numberOfLIS;
 }
};