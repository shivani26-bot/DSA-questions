class Solution {
public:
vector<vector<int>>merge(vector<vector<int>>&intervals){
    vector<vector<int>>ans;
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    ans.push_back(intervals[0]);
    for(int i=0;i<n;i++){
if(ans.back()[1]>intervals[i][0]){
    ans.back()[1]=max(intervals[i][1],ans.back()[1]);
}
else
ans.push_back(intervals[i]);
    }
    return ans;
}
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // to represent any rectangle we need bottom left and top right corners
        // [x1,y1,x2,y2]
        // rectangles donot overlap
        // either make 2 horizontal or 2 vertical cut in grid
        // after having 2 cuts in either of the direction we will have 3 sections
        // each of the 3 sections must have at least 1 rectangle
        // every rectangle belongs to exactly one section 
        // we can only cut at edges but make sure that cut doesnot goes through another rectangle, it can cut through edges of other rectangles that is fine  
        //  n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
        //  no line can be drawn from 1 to 5 , if we draw vertical line at 1 then red box will cut from between
        //  there is overlap between 1 to 5 and 0 to 2 hence no vertical line can be drawn
        //  if we merge  1 to 5 and 0 to 2 then we get 0 to 5, min(start1,start2) max(end1,end2)
        //  here only we can see that we can't make a vertical cut
        //  if we look forward as well, [3,2,5,3] then this captures from 3 to 5 and there is overlap between 0 to 5 and 3 to 5, if there is overlapping we can merge them, hence we get 0 to 5 after merging
        //  [0,4,4,5] it has captured 0 to 4 on x-axis, hence there is overlap between 0 to 4 and 0 to 5 hence merge them we get 0 to 5
        //  all of them got merged and captured from 0 to 5 hence we can't make a cut anywhere
        // x axis:{(0,5)} only 1 interval, no 2 cuts are possible on x axis
        //  we can try to make cut on y axis ie horizontal cut
// 1,0,5,2],[0,2,2,4]
// 0 to 2 and 2 to 4 there is no overlapping, hence we will not merge this hence there can be a line between 0 to 2 and 2 to 4
// [0,2,2,4], [3,2,5,3] it has captured the y-axis from 2 to 3 
// between 2 to 4 and 2 to 3 there is overlap hence we can merge them to form 2 to 4 we can't draw between 2 to 4

// y axis: {(0,2),(2,4)}
// [0,4,4,5]: 4 to 5, there is no overlap with any other interval on y axis , hence we can draw a cut at 4 on y axis
// y axis: {(0,2),(2,4),(4,5)}, after mergin there are 3 intervals, we can draw 2 lines

// we can have more than 3 intervals on y axis, and we can draw 2 lines on y axis
// number of intervals after merging >=3

// x axis => merge intervals => x
// y axis => merge intervals => y
// if number of intervals in x or y is >= 3 then answer is true 
// use concept of 
// 56. Merge Intervals

// from given array first separate the x and y axis in different array. then apply merge interval on x axis and y axis 
vector<vector<int>>xAxis,yAxis;
for(auto &coord:rectangles){
    int x1=coord[0];
    int y1=coord[1];
    int x2=coord[2];
    int y2=coord[3];
    xAxis.push_back({x1,x2});
    yAxis.push_back({y1,y2});
}
vector<vector<int>>horizontal= merge(xAxis);
if(horizontal.size()>=3) return true;
vector<vector<int>>vertical=merge(yAxis);

return horizontal.size()>=3 || vertical.size()>=3;

    }
};