class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        int n=intervals.size();
        // if new interval starting point is greater than current interval end point it means they are separate and keep inserting the current interval 
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        // buut as soon as the new interval overlaps with current intervals, now find the merged intervals start and end point
        int st=newInterval[0],en=newInterval[1];
        vector<int>mergedInterval={st,en};
        // now check till current intervals first index is less than en
        while(i<n && intervals[i][0]<=en){
            mergedInterval[0]=min(mergedInterval[0],intervals[i][0]);
             mergedInterval[1]=max(mergedInterval[1],intervals[i][1]);
             i++;
        }
    
    ans.push_back(mergedInterval);
    // now push the remaining elements 
    while(i<n){
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
    }
};