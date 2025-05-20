class Solution {
public:
// int solve(int index,vector<int>&days, vector<int>&costs){
// if(index>=days.size()) return 0;
// // 1 day pass 
//     int cost_1=costs[0]+solve(index+1,days,costs);
//     // 7 day pass 
//     int max_day=days[index]+7;
//     int j=index;
//     while(j<days.size() && days[j]<max_day){
//         j++;
//     }
//     int cost_7=costs[1]+solve(j,days,costs);
//     max_day=days[index]+30;
//     j=index;
//     while(j<days.size() &&  days[j]<max_day){
//         j++;
//     }
//     // 30 day pass
//     int cost_30=costs[2]+solve(j,days,costs);
// return min(cost_1,min(cost_7,cost_30));
// }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         // for every day we have 3 option, either buy a pass with cost, 2,7,15
// //         day={1,4,6,7,8,20}
// //         first parameter index of day, second parameter value of day
// //         solve(0,1)
// //          solve(1,4)                    solve(4,8) solve(6,)
// // solve(2,6)    solve(5,20) solve(6,)
// //             solve(6,)
// //  we have three options, if we use 2 rs for one day pass
// //      if we use 7 rs for 7 day pass, if we use 15 rs for 30 day pass.
// //     similarly for every index we have 3 choice, 2 rs, 7 rs, 30 rs

// //         when we reach index=6 then it means we have covered all the days in the list
// return solve(0,days,costs);
//     }

// int solve(int index,vector<int>&days, vector<int>&costs,vector<int>&dp){

// if(index>=days.size()) return 0;
   
//    if(dp[index]!=-1) return dp[index];
// // 1 day pass 
//     int cost_1=costs[0]+solve(index+1,days,costs,dp);
//     // 7 day pass 
//     int max_day=days[index]+7;
//     int j=index;
//     while(j<days.size() && days[j]<max_day){
//         j++;
//     }
//     int cost_7=costs[1]+solve(j,days,costs,dp);
//     max_day=days[index]+30;
//     j=index;
//     while(j<days.size() &&  days[j]<max_day){
//         j++;
//     }
//     // 30 day pass
//     int cost_30=costs[2]+solve(j,days,costs,dp);
// return dp[index]=min(cost_1,min(cost_7,cost_30));
// }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
// int n=days.size();
// vector<int>dp(n,-1);
// return solve(0,days,costs,dp);
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
// int n=days.size();

// // dp[i]=minimumm cost to reach till day i
// set<int>st(days.begin(),days.end());

// int lastDay=days.back();
// vector<int>dp(lastDay+1,0);
// // check if you have to travel on ith day or not 
// for(int i=1;i<=lastDay;i++){
//   if(st.find(i)==st.end()) {
//     dp[i]=dp[i-1];
//     continue;
//     }
//     dp[i]=INT_MAX;
    
//     int day1_pass= costs[0]+dp[max(i-1,0)];

//      int day7_pass= costs[1]+dp[max(i-7,0)];
//       int day30_pass= costs[2]+dp[max(i-30,0)];
// // dp[i]=min(day1_pass,min(day7_pass,day30_pass));
// dp[i]=min({day1_pass,day7_pass,day30_pass});
// }
// return dp[lastDay];
//     }



// int solve(int index,vector<int>&days, vector<int>&costs){
// if(index>=days.size()) return 0;
// // 1 day pass 
//     int cost_1=costs[0]+solve(index+1,days,costs);
//     // 7 day pass 
//     int max_day=days[index]+7;

//   int j= upper_bound(days.begin(),days.end(),max_day-1)-days.begin();
//     int cost_7=costs[1]+solve(j,days,costs);
//     max_day=days[index]+30;
//   j= upper_bound(days.begin(),days.end(),max_day-1)-days.begin();
//     // 30 day pass
//     int cost_30=costs[2]+solve(j,days,costs);
// return min(cost_1,min(cost_7,cost_30));
// }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
// return solve(0,days,costs);
//     }


int solve(int index,vector<int>&days, vector<int>&costs,vector<int>&dp){

if(index>=days.size()) return 0;
   
   if(dp[index]!=-1) return dp[index];
// 1 day pass 
    int cost_1=costs[0]+solve(index+1,days,costs,dp);
    // 7 day pass 
    int max_day=days[index]+7;
    int j= upper_bound(days.begin(),days.end(),max_day-1)-days.begin();
    int cost_7=costs[1]+solve(j,days,costs,dp);
    max_day=days[index]+30;
j= upper_bound(days.begin(),days.end(),max_day-1)-days.begin();
   
    // 30 day pass
    int cost_30=costs[2]+solve(j,days,costs,dp);
return dp[index]=min(cost_1,min(cost_7,cost_30));
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
int n=days.size();
vector<int>dp(n,-1);
return solve(0,days,costs,dp);
    }
};