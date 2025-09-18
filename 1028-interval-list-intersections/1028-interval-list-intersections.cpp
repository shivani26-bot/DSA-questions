class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n=firstList.size(),m=secondList.size();
        vector<vector<int>>ans;
        if(n==0 || m==0) return ans;
        //  start from 0 indexes of both the array 
        int i=0,j=0;
        // loop both the arrays 
        while(i<n && j<m){
            // find start and end at each iteration
            // start will be max of 2 starting points and end will be min of 2 ending points
            // these start and end will tell the closed interval or intersecting interval

            int start=max(firstList[i][0],secondList[j][0]);
            int end= min(firstList[i][1],secondList[j][1]);
            if(start<=end){
                // add it to ans array
                ans.push_back({start,end});
            }
            // if ending point of current interval in firstlist is smaller than ending point of current interval in secondList it means move the i pointer as current interval in firstlist will now no longer intersect with any of the intervals in second list
            if(firstList[i][1]<secondList[j][1])
            i++;
            else j++;
        }
        return ans;
    }
};