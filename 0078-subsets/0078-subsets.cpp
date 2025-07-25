// class Solution {
// public:
// int n;
//  vector<vector<int>>ans;
// void solve(int i,vector<int>subset,vector<int>& nums){
// if(i>=n){
//     ans.push_back(subset);
//     return;
// }
// subset.push_back(nums[i]);
// solve(i+1, subset, nums);
// subset.pop_back();
// solve(i+1,subset,nums);


// }
//     vector<vector<int>> subsets(vector<int>& nums) {
//          n=nums.size();
//         solve(0,{},nums);
//         return ans;
//     }
// };


class Solution {
public:
// if we have nums of size : 3 then there will be 2^3 subsets 
// as we know that if we have n elements then there are 2^n subsets formed by that
// element
// 3 size means 3 bit,  2 1 0            we have array as [1,2,3]
//                      0 0 0       []                     0 1 2
//                      0 0 1       [1]
//                      0 1 0       [2]
// (8 subsets)          0 1 1       [1,2]
//                      1 0 0       [3]
//                      1 0 1       [1,3]
//                      1 1 0       [2,3]
//                      1 1 1       [1,2,3]
//  carefully look at the bits and the index of the array
// the bits that are set indicates the array index to include in the subset
// hence we will iterate from 0 to 2^n and we have to check n bits of each binary
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();
        for(int i=0;i< (1<<n);i++){
     vector<int>subset;
            for(int j=0;j<n;j++){
                int mask=1<<j;
                if(i&(mask)) subset.push_back(nums[j]);
            }
            result.push_back(subset);
        }
        return result;
    }
};



// class Solution {
// public:

// void printsubset(vector<int>& nums, int n, int index, vector<int>& temp, vector<vector<int>>& result) {
//     // if (i == n) {
//     //     result.push_back(temp);
//     //     return;
//     // }

//         result.push_back(temp);
       
//     for(int i=index;i<nums.size();i++){
//          temp.push_back(nums[i]);
//           printsubset(nums, n, i + 1, temp, result);
//            temp.pop_back();
//     }
   
// }

// vector<vector<int>> subsets(vector<int>& nums) {
//     vector<vector<int>> result;
//     vector<int> temp;
//     int n = nums.size();
//     printsubset(nums, n, 0, temp, result);
//     return result;
// }

// };
 