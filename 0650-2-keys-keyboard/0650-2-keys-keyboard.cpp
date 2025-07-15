class Solution {
    // n=15
    // output:8
public:
// here we can't only take copy and paste options, because when we try to only copy then we get stuck in infinite loop 
// due to repition of same state as previous 
// int solve(int currA, int clipA, int n){
//     if(currA==n) return 1;
//     if(currA>n) return 100000; //invalid Case
//     // when we copyAll then how many A's will come in the clip board other than already existing
//     int copyAllPaste= 2+solve(currA+currA,currA,n);
//     // here we are not copying anything hence clipA remains same 
// int paste= 1+solve(currA+clipA,clipA,n);

// return min(copyAllPaste,paste);
// }
//     int minSteps(int n) {
//     //    we have two possibility , copyall+paste and paste
//     //    take the minimum of both
//     // initially we have to copy for the first time to make further operations possible
// // maintain currA value and clipBoard value
// if(n==1) return 0; //we already have 1 'A' in the notepad
// // number of A's currently , number of A on clip board,
//    return solve(1,1,n);
//     }


int solve(int currA, int clipA, int n){
    if(currA==n) return 0;//no operation required further
    if(currA>n) return 100000; //invalid Case
    // when we copyAll then how many A's will come in the clip board other than already existing
    int copyAllPaste= 2+solve(currA+currA,currA,n);//2operations
    // here we are not copying anything hence clipA remains same 
int paste= 1+solve(currA+clipA,clipA,n);//one operation

return min(copyAllPaste,paste);
}
    int minSteps(int n) {
    //    we have two possibility , copyall+paste and paste
    //    take the minimum of both
    // initially we have to copy for the first time to make further operations possible
// maintain currA value and clipBoard value
if(n==1) return 0; //we already have 1 'A' in the notepad
// number of A's currently , number of A on clip board,
   return 1+solve(1,1,n);
    }




};