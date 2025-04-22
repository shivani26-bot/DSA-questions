class Solution {
public:
// 17 mid val=4
// how many operation req to bring a number to mid value 17 to 4, 4operations
//  17
// 4  13
//   4   9
//      4   5
//         4  1

// 16 mid val=4 , 3 operations
// 16
// 4  12
//   4   8
//      4  4
bool possible(vector<int>&nums, int maxOperations, int mid){
         long long totalOperations=0;
         for(auto num: nums){
            int requiredOperations= num/mid;
            if(num%mid==0){
                requiredOperations-=1;
            }

            totalOperations+=requiredOperations;
         }
         return totalOperations<=maxOperations;

}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(nums, maxOperations, mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};