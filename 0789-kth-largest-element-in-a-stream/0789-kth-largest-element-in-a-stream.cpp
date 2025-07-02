class KthLargest {
public:
        //min-heap
 priority_queue<int,vector<int>,greater<int>>pq;
 int K;
    KthLargest(int k, vector<int>& nums) {
       K=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();//min element will be popped
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();
        return pq.top();
        
    }
};
// when we pop any element in priority queue it take log(k) times to adjust itself
// for kth largest use min heap, when heap size is greater than k then pop the top element, after that always the top element of the priority queue will be the answer for the kth largest element 

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */