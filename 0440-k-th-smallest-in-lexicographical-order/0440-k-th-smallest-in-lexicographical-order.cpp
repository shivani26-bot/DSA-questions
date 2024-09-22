class Solution {
public:
// tle current solution is in o(n) hence solve in o(logn)
// int ans=0;
//         int count=0;
// void dfs(long long int i, int n,int k){
//     if(i>n) return; 
//        count++;
//     if(count==k) {
//        ans=i;
//         return;
//     }
     
//     for(int j=0;j<=9;j++){
//         if(i*10+j>n) break;
//        dfs(i*10+j,n,k);
//     }
// }
//     int findKthNumber(int n, int k) {
        
//     for(long long int i=1;i<=9;i++){
//         // cout<<count<<endl;
      
//         dfs(i,n,k);
//          if(count>=k) break;
//     }
//         return ans;
//     }

    // memory limit exceeded 
// void dfs(int i, int n, vector<int>&ans){
//     if(i>n) return; 
//     ans.push_back(i);
//     for(int j=0;j<=9;j++){
//     int newNum=i*10+j;
//     if(newNum>n) return ;
//        dfs(newNum,n,ans);
//     }
// }
//  int findKthNumber(int n, int k) {
// vector<int>ans;
// for(int i=1;i<=9;i++){
//         dfs(i,n,ans);
//         }
//        return ans[k-1];
//     }

// optimized 
// n=22,k=14
// 1-> 1,10,11,12,13,14,15,16,17,18,19
// start from 1, and count prefixes starting from 1 and that is less than n
// hence count is 11, hence none of the prefixes are kth required prefix 
// and hence we can skip all these numbers 
// 2-> 2,20,21 
// 14th number is 21 
// if we skip few numbers then we can possibly optimise our approach 

int countSteps(int n, long long int currStart, long long int nextStart ){
   int stepsToSkip=0;
while(currStart<=n){ // no point of going further once currStart > n, now we should move the currPrefix to 2 and nextPrefix to 3
    stepsToSkip += min((long long int)(n + 1), nextStart) - currStart;
    // 2-1 formula to find the difference between number of steps that can be skipped
   currStart*=10; // go to next level for currPrefix=1 next level will start from 10
   nextStart*=10; // go to next level for nextPrefix=2 next level will start from 20
}
   return stepsToSkip;
}
    int findKthNumber(int n, int k) {
//    1st level->         1                                  2                       3         4            5...................
//  2nd level->10,11,12,13,14,15,16,17,18,19    20,21,22,23,24,25,26,27,28,29
                    //  10
// 3rd level->100,101,102,103,104,105,106,107,108,109
         int curr=1;
k--; // as we start from first number 1, we need k-1 more numbers
        //  lets suppose we start from 1 count number of steps we can skip use currPrex=1 and nextPrefix=2 ie currPrefix+1
        while(k>0){
         int countStepToSkip= countSteps(n, curr,curr+1);
         if(countStepToSkip<=k){
            curr++;
            k-=countStepToSkip;
         }
         else{
            // it means we will get the kth number in the currPrefix series only 
            curr*=10; //10,11,12,13,14,15,16,17,18,19
            k--;

         }
        }
        return curr;
    }
    
};