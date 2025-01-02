class Solution {
public:
    int maxScore(string inputStr) {
        int n=inputStr.length();
        vector<int>prefixZero(n,0);
        vector<int>suffixOne(n,0);
        if(inputStr[0]=='0') prefixZero[0]=1;
         if(inputStr[n-1]=='1') suffixOne[n-1]=1;
        for(int i=1;i<n;i++){
                if(inputStr[i]=='0') 
                 prefixZero[i]=1+prefixZero[i-1];
                else prefixZero[i]=prefixZero[i-1];
        }
     for(int i=n-2;i>=0;i--){
                if(inputStr[i]=='1') 
                 suffixOne[i]= 1+suffixOne[i+1];
                else suffixOne[i]=suffixOne[i+1];
        }
        for(int i=0;i<n;i++){
            cout<<prefixZero[i]<<" ";
        }
        cout<<endl;
         for(int i=0;i<n;i++){
           cout<<suffixOne[i]<<" ";
        }
          cout<<endl;
// "1111" "00"
          if((prefixZero[n-1]==0 && suffixOne[0]==n)|| (prefixZero[n-1]==n && suffixOne[0]==0)) return n-1;
             if(n==2 && prefixZero[0]==0 && suffixOne[n-1]==0) return 0;  //"10"
             if(n==2 && prefixZero[0]==1 && suffixOne[n-1]==1) return 2;  //""
        int score=0;
        int maxScore=INT_MIN;
        for(int i=1;i<n-1;i++){ //"0100"
            score=prefixZero[i]+suffixOne[i];
            maxScore=max(score, maxScore);
        }
        return maxScore;
    }
};