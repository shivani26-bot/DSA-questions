class Solution {
public:
// ["A","C","A","B","D","B","A","A","A","A"]  n=1
// CDBABA_A_A_A_A =14 times
// try to finish the task occuring more number of times at start only
// ABABACADA_A => only 1 idle time
// use priority queue
// freq: A=6,B=2,C=1,D=1
// n=1, pq: 6 2 1 1 
// freq=6->5
// freq=2->1
// A B 
// At a time we pick n+1  task,because when we do our first task, we need to wait for n interval before doing the same task
// store this in temporary vector and put back in priority queue
// {5,1}
// pq: 5 1 1 1 
// freq=5->4
// freq=1->0
// A B | A B
// {4}
// pq: 4 1 1 
// freq=4->3
// freq=1->0
// A B | A B | A C
// {3}
// pq: 3 1 
// freq=3->2
// freq=1->0
// A B | A B | A C | A D
// {2}
// pq: 2 
// freq=2->1
// A B | A B | A C | A D | A _ 
// {1}
// pq: 1
// freq=1->0  
// A B | A B | A C | A D | A _ |A  -> every time we add n+1 time, as we are performing n+1 tasks, for last task we only did task equal to size of priority queue
// now priority queue is empty


// {"A","A","A","B","B","B"} n=2
// pq: 3  3
// freq=3->2
// we need 2 more task before doing the same task as n=2
// freq=3 ->2
// A B _ |
// {2,2}
// pq: 2 2
// freq=2->1
// we need 2 more task before doing the same task as n=2
// freq=2 ->1
// A B _ |A B _
// {1,1}
// pq: 1 1
// freq=1->0
// we need 2 more task before doing the same task as n=2
// freq=1 ->0
// {0,0} pq is now empty it means we have done only 2 tasks
// A B _ |A B _ | A B  -> n+1 time for each, except the last one

    int leastInterval(vector<char>& tasks, int n) {
       priority_queue<int>pq; //max heap
       vector<int>mp(26,0);
       for(auto ch: tasks){
        mp[ch-'A']++;
       }
       for(auto it: mp){
        if(it>0) pq.push(it);
       }
       int time=0;

       while(!pq.empty()){
vector<int>temp;
        // in each section we perform n+1 tasks then only we can repeat the same task
        for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
                int freq= pq.top();
                pq.pop();
                freq--;//use the element and decrease its frequency
temp.push_back(freq);
            }
        }
              for(auto it:temp){
                if(it>0) pq.push(it);
              }
              if(pq.empty()) time+=temp.size();
              else time+=n+1;
      
       }
       return time;
        
        // greedy 
        // idealspots nikalo, sbse jyada time occur hone wala character ki frequency mein se -1 krke and multiply by n
        //     ex: A:4, B:3, C:2, D:1 n=2
        //         A_ _ A_ _ A_ _ A   idealslots= (freq[A]-1)*n because A is has max freq.
        //         A:4, B:4, c:1, D:1 n=2
        // if(n==0) return tasks.size();
        // vector<int>mp(26,0);
        // for(int i=0;i<tasks.size();i++){
        //     mp[tasks[i]-'A']++;
        // }
        // sort(mp.begin(),mp.end());
        // int maxFrequency= mp[25];
        // int gaddhe= (maxFrequency-1);
        // cout<<maxFrequency<<" "<<gaddhe<<endl;
        // int idealSlots=gaddhe*n;
        // for(int i=24;i>=0;i--){
        //     idealSlots-= min(mp[i],gaddhe);
        // }
        // if(idealSlots>0){
        //     return tasks.size()+idealSlots;
        // }
        // return tasks.size();
    }
};