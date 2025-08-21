class Solution {
public:
int n;

vector<vector<int>>result;
void solve(vector<int>& nums, int k, vector<int>temp, int idx, int prev){
if(idx>=n){
    // result.push_back(temp);
    return;
}
    for(int j=idx;j<n;j++){
        if(prev==-1 || (nums[j]-prev!=k)){
            temp.push_back(nums[j]);
            result.push_back(temp);
            solve(nums,k, temp,j+1,nums[j]);
            temp.pop_back();
        }
    }
}
    int beautifulSubsets(vector<int>& nums, int k) {
      n=nums.size();
      vector<int>temp;
      sort(nums.begin(),nums.end());
      solve(nums,k,temp,0,-1); 
      for(auto& vec:result){
        cout<<"[";
        for(auto& num:vec){
            cout<<num<<",";
        }
        cout<<"]";
      } 
      return result.size();
    }
};