class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
int prevEnd=0;
int count=0;
        for(int i=0;i<n;i++){
            int currStart=meetings[i][0];
if(currStart>prevEnd){
    count+=(currStart-prevEnd-1);
}

prevEnd=max(prevEnd,meetings[i][1]); //keep the ending time maximum , if in case overlaps 
        }
        if(prevEnd<days) count+=(days-prevEnd);
        return count;
    }
};

// [[1,5],[2,4]]
// days=10
