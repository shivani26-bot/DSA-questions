class Solution {
public:
struct comp {
    bool operator() (vector<int>&p, vector<int>&q){
        long d1=p[0]*p[0]+p[1]*p[1];
        long d2=q[0]*q[0]+q[1]*q[1];
        return d1>d2;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>result;
        priority_queue<vector<int>,vector<vector<int>>,comp>pq(points.begin(),points.end());
        for(int i=0;i<k;i++){
            vector<int>p=pq.top();
            result.push_back(p);
            pq.pop();
        }
        return result;
    }
};