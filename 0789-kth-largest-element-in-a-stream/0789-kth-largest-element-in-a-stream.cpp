class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>>q; //minheap
int K;

 //nlogk
    KthLargest(int k, vector<int>& nums) {
        int n= nums.size();
            K=k;
        // nlogk
        for(int i=0;i<n;i++){
                q.push(nums[i]);//logk
                if(q.size()>k) q.pop();//min element will be popped
        }
    }
    //logk
    int add(int val) {
        q.push(val); //logk
        if(q.size()>K) q.pop();//logk
        return q.top();
    }
};
// when we pop any element in priority queue it take log(k) times to adjust itself
// for kth largest use min heap, when heap size is greater than k then pop the top element, after that always the top element of the priority queue will be the answer for the kth largest element 

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */