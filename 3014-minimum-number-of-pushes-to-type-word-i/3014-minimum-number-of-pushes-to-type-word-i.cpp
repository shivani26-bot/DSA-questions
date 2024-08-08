class Solution {
public:
    int minimumPushes(string word) {
        int count=0,sum=0;
      for(auto it:word){
           count++;
           if(count<=8){
            sum+=1;
           }
           else if(count<=16){
            sum+=2;
           }
           else if(count<=24){
            sum+=3;
           }
          else {
            sum+=4;
           }
      }
      return sum;
    }
};