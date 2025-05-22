class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
         int n=nums.size();
         sort(nums.begin(),nums.end());
        int i=0,j=1;
        int ans=0;
        int currDiff;
        while(j<n){
             currDiff= abs(nums[i]-nums[j]);
             if(currDiff < k){
                j++;
             }
             else if(currDiff > k){
                i++;
                if(i==j) j++;
             }
             else{
                 
                     ans++;
                   
                    while(j<n-1 && nums[j]==nums[j+1]){
                     
                        j++;
                    }
                     while(i<n-1 && nums[i]==nums[i+1]){
                     
                        i++;
                    }
                   
                    j++;
             }
        
        }
        return ans;
    }
};