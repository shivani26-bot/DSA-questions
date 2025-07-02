class Solution {
public:
// n+klogk+nlogn
    long long pickGifts(vector<int>& gifts, int k) {
        //n heapify
priority_queue<int>pq(gifts.begin(),gifts.end());

// klogn
while(k-->0){
    int x=pq.top(); //o(1)
    pq.pop();//log n
    int y= floor(sqrt(x));
    pq.push(y);//logn
}
long long sum=0;
//nlogn  // atmost n elements can be there in pq
while(!pq.empty()){
      int x=pq.top();
      pq.pop();
      sum+=x;
}

return sum;
    }

};