class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int>ans(n,0);

int j=0;
if(n%2==0){
for(int i=0;i<n/2;i++){
    if(j>=n) break;
    ans[j]=nums[i];
    j+=2;
}
j=1;
for(int i=n/2;i<n;i++){
     if(j>=n) break;
    ans[j]=nums[i];
    j+=2;
}
}
else{
    for(int i=0;i<=n/2;i++){
    if(j>=n) break;
    ans[j]=nums[i];
    j+=2;
}
j=1;
for(int i=n/2+1;i<n;i++){
     if(j>=n) break;
    ans[j]=nums[i];
    j+=2;
}
}
return ans;
    }
};

// [4,3,6,7,9]
// output: [6,3,7,4,9]