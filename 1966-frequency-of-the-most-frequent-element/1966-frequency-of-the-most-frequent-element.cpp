// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//         int i=0,j=0, n=nums.size();
//         long currSum=0;
//         sort(nums.begin(),nums.end());//sorting such that always the last element of the window will be max element
        
//         long requiredTotalInWin=0;
//         int maxWin=INT_MIN;
//         while(j<n){
//             currSum+=nums[j];

//             long maxEleInWin=nums[j];
//             requiredTotalInWin= maxEleInWin*(j-i+1);
   
//         if(requiredTotalInWin-currSum>k){
                
//                 currSum-=nums[i];
//                 i++;
           
//             }
//             maxWin= max(maxWin, j-i+1);
//             j++;

//         }
//         return maxWin;
//     }
// };

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i=0,j=0, n=nums.size();
        long currSum=0;
        sort(nums.begin(),nums.end());//sorting such that always the last element of the window will be max element
        

        int maxWin=INT_MIN;
        while(j<n){
            currSum+=nums[j];

            long maxEleInWin=nums[j];
           
   
        while(maxEleInWin*(j-i+1)-currSum>k){
                
                currSum-=nums[i];
                i++;
           
            }
            maxWin= max(maxWin, j-i+1);
            j++;

        }
        return maxWin;
    }
};