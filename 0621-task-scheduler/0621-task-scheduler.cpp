class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       //   priority_queue<int>pq;
       //  vector<int>mp(26,0);
       //  for(int i=0;i<tasks.size();i++){
       //      mp[tasks[i]-'A']++;
       //  }
       //  for(int i=0;i<mp.size();i++){
       //      if(mp[i]>0) pq.push(mp[i]);
       //  }
       // int time=0;
       // while(!pq.empty()){
       //     vector<int>temp;
       //     for(int i=1;i<=n+1;i++){
       //         if(!pq.empty()){
       //             int freq=pq.top();
       //             pq.pop();
       //             freq--;
       //             temp.push_back(freq);
       //         }
       //     }
       //     for(int i=0;i<temp.size();i++){
       //         if(temp[i]>0) pq.push(temp[i]);
       //     }
       //     if(pq.empty()){
       //         time+=temp.size();
       //     }
       //     else{
       //         time+=n+1;
       //     }
       // }
       //  return time;
        
        // greedy 
        // idealspots nikalo, sbse jyada time occur hone wala character ki frequency mein se -1 krke and multiply by n
        //     ex: A:4, B:3, C:2, D:1 n=2
        //         A_ _ A_ _ A_ _ A   idealslots= (freq[A]-1)*n because A is has max freq.
        //         A:4, B:4, c:1, D:1 n=2
        if(n==0) return tasks.size();
        vector<int>mp(26,0);
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]-'A']++;
        }
        sort(mp.begin(),mp.end());
        int maxFrequency= mp[25];
        int gaddhe= (maxFrequency-1);
        int idealSlots=gaddhe*n;
        for(int i=24;i>=0;i--){
            idealSlots-= min(mp[i],gaddhe);
        }
        if(idealSlots>0){
            return tasks.size()+idealSlots;
        }
        return tasks.size();
    }
};