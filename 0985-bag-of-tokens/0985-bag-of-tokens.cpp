class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
          int i=0,j=n-1;
   int score=0,maxScore=0;
if(n==1){
    if(power>=tokens[0]) return score+=1;
    else return 0;
}
 
   while(i<=j){
if(power>=tokens[i]){
    score+=1;
  
    power-=tokens[i];
      cout<<power<<" "<<score<<endl;
    i++;
}
else if(score>=1){
    power+=tokens[j];
    score-=1;
  
     cout<<power<<" "<<score<<endl;
    j--;
}
else {
    i++;
    
}
  maxScore=max(score,maxScore);
   }

 
   return maxScore;
    }
};