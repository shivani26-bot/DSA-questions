class Solution {
public:
// int helper(vector<int>&sums,int index,int count,int k,vector<int>&result){
//     if(count==0) return 0;
//           if(index>=sums.size()) return INT_MIN;
//           int take= sums[index]+helper(sums,index+k,count-1,k,result);
//           int not_take=helper(sums,index+1,count, k, result);
//           return max(take,not_take);
// }
// void solve(vector<int>&sums,int index,int count,int k,vector<int>&result)
//   {   
//           if(count==0) return ;
//           if(index>=sums.size()) return;
//           int take= sums[index]+helper(sums,index+k,count-1,k,result);
//           int not_take=helper(sums,index+1,count, k, result);
//           if(take>=not_take){
//             result.push_back(index);
//             solve(sums, index+k,count-1,k,result);
//           }
//           else{
//             solve(sums,index+1,count,k, result);
//           }
//   }
//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
// //         [1,2,1,2,6,7,5,1]
// //          0 1 2 3 4 5 6 7
// //         [1,2,1,2,6,7,5,1]  ={3,8,12}  return this as answer because of lexically smaller index
// //         ----   --- ---  
// //         [1,2,1,2,6,7,5,1]={3,8,12}
// //            --- --- ---
// //        we only have to find 3 subarrays , hence size of nums must be >= 3*k
// //     if we stand at index i, then next subarray starts from index =i+k 
// // at any given index we have two options: 
// // i-> start subarray of size==k
// //     not start subarray 

//     // maintain a total sum , the path that will give maximum total sum will help to determine that from which index we should start 
//     // if in case we get same maximum total sum from more than one path then consider the path whose starting index is lexically smaller 
// //   it's impossible that we write logic for building index array and as well as deciding that whethere the particular inde should be the start of the 3 subarrays non overlapping or not-> that will be so messy
// //   we will make two function, one will build the index for us, other will tell us whether to start from that index or not based on total sum for that path 
// // solve() - decide whether to start subarray from that index or not
// // and helper() ->find the total sum for every decision taken in solve() 
// // decides what will be the total sum if we start from current index  
// // count=3, as we only have to find 3 subarray

// // helper(i,count){
// //     if(count==0) return 0;//no subarray, return sum as 0
// //     if(i>=n) {//count!=0 but i>=n
// //         //index out of bound;
// //         return INT_MIN;//invalid case
// //     }
// //     int take= subarray(i,k)+helper(i+k,count-1);
// //     int not_take=helper(i+1,count);
// //     return max(take, not_take);
// // }
// // solve(count,i){
// // if(count==0) return;
// // if(i>=n) return ;

// // // subarray(i,k)-> finds the sum of subarray of length k starting from i
// // int take= subarray(i,k)+helper(i+k,count-1);
// // int not_take=helper(i+1,count);
// // if(take>=not_take){
// //     result.push_back(i);
// //     solve(count-1,i+k)
// // }
// // else solve(count, i+1)
// // }

// // to find subarray sum of size k starting from index i, use sliding window
// vector<int>sums;//contains sum of subarray of size k for every index i from 0 to nums.size()-k+1
// int i=0,j=0;
// int windowSum=0;
// while(j<nums.size()){
//     windowSum+=nums[j];

//     if(j-i+1==k){
//         sums.push_back(windowSum);
//         windowSum-=nums[i];
//         i++;
//     }
//     j++;
// }

// vector<int>result;
//  solve(sums,0,3,k,result);
// return result;

//     }

  int dp[20001][4];
  int helper(vector<int>&sums,int index,int count,int k,vector<int>&result){
    if(count==0) return 0;
          if(index>=sums.size()) return INT_MIN;

          if(dp[index][count]!=-1) return dp[index][count];
          int take= sums[index]+helper(sums,index+k,count-1,k,result);
          int not_take=helper(sums,index+1,count, k, result);
          dp[index][count]=max(take,not_take);
          return dp[index][count];
}
void solve(vector<int>&sums,int index,int count,int k,vector<int>&result)
  {   
          if(count==0) return ;
          if(index>=sums.size()) return;
          int take= sums[index]+helper(sums,index+k,count-1,k,result);
          int not_take=helper(sums,index+1,count, k, result);
          if(take>=not_take){
            result.push_back(index);
            solve(sums, index+k,count-1,k,result);
          }
          else{
            solve(sums,index+1,count,k, result);
          }
  }
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    memset(dp,-1,sizeof(dp));
vector<int>sums;//contains sum of subarray of size k for every index i from 0 to nums.size()-k+1
int i=0,j=0;
int windowSum=0;
while(j<nums.size()){
    windowSum+=nums[j];

    if(j-i+1==k){
        sums.push_back(windowSum);
        windowSum-=nums[i];
        i++;
    }
    j++;
}

vector<int>result;
 solve(sums,0,3,k,result);
return result;

    }
  
};