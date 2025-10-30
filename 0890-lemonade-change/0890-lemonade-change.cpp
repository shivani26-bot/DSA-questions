class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    //   20 can be broken in to change of 10,5 or 5,5,5
    // 10 can be broken in to change of 5 only 
    // maintain 2 variables for 5 and 10 because change will be in terms of 5 or 10 
    // handle 3 cases when bills[i] is 5 10 and 20 separately
    // if current number is 5 then no need to give change just add it to five 
    int five=0,ten=0;
    for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            five++;
        }
        else if(bills[i]==10){
            // only check for 5 as change , only if we have 5 as change decrement five and increment ten
            if(five>0){
                five--;
                ten++;
            }
            else {
                return false;
            }
        }
        else{
            // first try to break into 5 and 10
            if(five>0 && ten>0){
                five--;
                ten--;
            }
            // then try to break into 5 5 5
            else if(five>=3){
                five-=3;
            }
            else{
                return false;
            }
        }
    }
    return true;
    }
};