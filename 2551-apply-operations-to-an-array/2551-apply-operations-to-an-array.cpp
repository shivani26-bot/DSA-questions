class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
           if(i<n-1 && nums[i]==nums[i+1]){
            nums[i]*=2;
            nums[i+1]=0;
            i++;
           }
          i++;
        }
        for(int i=0;i<n;i++)
        cout<<nums[i];
        int j=0,k=0;
        while(k<n){
            if(nums[k]!=0){
             swap(nums[j],nums[k]);
             j++;
            }
            k++;
        }
        return nums;
    }
};