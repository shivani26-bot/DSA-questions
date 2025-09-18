class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort by starting point 
        sort(intervals.begin(),intervals.end());

int s=intervals[0][0];
int e=intervals[0][1];

int result=1;//first element will always be inclued in answer
// start from second element of array 
int n=intervals.size();
for(int i=1;i<n;i++){
    // if current interval doesn't lie completely in the prev interval {s,e} then count the current interval 
    // if current interval start point > prev start and current interval end point > e  it means its not completely inside previous s and e
    if(intervals[i][0]>s && intervals[i][1]>e){
        result++;

    }

    // add s and e with next intervals  as we are comparing from upcoming ones
    // if current interval end point is after prev end point update the prev s and e to current interval start and end
    if(intervals[i][1]>e){
s= intervals[i][0];
e=intervals[i][1];
    }
}
 return result;
    }
};