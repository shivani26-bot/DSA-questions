class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // values[i] + values[j] + i - j=> try to rearrange the expression
        // ( values[i]  + i) + (values[j] - j)

        // for any given index we want to know the maximum value of values[i]+i from left side that we will maintain in dp variable
       int n=values.size();
       if(n==2) return values[0]+values[1]-1;

       int dp=values[0]+0, score=0;
       for(int j=1;j<n;j++){
        int val=values[j];
        score= max(score, dp+val-j);

        dp=max(dp,val+j);
       }
       return score;
    }
};