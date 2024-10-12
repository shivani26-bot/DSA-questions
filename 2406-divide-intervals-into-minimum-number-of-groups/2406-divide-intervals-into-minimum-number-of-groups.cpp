class Solution {
public:
    // time: o(nlogn)
    //     heap operations take logn time
    int minGroups(vector<vector<int>>& intervals) {
        // for interval based questions, first sort based on start point or end point or both 
        int n=intervals.size();
        priority_queue<int,vector<int>,greater<int>>endTimes;
        sort(intervals.begin(),intervals.end());
        endTimes.push(intervals[0][1]);
        // int groups=1;
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
           if(endTimes.top()< start){
            endTimes.pop();
           
           }
            endTimes.push(end);
        }
        return endTimes.size();
    }
};