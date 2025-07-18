class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // sort the array so that we donot need to worry about the age  after sorting , all the older players will come after the younger player, we can directly compare the scores
        vector<pair<int,int>>ageScore;
        int n=scores.size();
        for(int i=0;i<n;i++){
            ageScore.push_back({ages[i],scores[i]});
        }
    sort(ageScore.begin(),ageScore.end());
    vector<int>dp(n);
    int bestScore=0;

    //lis
for(int i=0;i<n;i++){
    dp[i]=ageScore[i].second;
    for(int j=0;j<i;j++){
        if(ageScore[i].second>=ageScore[j].second){
            dp[i]= max(dp[i], dp[j]+ageScore[i].second);
        }
    }
    bestScore= max(bestScore, dp[i]);
}
return bestScore;
    }
};