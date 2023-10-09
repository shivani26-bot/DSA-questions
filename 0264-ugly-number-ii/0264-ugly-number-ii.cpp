class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        unordered_map<long long ,bool>umap;
        pq.push(1);
        umap[1]=true;
        long long ans;
        vector<int>primes={2,3,5};
        while(n--){
            ans=pq.top();
            pq.pop();
            for(int i=0;i<3;i++){
                if(umap.find(ans*primes[i])==umap.end()){
                pq.push(ans*primes[i]);
                umap[ans*primes[i]]=true;
                }
            }
        }
        return ans;
    }
};