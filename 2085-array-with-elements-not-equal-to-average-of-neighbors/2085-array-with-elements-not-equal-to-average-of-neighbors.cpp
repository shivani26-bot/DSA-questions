class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
//     int n=nums.size();
//     sort(nums.begin(),nums.end());
//     vector<int>ans(n,0);

// int j=0;
// if(n%2==0){
// for(int i=0;i<n/2;i++){
//     if(j>=n) break;
//     ans[j]=nums[i];
//     j+=2;
// }
// j=1;
// for(int i=n/2;i<n;i++){
//      if(j>=n) break;
//     ans[j]=nums[i];
//     j+=2;
// }
// }
// else{
//     for(int i=0;i<=n/2;i++){
//     if(j>=n) break;
//     ans[j]=nums[i];
//     j+=2;
// }
// j=1;
// for(int i=n/2+1;i<n;i++){
//      if(j>=n) break;
//     ans[j]=nums[i];
//     j+=2;
// }
// }
// return ans;

// sort(nums.begin(),nums.end());
// vector<int>ans;
// int n=nums.size();
// int i=0,j=n-1,flag=true;
// while(i<=j){
//     ans.push_back(flag ?  nums[i++]:nums[j--]);
//     flag=!flag;
// }
// return ans;


int n=nums.size();
for(int i=1;i<n-1;i++){
    int avg= (nums[i-1]+nums[i+1]);
    if(2*nums[i] == avg){
          swap(nums[i],nums[i+1]);
    }
}
for(int i=n-2;i>0;i--){
    int avg= (nums[i-1]+nums[i+1]);
    if(2*nums[i] == avg){
          swap(nums[i],nums[i-1]);
    }
}
return nums;
    }
};

// [4,3,6,7,9]
// output: [6,3,7,4,9]