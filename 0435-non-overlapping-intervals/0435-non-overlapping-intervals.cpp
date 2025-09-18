class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // sort by end
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a , const vector<int>&b){
            return a[1]<b[1];
        });
        int count=0;
        int prevEnd=intervals[0][1];

        for(int i=1;i<n;i++){
            // current interval starting point lies before  ending point of previous interval then it's a overlap remove the interval
if(intervals[i][0]<prevEnd){
    // overlap remove this interval 
    count++;
}
else{
    // no overlap update prevend, because list is sorted
    prevEnd=intervals[i][1];
}

        }
        return count;
    }
};