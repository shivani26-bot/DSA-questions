class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // [9,9,9,1,2,3]
        // 3
        int n=nums.size();
        int i=0,j=0;
        int maxAns=0;
        int sum=0;
        unordered_set<int>st;
        while(j<n){
            
            st.insert(nums[j]);
            
            sum+=nums[j];
          
            if(j-i+1<k) j++;
            else {
                if(st.size()==k)
                maxAns=max(maxAns,sum);
                  st.erase(nums[i]);
                sum-=nums[i];
              
                i++;
j++;
            }
        }
        return maxAns;
    }
};