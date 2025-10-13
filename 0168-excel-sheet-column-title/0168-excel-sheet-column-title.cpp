class Solution {
public:
    string convertToTitle(int columnNumber) {
        // after 26 letters it will start repeating, 
        // A, B, C, D, E, F, G, H, I, J, K, L,......,Z
        // AA,AB,AC,AD,AE,AF,AG,AH,AI,AJ,AK,AL.......AZ
        // BA,BB,BC,BD,BE,BF,BG,BH,BI BJ,BK,BL,......BZ

        // In decimal, after 10 letters it starts repeating
        // 1,2,3,4,5,6,7,8,9,10
        // 11,12,13,14,15,16,17,18,19,20
        // 21,22,23,24,25,26,27,28,29,30
          
        //   ascii value range for A to Z => 65 to 90
        //   remainder + 'A'= 1+65=66-1=65
        //   because if remainder is 1 then it maps to 'A '
        // one edge case: if we get multiple of 26
        // remainder is 0 then we should add Z,
  string ans="";
    while(columnNumber>0){
        columnNumber--; 
        int remainder=columnNumber%26;
// ans+= remainder+'A'-1;//for remainder 0 we get 0+65-1=64 ie @
ans+=remainder+'A';

        columnNumber=columnNumber/26;
    }
    reverse(ans.begin(),ans.end());
    return ans;
// tc
    // log26(columnnumber)
    }
};