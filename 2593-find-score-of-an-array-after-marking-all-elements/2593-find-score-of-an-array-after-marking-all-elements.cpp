class Solution {
public:
    long long findScore(vector<int>& nums) {
    

        long long score=0;
        int n=nums.size();
        vector<bool>vec(n,true);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(!pq.empty()){
                  int ele=pq.top().first;
                  int idx=pq.top().second;
pq.pop();
if(!vec[idx]) continue;

                  if(idx-1>=0) vec[idx-1]=false;
                  if(idx+1<n) vec[idx+1]=false;
                  vec[idx]=false;
                  score+=nums[idx];
        }
        return score;
    }
};