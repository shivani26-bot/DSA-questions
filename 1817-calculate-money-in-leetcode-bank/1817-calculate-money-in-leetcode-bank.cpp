class Solution {
public:
    int totalMoney(int n) {
        // run a loop while n>0
        // add money for min(n,7) days
        // n-= 7
        // monday+=1
        // o(n)
        // int result=0;
        // int monday_money=1; //start with 1 dollar

        // // while day is remaining run the loop 
        // while(n>0){

        //     // start with monday money 
        //     int money=monday_money;
        //     for(int day=1;day<=min(n,7);day++){
        //         result+=money;
        //         money++;
        //     }
        //     n-=7;
        //     monday_money++;
        // }
        // return result;

        // 0(1)
        // n=21
        // 1st week= 1+2+3+4+5+6+7=28
        // 2nd week= 2+3+4+5+6+7+8=35
        // 3rd week= 3+4+5+6+7+8+9=42
//         it forms an arithmetic progression as common difference is 7 constant between 28,35,42
//          Sum of n arithmetic progression :( total_terms/2 )*(a1+an)
//          3/2* (28+42) = 35*3= 105
//          total weeks =n/7 = total terms =21/7=3
//          nth terms Tn or an= a1+(n-1)*d= 28+(3-1)*7 =42
// but when n is not divisible by 7
// n=25
//   1st week= 1+2+3+4+5+6+7=28
//         2nd week= 2+3+4+5+6+7+8=35
//         3rd week= 3+4+5+6+7+8+9=42
//         4th week= 4+5+6+7
//         n%7 days will be reamining in last week
// we can use ap formula for 1st 3 weeks 
// and find out for final week separately
// first term of last week= 1+(number of weeks passed, n/7 )
// use for loop for last week 
int terms=n/7;
int first=28;
int last=28+(terms-1)*7;//7 is the difference, 

//this will also take care of fact when original n<7 , then terms will be 0 and result will be 0 , then we need to go to for loop
int result= terms*(first+last)/2;

// final week remaining days=n%7
// start money for last week 
int start_money= 1+terms;
for(int day=1;day<=(n%7);day++){
    result+=start_money;
    start_money++;
}
return result;
    }
};