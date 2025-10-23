class Solution {
public:

// s="1296"
// "1"   "12"  "129"  "1296"

// total tc: o(n*2^log10(n^2 ))
// bool check(int i,int currsum,string s, int num){
//     // once we reach end of the string s, just return true if currsum == original num
// if(i==s.length()){
//     return currsum==num;
// }
// if(currsum>num){
//     return false;
// }
// bool possible=false;
// for(int j=i;j<s.length();j++){
//     //find the substring first start from i, and j-i+1 length
//     string sub=s.substr(i,j-i+1);
//     int val=stoi(sub);//convert into integer
//     // now check from j+1
//     possible=possible || check(j+1,currsum+val,s,num);

//     if(possible) return true;
// }

// return possible;
// }
//     int punishmentNumber(int n) {
        
// int punish=0;
//         // run a for loop from 1 to n, for each number find the square first then convert it to string
//         // and then check all possible substring of that string that whether sum of possible substring result in the original num itself or not,
// o(n)
//         for(int num=1;num<=n;num++){
//             int sq=num*num;
//             string s= to_string(sq);
//             // check using recursion , at every index tries to partition, 
// at every index i, we have 2 options that we can do partition that index or not
// for any given number first square the number (in worst case) n*n then there are 
// digits= log10(n^2), number of digits in any given number is log10(n)
// for 2 possiblility 2^log10(n^2)
//             if(check(0,0,s,num)){
//                 punish+=sq; //add the sq number if condition is true
//             }
//         }
//         return punish;
        
//     }

// we can also memoize 
// bool check(int i,int currsum,string s, int num, vector<vector<int>>&dp){
//     // once we reach end of the string s, just return true if currsum == original num
// if(i==s.length()){
//     return currsum==num;
// }
// if(currsum>num){
//     return false;
// }
// if(dp[i][currsum]!=-1) return dp[i][currsum];
// bool possible=false;
// for(int j=i;j<s.length();j++){ 
//     //find the substring first start from i, and j-i+1 length
//     string sub=s.substr(i,j-i+1);
//     int val=stoi(sub);//convert into integer
//     // now check from j+1
//     // check function tries to partition the string in contiguous substring 
//     possible=possible || check(j+1,currsum+val,s,num,dp);

//     if(possible) return true;
// }

// return dp[i][currsum]=possible;
// }
//     int punishmentNumber(int n) {
        
// int punish=0;
// //o(n)
//         for(int num=1;num<=n;num++){
//             int sq=num*num;
//             string s= to_string(sq);
//                 //   2 states are changing currsum and index 
//     vector<vector<int>>dp(s.length(),vector<int>(num+1,-1));
//             // check using recursion 
//             if(check(0,0,s,num,dp)){
//                 punish+=sq; //add the sq number if condition is true
//             }
//         }
//         return punish;
        
//     }
// num=36,sq=1296
// we can find the partition like that
// sum of  each partition should be equal to num
// 1<=num<=1000, only divide till 1000 no need to go to 10000 and more
// ex: num=787, sq="123456"
// 123456%10000=3456 and 123456/10000=12 , if we divide be 10000 then remainder will be greater than num
// 1296%10=6
// 1296/10=129 , similarly we can break this further divide by 10, 100 , 1000

// 1296%100=96
// 1296/100=12

// 1296%1000=296
// 1296/1000=1

// 1296%10000=1296
// 1296/10000=0

// currsum=0, add remainder to currsum, we have possiblity that we can either take mod with 10, 100 or 1000
//                   (1296,0,num=36)
//  we can't get ans from other two partion X check for first one
// 1296%10=6                                                1296%100=96   1296%1000=296  
// (129,6,36)                                                 (12,96,36)  (1,296,36)
// 129%10=9        129%100=29     129%1000=1                         x        x  
// (12,9+6=15,36)  (1,6+29=35,36)   (0,1+6,36)
//      x            1%10=1             x
//                  (0,6+29+1=36,36)
//                  when we reach 0 it means we finished the number 
//                  if any path return true ans is true
    

// we check from 1 to n, if n=1000 then our test case will fail because 
    // edge case:when n=1000, output: 9804657 expected 10804657
    // n=1000,sq=1000000->digits=7 , only case where its 7 digits otherwise till 999 it will be 6 digits only, hence divide by 10000 also to avoid failure of this test case where digits exceeds to 7 digit
    // n=999,sq=998001->digits=6

    bool check(int sq, int currsum,int num){
        if(sq==0){//if at the end sq becomes 0 it means we finished the number
            return currsum==num;
        }
        return check(sq/10,currsum+sq%10,num)||check(sq/100,currsum+sq%100,num)||check(sq/1000,currsum+sq%1000,num)||check(sq/10000,currsum+sq%10000,num);
    }
    int punishmentNumber(int n) {
        int punish=0;
// tc: o(n*2^(log10(n^2)))
// sc: o(log10(n^2))
        for(int num=1;num<=n;num++){
            int sq=num*num;
            if(check(sq,0,num)){
                punish+=sq;
            }
        }
        return punish;
    }
};

// sc: number of digits * n
// // for recursion call, tree depth= number of digits 
// log10(n^2) * n +log10(n^2)