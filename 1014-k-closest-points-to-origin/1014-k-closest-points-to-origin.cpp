class Solution {
public:
//   priority_queue<vector<int>,vetor<vector<int>>,comp>pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>>>pq;
 vector<vector<int>> result;
        int n= points.size();
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            double dist= sqrt(pow(x1,2)+pow(y1,2));
             pq.push({dist, i});
        }

        while(k--){
            auto ele= pq.top();
            int idx= ele.second;
            result.push_back(points[idx]);
            pq.pop();
        }
        return result;
    }
};