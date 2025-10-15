class Solution {
public:
    int totalMoney(int n) {
        // run a loop while n>0
        // add money for min(n,7) days
        // n-= 7
        // monday+=1
        int result=0;
        int monday_money=1; //start with 1 dollar

        // while day is remaining run the loop 
        while(n>0){

            // start with monday money 
            int money=monday_money;
            for(int day=1;day<=min(n,7);day++){
                result+=money;
                money++;
            }
            n-=7;
            monday_money++;
        }
        return result;


    }
};