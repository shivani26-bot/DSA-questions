class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
int n=nums.size();
for(int i=0;i<n;i++){
    minHeap.push({nums[i],i});
}
while(k--){
    int ele=minHeap.top().first;
    int idx=minHeap.top().second;
    minHeap.pop();
    int newel= ele*multiplier;
    nums[idx]=newel;
    minHeap.push({newel,idx});
}
return nums;
    }
};