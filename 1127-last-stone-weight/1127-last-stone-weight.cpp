class Solution {
public:
//
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;//maxheap
        //  priority_queue<int> pq(stones.begin(),stones.end());//o(n)
        int n=stones.size();
        // nlogn
        for(int i=0;i<n;i++){
            pq.push(stones[i]); //logn
        }

// (n-1)logn
        while(pq.size()>1){
            int p=pq.top();pq.pop();//logn
            int q=pq.top();pq.pop();//logn
            if(p!=q){
                int newStone= p-q;//new stone weight
                pq.push(newStone);//logn
            }
        }
        return pq.empty()?0:pq.top(); //o(1)
    }
};