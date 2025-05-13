class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
int n=nums.size();
int i=0,j=0;
int ans=INT_MAX;
while(j<n){

if(j-i+1<k){
    j++;
}
else if(j-i+1==k){
    int lowest= nums[i];
    int highest= nums[j];
    int diff= nums[j]-nums[i];
    ans=min(ans,diff);
    i++;
    j++;
}
}
return ans;
    }
};