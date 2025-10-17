class Solution {
public:
    int numberOfMatches(int n) {
//         int matches=0;
// //logn at each step n is divided by 2
//         while(n>1){
//             if(n%2==0){
//                 //even teams
//                 matches+=n/2;
//                 n=n/2;
//             }
//             else{
//                 matches+=(n-1)/2;
//                 n=(n-1)/2+1;
//             }
//         }
//         return matches;

// directly consider beginning and end of tournament 
// there are n teams, 1 winner, it means n-1 teams will be eliminated
// each match is played between 2 teams, one team wins one losses, each match eliminates exactly 1 team;
// hence n-1 teams will be eliminated , there will be n-1 matches played
return n-1;
    }
};