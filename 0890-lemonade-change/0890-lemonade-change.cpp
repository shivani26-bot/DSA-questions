class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    //   20 can be broken in to 10,5 or 5,5,5
    // 10 can be broken in to 5 only 
    // maintain 2 variables for 5 and 10 because change will be in terms of 5 or 10 
    int five=0,ten=0;
    for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            five++;
        }
        else if(bills[i]==10){
            if(five>0){
                five--;
                ten++;
            }
            else {
                return false;
            }
        }
        else{
            if(five>0 && ten>0){
                five--;
                ten--;
            }
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