class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     ans.push_back(nums[i]);
        //     ans.push_back(nums[i+n]);
        // }
        // return ans;

        // vector<int>ans;
        // int i=0,j=n;
        // while(i<n && j<2*n){
        //     ans.push_back(nums[i++]);
        //     ans.push_back(nums[j++]);
        // }
        // return ans;

        // without extra space 

        // encode the nums array 
        // this will encode the nums array from index 0 to n-1 , from 0 to n-1 the ecoded form will have nums[i] and nums[i+n] in it
        for(int i=0;i<n;i++){
            // (we use 10000 because nums[i] ≤ 1000, so no overlap)
            nums[i]=nums[i]+nums[i+n]*10000;
        }
// decode the array and replace the elements with correct y and x pair 
int idx=2*n-1;//start from last of the array
// start from the half of the array and go till start of the array because in this range encoded form exists
for(int i=n-1;i>=0;i--){
    // extract y and x from the encoded form 
    int y=nums[i]/10000;
    int x=nums[i]%10000;

// first put y and then x
    nums[idx--]=y;
    nums[idx--]=x;
}
    return nums;
    }
};