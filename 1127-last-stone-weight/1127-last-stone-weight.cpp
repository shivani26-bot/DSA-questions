class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;//maxheap
        //  priority_queue<int> pq(stones.begin(),stones.end());
        int n=stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int p=pq.top();pq.pop();
            int q=pq.top();pq.pop();
            if(p!=q){
                int newStone= p-q;//new stone weight
                pq.push(newStone);
            }
        }
        return pq.empty()?0:pq.top();
    }
};