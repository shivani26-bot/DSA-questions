class Solution {
public:
int n;
bool solve(vector<int>& nums, vector<int>&visited,int target, int idx, int curr_sum, int k){
  if(k==1) return true;
  if(idx>=n) return false;
       if(curr_sum==target) return solve(nums,visited,target,0,0,k-1) ;


    for(int j=idx;j<n;j++){
if(visited[j] || curr_sum+nums[j]>target) continue;
        visited[j]=true;
        if(solve(nums, visited, target, j+1,curr_sum+nums[j],k)) return true;
        visited[j]=false;
    }
    return false;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
          n=nums.size();
    int totalSum=0;

    for(int i=0;i<nums.size();i++){
        totalSum+=nums[i];
    } 
     
    if(n<k||  totalSum%k) return false;
    int target= totalSum/k;
    vector<int>visited(n,false);
    // ->>Why we need to sort the nums array in decreasing order
// : The ans for this is when we sort the array so we can exclude some unneccesory calculation for nums[j]+curr_sum>target
// Without sorting, we’d try [1,2,2], [2,3], [3,4], etc. Sorting ensures larger numbers are placed first so invalid branches (like 6 > 5) are cut early → less backtracking.
    sort(nums.begin(),nums.end(),greater<int>());
return solve(nums,visited,target,0,0,k);
    }
};