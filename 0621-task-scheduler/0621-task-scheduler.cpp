class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]) pq.push(freq[i]);
        }
        int countInterval=0;
        while(pq.size()>0){
            int countWindowSize=0;
            vector<int>temp;
            while(countWindowSize<=n){
                if(pq.size()==0){
                    if(temp.size()>0)
                    
                        countInterval+=(n-countWindowSize+1);
                        break;
                    
                }
                int x=pq.top();
                pq.pop();
                if(x-1>0) temp.push_back(x-1);
                countInterval++;
                countWindowSize++;
            }
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
        }
        return countInterval;

    }
};