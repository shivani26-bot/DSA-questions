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
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int result=0;
for(int i=0;i<n;i++){
int y=nums[i]+2*k;
int idx=upper_bound(nums.begin(),nums.end(),y)-nums.begin();
result=max(result,idx-i);

}
return result;

    }
};