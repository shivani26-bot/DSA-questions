class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // int n=nums.size();
        //  for(int i=0;i<n-1;i++){
        //         if((nums[i]%2==0 && nums[i+1]%2==0) || (nums[i]%2!=0 && nums[i+1]%2!=0)) {
        //            return false;
        //         }
               
        //     }
        //     return true;
int n=nums.size();
// odd+odd=even
// even+even=even
// odd+even=odd
        vector<int>prefixSum(n);
        if(n==1){
            return true;
        }
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++ ){
             prefixSum[i]=nums[i]+prefixSum[i-1];
        }
         int sum;
       for(int i=1;i<n;i++){
        if(i-2>=0)
          sum=prefixSum[i]-prefixSum[i-2];
          else sum=prefixSum[i];
          if(sum%2==0) return false;
          
       }
       return true;
    }
};