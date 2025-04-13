class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int i=0,j=nums.size()-1;
        int n=nums.size();
        vector<int>ans;
        while(i<=j){
            
            int square_i= nums[i]*nums[i];
            int square_j= nums[j]*nums[j];
            if(square_i>=square_j){
                ans.push_back(square_i);
                     i++ ;
            }
            else{
                ans.push_back(square_j);
                 j--;
            }
        }
        vector<int>result(ans.rbegin(),ans.rend());
        return result;







         //    for(int i=0;i<nums.size();i++) {
    //        nums[i]=nums[i]*nums[i];
    //    }  
    //    sort(nums.begin(),nums.end());
    //    return nums;

//   int n=nums.size();
//   int i;
//         for( i=0;i<nums.size();i++){
//             if(nums[i]>=0) break;
//         }
//   int j=i-1;
//   vector<int>ans;
//   while(j>=0 && i<nums.size()){
//       if(abs(nums[i])<=abs(nums[j])){
//           ans.push_back(nums[i]*nums[i]);
//           i++;
//       }
//       else{
//           ans.push_back(nums[j]*nums[j]);
//           j--;
//       }
//   }

//   while(j>=0){
//       ans.push_back(nums[j]*nums[j]);
//       j--;
//   }
//   while(i<nums.size()){
//       ans.push_back(nums[i]*nums[i]);
//       i++;
//   }
//   return ans;
// int n=nums.size();
// vector<int>ans(n);
// int left=0,right=n-1;
// int ansPos=n-1;
// while(left<=right){
//     if(abs(nums[left])<=abs(nums[right])){
//         ans[ansPos]=nums[right]*nums[right];
//         ansPos--;
//         right--;
//  }
//  else{
//      ans[ansPos]=nums[left]*nums[left];
//         ansPos--;
//         left++;; 
//  }
// }
//  return ans;
    }
};