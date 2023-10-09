vector<long>nums;


class Solution {
public:
struct comp{
        bool operator()(pair<long,long> &p1,pair<long,long> &p2){
             return p1.first*nums[p1.second] > p2.first*nums[p2.second];
        }
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
nums.clear();
 priority_queue<pair<long,long>,vector<pair<long,long>>,comp> pq;
        nums.push_back(1);
        for(int i=0;i<primes.size();i++){
            pq.push({primes[i],0});  //this zero is index in nums...
        }
    while(nums.size()<n){
        pair<long,long>p=pq.top();
        pq.pop();
        if(p.first*nums[p.second]>nums[nums.size()-1]){
            nums.push_back(p.first* nums[p.second]);
        }
        pq.push({p.first,p.second+1});
    }
    return nums[nums.size()-1];
    }
};