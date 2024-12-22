class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // approach 1
        // find maximum overlapping intervals 
        // sort the intervals based on starting point
        vector<pair<int,int>>vec; //stores interval
        int n=nums.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums[i]-k,nums[i]+k});

        }
        sort(vec.begin(),vec.end());
        int result=INT_MIN;
        deque<int>dq;//store the end points
    
     for(auto it:vec){
while(!dq.empty() && dq.front()<it.first){
    dq.pop_front();
}
        dq.push_back(it.second);
        result=max(result, (int)dq.size());
     }
     return result;
    }
};