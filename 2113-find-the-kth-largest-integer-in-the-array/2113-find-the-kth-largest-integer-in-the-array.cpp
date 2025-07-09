class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
    // compare strings directly, because strings can be too long to fit into long long or int data types
    // "Treat shorter strings as smaller, and for same-length strings, use lexicographic order.
    auto comp= [](string& a, string& b){
if(a.size()!=b.size()) return a.size()>b.size();// shorter string = smaller number
return a>b;//exicographic compare if lengths are equal
    };
    // priority_queue, the top element is the "greatest" by default (max heap).
// thats why we are using a custom comparator
    priority_queue<string,vector<string>,decltype(comp)>pq(comp);
    for(auto &str: nums){
        pq.push(str);
        if(pq.size()>k) pq.pop();
    }
    return pq.top();
    }
};