class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n= nums.size();
        // int i=n-2;
        // while (i >= 0 &&  nums[i +1]<=nums[i] ) {
        //     i--;
        // }
        // if (i >= 0) {
        //     for (int j = n - 1; j > i; j--) {
        //         if (nums[j] >nums[i ]) {
        //             swap(nums[j], nums[i]);
        //             break;
        //         }
        //     }
          
        // }
        // reverse(nums.begin() + i + 1, nums.end());  


        int i=nums.size()-1;
        while(i>0&&nums[i]<=nums[i-1])
            i--;
        if(i-1>=0){
            
            for(int j=nums.size()-1;j>=i;j--){
                if(nums[j]>nums[i-1]){
                    swap(nums[j],nums[i-1]);
                    break;
                    
                }
            }
        }
        int l=nums.size()-1, k= i;
        while(k<l){
            swap(nums[k],nums[l]);
            k++;
            l--;
        }
        
    }
};
