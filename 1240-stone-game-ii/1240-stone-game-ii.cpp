class Solution {
public:
// person=1 alice
// person=0 bob
// int solve(int index,int person, int m,vector<int>piles, int n)
// {
//     if(index>=n) return 0;
//     int stones=0;
//     int result=person==1? INT_MIN : INT_MAX;
 
//     // 0 1 2 3 4
//     // 1 2 8 3 5
//     //       i    n=5, m=2  we can only pick n-i elements from this index i
//     for(int x=1;x<= min(2*m,n-index);x++){
//         stones+=piles[index+x-1];
//         if(person==1){
//             //alice
//             result=max(result,stones+solve(index+x,0,max(m,x),piles,n));
//         }
//         else{
//             // bob
//             result=min(result,solve(index+x,1,max(m,x),piles,n));
//         }
//     }
//     return result;
// }    

// int stoneGameII(vector<int>& piles) {
//     //    initially  m=1, and we start game from alice
//     //    alice has options to take all the stomes from first x remaining piles
//     //    [2,7,9,4,4]
//     //    where 1 <= X <= 2M ie 1 <= X <= 2*1
//     //    hence alice has option to take all the stones 
//     //    from pile1 ie x=1 or pile1+pile2 ie x=2
//     //    after choosing the number of piles ie x, we update the m value to be
//     //    max(m,x piles choosen by alice) for next player bob
//     //    if alice choose number of piles greedily , that is if he chooses max number of piles that is x=2 then m=(m,x)
//  ie(1,2) =2 will be the value for bob, and then bob has options 1<=x<=2*2, hence bob will take all the remaining piles.
//     //    hence thinking greedily will not work and it will increase the chances for alice to loose.
//     //    hence if alice choose max number of x every time it will increase range of x for bob as well and bob 
// will end up having more number of options than alice

//     //    if m=1, alice turn , 1<=X<=2 and alice choose only 1st or one pile
//     //    m=max(1,1)=1, hence bob will have options in range  1<=X<=2*1
//     //    now if bob choose to pick 2 piles,then x=2, and m=max(1,2)=2
//     //    and alice has options in range 1<=x<=2*2, hence chance of alice to win will increase
//     //    A=2+4+4
//     //    B=2+7

   // // Game strategy questions falls in dp
  //  // when it's your turn , do your best 
  //  // when its your opponent's turn , expect the worst

// // if x=1, then index=index+x-1
// // when it's chance for alice it will try to do his best and collect stones from only 1 pile and next move will be given for bob
// // when  it's turn for bob, expect the minimum result from bob
// // we add stones value only when it's alice turns
// int n=piles.size();
// return solve(0,1,1,piles,n);
//      }

int dp[2][101][101];
int solve(int index,int person, int m,vector<int>piles, int n)
{
    if(index>=n) return 0;
    if(dp[person][index][m]!=-1) return dp[person][index][m];
    int stones=0;
    int result=person==1? INT_MIN : INT_MAX;

    for(int x=1;x<= min(2*m,n-index);x++){
        stones+=piles[index+x-1];
        if(person==1){
            //alice
            result=max(result,stones+solve(index+x,0,max(m,x),piles,n));
        }
        else{
            // bob
            result=min(result,solve(index+x,1,max(m,x),piles,n));
        }
    }
    return dp[person][index][m]=result;
}    

int stoneGameII(vector<int>& piles) {

int n=piles.size();
// here 3 variables are changing, person, index, m 
memset(dp,-1,sizeof(dp));
return solve(0,1,1,piles,n);
     }
};