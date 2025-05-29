class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
         sort(tokens.begin(),tokens.end());
          int i=0,j=tokens.size()-1;
          int score=0;
          int maxscore=0;
         while(i<=j){

             
            if(power>=tokens[i]){
                 power-=tokens[i];
                 score++;
                 maxscore=max(maxscore,score);
                 i++;
             }
             else if(score>=1){
                 power+=tokens[j];
                 score--;
                 j--;
             }
         else break;
             
         }
         return maxscore;
    }
};