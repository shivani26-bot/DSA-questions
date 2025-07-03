class Solution {
public:
struct comp {
bool operator() (vector<int>&p, vector<int>&q){
    return (p[0]*p[0]+p[1]*p[1])>(q[0]*q[0]+q[1]*q[1]);
}
};

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>>>pq;
//  vector<vector<int>> result;
//         int n= points.size();
//         // nlogn
//         for(int i=0;i<n;i++){
//             int x1=points[i][0];
//             int y1=points[i][1];
//             double dist= sqrt(pow(x1,2)+pow(y1,2));
//              pq.push({dist, i});//logn
//         }
// // nlogk
//         while(k--){
//             auto ele= pq.top();
//             int idx= ele.second;
//             result.push_back(points[idx]);
//             pq.pop();
//         }
//         return result;



vector<vector<int>>result;
priority_queue<vector<int>,vector<vector<int>>, comp>pq(points.begin(),points.end());
while(k--){
    vector<int>ele= pq.top();
    result.push_back(ele);
    pq.pop();
}
return result;
    }
};