class Solution {
public:
// total tc: o(n^2*n)
// space: o(n)
//o(n)
// int solve(int j, int k,vector<int>& arr,unordered_map<int,int>&mp ){
//     int target=arr[k]-arr[j];
//     if(mp.count(target) && mp[target]<j){
//         int i=mp[target];
//         return solve(i,j,arr,mp)+1;//1 is for kth element that will be included in ans
//     }
//     return 2; // 2 because if in case we don't have further elements i,j,k since k has already been counted, this is for i,j
// }

// //o(n^2)
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n=arr.size();
//     //    elements are in strictly increasing order, and unique we can store element->index in map, we will use map to find the index of 3rd element in the sequence
//     // also length>=3 only then its a valid sub-sequence
//     // i<j<k
//     // 3 5 8
//     // a+b=c=> c-b=a
//     // mp=> a->0, b->1,c->2 
// //     0  1  2
// //    {a, b, c}
// //     i  j  k

// // 1+ solve(j,k)=> 1+2=3
// //    c-b=a 0<1


// // solve(i,j) =>this will return 2 as there is no z a and b are last element
// // b-a=z
// unordered_map<int,int>mp;
// for(int i=0;i<n;i++){
//     mp[arr[i]]=i;
// }

// int result=0;
// for(int j=1;j<n;j++){
//     for(int k=j+1;k<n;k++){
//        int length=solve(j,k,arr,mp);
// if(length>=3){
//     result=max(result,length);
// }
//     }
// }
// return result;//will give max length fibonacci subsequence
//     }





    //memoization top down
//  0 1 2 3 4 5 6 7
// {1,2,3,4,5,6,7,8}
//    j k 
//  0 1 2 3 4 5 6 7
// {1,2,3,4,5,6,7,8}
//      j   k     ith index element =5-3=2, ith index=1 ie i<j
//  0 1 2 3 4 5 6 7
// {1,2,3,4,5,6,7,8}
//    i j   k             for dp[1][2] we have already stored the ans , the length of fibonacci ending at that index is 3 , we can use the stored ans
//    dp[j][k]=dp[1][2]=3 length of fibonacci at index 1,2
    
    // dp[j][k]=> length of fibonacci sequence ending at index j,k 
//     int solve(int j, int k,vector<int>& arr,unordered_map<int,int>&mp,vector<vector<int>>&dp ){
//     if(dp[j][k]!=-1) return dp[j][k];
//     int target=arr[k]-arr[j];
//     if(mp.count(target) && mp[target]<j){
//         int i=mp[target];
//     dp[j][k]= 1+solve(i,j,arr,mp,dp);
//     return dp[j][k];
//     }
//     return dp[j][k]=2; 
// }

// //o(n^2)
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n=arr.size();
// unordered_map<int,int>mp;
// vector<vector<int>>dp(n,vector<int>(n,-1));
// for(int i=0;i<n;i++){
//     mp[arr[i]]=i;
// }

// int result=0;
// for(int j=1;j<n;j++){
//     for(int k=j+1;k<n;k++){
//        int length=solve(j,k,arr,mp,dp);
// if(length>=3){
//     result=max(result,length);
// }
//     }
// }
// return result;//will give max length fibonacci subsequence
//     }











// bottom up tabulation
// state definition
// t[i][j]= max length of fibonacci like sequence ending at i,j




//o(n^2)
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
unordered_map<int,int>mp;
vector<vector<int>>dp(n,vector<int>(n,2));
//when we only have 2 element and we don't find further element, 2 is base caseatleast 2 elements must be there, because fibonacci length>=3
for(int i=0;i<n;i++){
    mp[arr[i]]=i;
}

int result=0;
for(int j=1;j<n;j++){
    for(int k=j+1;k<n;k++){
        int target= arr[k]-arr[j];
         if(mp.count(target) && mp[target]<j){
        int i=mp[target];
    dp[j][k]= 1+dp[i][j];
    }
//    int length=dp[j][k];
// if(length>=3){
//     result=max(result,length);
// }
result=max(result,dp[j][k]);

    }
}
// return result;//will give max length fibonacci subsequence
return result>=3?result:0;
    }
};