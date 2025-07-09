class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
    // compare strings directly, because strings can be too long to fit into long long or int data types
    auto comp= [&](string& a, string& b){
if(a.size()!=b.size()) return a.size()>b.size();
return a>b;
    };
    priority_queue<string,vector<string>,decltype(comp)>pq(comp);
    for(auto &str: nums){
        pq.push(str);
        if(pq.size()>k) pq.pop();
    }
    return pq.top();
    }
};