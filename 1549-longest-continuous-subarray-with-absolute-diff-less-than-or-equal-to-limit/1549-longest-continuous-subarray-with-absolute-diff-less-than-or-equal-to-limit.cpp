class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       
    //    data structure that efficiently track the min and max in a sliding window
    deque<int>maxdq;
    deque<int>mindq;
        int n=nums.size();
        int i=0,j=0;
        int maxWindow=INT_MIN;
        maxdq.push_back(0);//max-dq store the index of nums array which has maximum element
        mindq.push_back(0);//mindq store the index of num array which has minimum element
        while(j<n){
            while(!maxdq.empty() && nums[j]>=nums[maxdq.back()]){
                maxdq.pop_back();
            }
          maxdq.push_back(j);
          while(!mindq.empty() && nums[j]<=nums[mindq.back()]){
            mindq.pop_back();
          }
mindq.push_back(j);
while(abs(nums[maxdq.front()]-nums[mindq.front()])>limit){
    if(maxdq.front()==i){
        maxdq.pop_front();
    }
    if(mindq.front()==i){
        mindq.pop_front();
    }
    i++; 
}
            maxWindow=max(maxWindow,j-i+1);
            j++;
        }
        return maxWindow;
    }
};