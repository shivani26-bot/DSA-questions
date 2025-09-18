class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
int n=intervals.size();
priority_queue<int,vector<int>,greater<int>>endTimes;
endTimes.push(intervals[0][1]);


        for(int i=1;i<n;i++){
          
           int s=intervals[i][0];
           int  e=intervals[i][1];
        //    if smallest endTime in endTimes queue is less than current intervals start time , we can pop the endtimes from queue add the current intervals end time
        // as the queue stores the last end time for each group 
           if(endTimes.top()<s){
            endTimes.pop();
           }
           endTimes.push(e);
        }
        return endTimes.size();
    }
};