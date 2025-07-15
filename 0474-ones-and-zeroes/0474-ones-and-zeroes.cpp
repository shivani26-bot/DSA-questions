class Solution {
public:

// int recursive(int index,vector<string>& strs, int m, int n, unordered_map<string,pair<int,int>>&mp){
// if(index>=strs.size()) return 0;

// int take=0;
// if(mp[strs[index]].first<=m && mp[strs[index]].second<=n){
//     take= 1+recursive(index+1,strs,m-mp[strs[index]].first,n-mp[strs[index]].second,mp);
// }
//  int notTake=recursive(index+1,strs,m,n,mp);
// return max(take,notTake);
// }
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         unordered_map<string,pair<int,int>>mp;
//         for(int i=0;i<strs.size();i++){
//             int count0=0;
//             int count1=0;
//             for(int j=0;j<strs[i].size();j++){
//                 if(strs[i][j]=='0') count0++;
//                 else count1++;
//             }
//             mp[strs[i]]={count0,count1};
            
//         }
//         return recursive(0,strs,m,n,mp);
//     }


// int recursive(int index,vector<string>& strs, int m, int n, unordered_map<string,pair<int,int>>&mp,vector<vector<vector<int>>>&dp){
// if(index>=strs.size()) return 0;
// if(dp[index][m][n]!=-1) return dp[index][m][n];
// int take=0;
// if(mp[strs[index]].first<=m && mp[strs[index]].second<=n){
//     take= 1+recursive(index+1,strs,m-mp[strs[index]].first,n-mp[strs[index]].second,mp,dp);
// }
//  int notTake=recursive(index+1,strs,m,n,mp,dp);
// return dp[index][m][n]= max(take,notTake);
// }
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         unordered_map<string,pair<int,int>>mp;
//         int sz=strs.size();
// vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
//         for(int i=0;i<strs.size();i++){
//             int count0=0;
//             int count1=0;
//             for(int j=0;j<strs[i].size();j++){
//                 if(strs[i][j]=='0') count0++;
//                 else count1++;
//             }
//             mp[strs[i]]={count0,count1};
//         }
//         return recursive(0,strs,m,n,mp,dp);
//     }

// int solve(int idx,vector<string>& strs, int m, int n,unordered_map<string,pair<int,int>>mp){
// if(idx>=strs.size()) return 0;

// int take=0;
// if(mp[strs[idx]].first<=m && mp[strs[idx]].second<=n)
//     take=1+solve(idx+1,strs,m-mp[strs[idx]].first,n-mp[strs[idx]].second,mp);
//     int notTake=solve(idx+1,strs,m,n,mp);
//     return max(take,notTake);
// }
//     int findMaxForm(vector<string>& strs, int m, int n) {
//        unordered_map<string,pair<int,int>>mp;

//        for(auto &str: strs){
//         int count0=0;
//         int count1=0;
//         for(auto &ch: str){
//             if(ch=='0') count0++;
    //         else count1++;
    //     }
    //     mp[str]={count0,count1};
    //    }
    //    return solve(0,strs,m,n,mp);
    // }


int solve(int idx,vector<string>& strs, int m, int n,unordered_map<string,pair<int,int>>&mp,vector<vector<vector<int>>>&dp){
if(idx>=strs.size()) return 0;
if(dp[idx][m][n]!=-1) return dp[idx][m][n];
int take=0;
if(mp[strs[idx]].first<=m && mp[strs[idx]].second<=n)
    take=1+solve(idx+1,strs,m-mp[strs[idx]].first,n-mp[strs[idx]].second,mp,dp);
    int notTake=solve(idx+1,strs,m,n,mp,dp);
    return dp[idx][m][n]=max(take,notTake);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
       unordered_map<string,pair<int,int>>mp;
 int sz=strs.size();
vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
       for(auto &str: strs){
        int count0=0;
        int count1=0;
        for(auto &ch: str){
            if(ch=='0') count0++;
            else count1++;
        }
        mp[str]={count0,count1};
       }
       return solve(0,strs,m,n,mp,dp);
    }
};