class Solution {
public:
// int solve(vector<int>&dp, int n){
//     if(n<=1) return 1;

//     if(dp[n]!=-1) return dp[n];
//     int ans=0;
//     for(int i=1;i<=n;i++){
//        ans+=solve(dp,i-1)*solve(dp,n-i);
//     }
//     return dp[n]=ans;
// }
int solve(vector<int>&dp, int n){
    if(n<=1) return 1;
dp[0]=1;
dp[1]=1;

    int ans=0;
    // number of nodes 
    for(int i=2;i<=n;i++){
        // parent node
        for(int j=1;j<=i;j++){
dp[i]+=dp[j-1]*dp[i-j];
        }
      
    }
    return dp[n];
}
//     int numTrees(int n) {
//         // in a given binary search tree, if there is root and total 4 different structurally bst are possible for left node and 
//         // total 5 different structurally bst are possible for right node then total number of structurally different bst will be
//         // 5*4=20
//         // if n=3 , then possible root nodes are 1,2,3
//         // for root =1, node(2,3) lies on the right of the root
//         // for root =2, node 1 lies on the left of the root and 3 on the right of the root
//         // for root =3, node(1,2) lies on the left of the root
//         // if number of node=0 or 1 then possible number of structurally unique bst will be 1, base case
//         // if we have n nodes
//         // then there are possiblities of n roots
//         // 1->root
//         // 2->root
//         // 3->root
//         // .
//         // .
//         // .
//         // i->root
//         // .
//         // .
//         // .
//         // n->root
//         // if we choose i as root then nodes from 1 to i-1 will lie on left side of the i
//         // and nodes from i+1 to n will lie on right side of the i
//         // hence lhs contains i-1 nodes and rhs contains n-i nodes
//         // hence total unique structure will be (n-i)*(i-1)
//         // hence f(n)=f(n-i)*f(i-1)
//         // f(n)= summation of (f(n-i)* f(i-1))
        

// // if(n<=1) return 1;
// // int ans=0;
// // // every node will be root at a time 
// //         for(int i=1;i<=n;i++){
// //  ans+=numTrees(i-1)*numTrees(n-i);
// //         }
// //         return ans;


// // top down 
// // vector<int>dp(n+1,-1);
// // return solve(dp,n);

// // bottom up
// // vector<int>dp(n+1,0);
// // return solve(dp,n);

// // catalan numbers 
// if(n<=1) return 1;
// long long catalan=1;
// for(int i=0;i<n;i++){
//     catalan=catalan*2*(2*i+1)/(i+2);
// }
// return static_cast<int>(catalan);
//     }





int numTrees(int n) {
// n represent number of nodes 
// n=0 nodes
// n=1 nodes
if(n<=1) return 1;
// in bst if i is the root node then 1 to i-1 lie in lhs and i+1 to n lie in rhs
  int ans=0;
   for(int i=1;i<=n;i++){
    // lhs has i-1 nodes, rhs has n-i nodes 
    ans+=numTrees(i-1) * numTrees(n-i);
   }
   return ans;
    }
};


// answer follows the following pattern 
// n=0 -> ans=1
// n=1 -> ans=1
// n=2 -> ans=2
// n=3 -> ans=5
// n=4 -> ans=14
// catalan numbers 


