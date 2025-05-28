class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
    vector<int>ans(n);
   int posIndex=0, negIndex=1;
   int i=0;
   while(i<n){
    if(nums[i]>0){
        ans[posIndex]=nums[i];
        i++;
        posIndex+=2;
    }
    else{
        ans[negIndex]=nums[i];
        negIndex+=2;
        i++;
    }
   }
   return ans;



    // vector<int>positive;
    //     vector<int>negative;
    //     for(int i=0;i<nums.size();i++) {
    //         if(nums[i]<0) negative.push_back(nums[i]);
    //         else positive.push_back(nums[i]);
    //     }
    //     int i=0, j=0;
    //     int n=positive.size();
    //     int m= negative.size();
    //     vector<int>ans;
    //     while(i<n || j<m) {
    //     ans.push_back(positive[i]);
    //     ans.push_back(negative[i]);
    //     i++;
    //     j++;
    //     }
    //     return ans;
    }
};