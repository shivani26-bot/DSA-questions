class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // approach 1
        // find maximum overlapping intervals 
        // sort the intervals based on starting point
        // o(nlogn)
//         vector<pair<int,int>>vec; //stores interval
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             vec.push_back({nums[i]-k,nums[i]+k});

//         }
//         sort(vec.begin(),vec.end());
//         int result=INT_MIN;
//         deque<int>dq;//store the end points
    
//      for(auto it:vec){
// while(!dq.empty() && dq.front()<it.first){
//     dq.pop_front();
// }
//         dq.push_back(it.second);
//         result=max(result, (int)dq.size());
//      }
//      return result;

    //  if array is sorted, for any elements x and y
    //  x-> x-k,x+k
    //  y-> y-k,y+k
    //  intervals of two elements will overlap when ending point of x>= starting point of y
    //  x+k>=y-k
    //  for any given x if we want x==y then y must be <= x+2*k
    //  y<=x+2*k
    // {1,2,3,4,5} k=2
    // x=1, then y<=5
    // all the y's less then equal to 5 can be the answer but we will choose the largest or farthest value 
// hence choose 5
// and all the elements from 1 to 5 can be a beautifull sequence 
//     sort(nums.begin(),nums.end());
//     int n=nums.size();
//     int result=0;
// for(int i=0;i<n;i++){
// int y=nums[i]+2*k;
// int idx=upper_bound(nums.begin(),nums.end(),y)-nums.begin();
// result=max(result,idx-i);

// }
// return result;

// we can also use sliding window such that nus[j]<=nums[i]+2k
// If nums[i] = 5 and k = 2:
// Allowed range = [5, 9]
// Any nums[j] ≤ 9 can still be adjusted to match nums[i]’s adjusted value.
int n=nums.size();
sort(nums.begin(),nums.end());
int i=0,j=0;
int maxBeauty=0;
while(i<n){
// The condition ensures all numbers in the current window can be made equal by adjusting each by at most k.
// k as the maximum amount each number can be adjusted (either up or down).
// If you can increase a number by at most k and also decrease another number by at most k,
// Then the total possible difference you can “cover” between two numbers is 2*k.
while(j<n && nums[j]<=nums[i]+2*k) j++;
maxBeauty=max(maxBeauty,j-i);
i++;
}
return maxBeauty;
    }
};