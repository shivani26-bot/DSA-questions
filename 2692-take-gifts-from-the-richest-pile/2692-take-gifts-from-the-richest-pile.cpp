class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
//         priority_queue<int>pq(gifts.begin(),gifts.end());

//         while(k>0){
//             int x=pq.top();
//             pq.pop();
//             int y= floor(sqrt(x));
//             pq.push(y);
//             k--;
//         }
// long long sum=0;
//         while(!pq.empty()){
//             int x=pq.top();
//             pq.pop();
//             sum+=x;

//         }
//         return sum;
//     }
priority_queue<int>pq(gifts.begin(),gifts.end());

while(k-->0){
    int x=pq.top();
    pq.pop();
    int y= floor(sqrt(x));
    pq.push(y);
}
long long sum=0;
while(!pq.empty()){
      int x=pq.top();
      pq.pop();
      sum+=x;
}

return sum;
    }

};