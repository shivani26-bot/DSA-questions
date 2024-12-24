class Solution {
public:
int binarySearch(vector<vector<int>>& events,int n, int endTime){
    int l=0;
    int h=n-1;
    int result=n;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(events[mid][0]>endTime){
            result=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return result;
}
int  solve(int i, int n,vector<vector<int>>& events , int count, vector<vector<int>>&dp){

if(count==2 || i>=n) return 0;
if(dp[i][count]!=-1) return dp[i][count];
int nextValidEventIndex=binarySearch(events,n,events[i][1]);
    int take= events[i][2] + solve(nextValidEventIndex,n,events,count+1,dp);
    int not_take= solve(i+1,n,events,count,dp);
    return dp[i][count]=max(take,not_take);

}
    // int maxTwoEvents(vector<vector<int>>& events) {
    //     // for every event we have two option, either we can take it or not 
    //     // brute force 
    //     // o(n^2)
    //     int n=events.size();
    //     int result=0;
    //     for(int i=0;i<n;i++){
    //         int val=events[i][2];
    //         result=max(result,val);
    //         for(int j=0;j<n;j++){
    //             if(i==j) continue;
    //             if(events[i][1]>=events[j][0] && events[j][1] >= events[i][0]) continue;
    //             result=max(result, val+events[j][2]);
    //         }
    //     }
    //     return result;
        
    // }


    int maxTwoEvents(vector<vector<int>>& events) {
   
        // we can also use dp 
        // in interval based questions try to sort based on either start point or end point 
        sort(events.begin(),events.end());
        // take a event and search for all the event whose starting point > current event's ending point 
        int n=events.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
     return solve(0,n,events,0,dp);
    }
};