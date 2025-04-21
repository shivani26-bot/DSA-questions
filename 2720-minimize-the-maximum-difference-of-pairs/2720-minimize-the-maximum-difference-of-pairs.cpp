class Solution {
public:
int n;
bool isPossible(vector<int>& nums, int p,int mid){
    int actualPairs=0;
   for(int i=0;i<n-1;i++) {

        if(abs(nums[i]-nums[i+1])<=mid) {actualPairs++;i++;}
    }
   
   return actualPairs>=p;
}
    int minimizeMax(vector<int>& nums, int p) {
        n=nums.size();
        sort(nums.begin(),nums.end());

        int low=0, high=nums[n-1]-nums[0];
        int result=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,p,mid)){
                result=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return result;
    }
};