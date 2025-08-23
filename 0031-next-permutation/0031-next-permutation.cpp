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

// [1,2,3]=>lexicographical permutation
// [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,1,2] [3,2,1] , no next permutation for [3,2,1] return the first array :[1,2,3]

// for current element find the largest to it's right swap with it and reverse the right part 

// first find the candidate from the right side where nums[i]>nums[i-1]
// [1,3,4,5,2]=> here 4 is the candidate, 5 is just greater than 4 , [1 3 5 2 4]
        int i=nums.size()-1;
        while(i>0&&nums[i]<=nums[i-1]) //choose i-1 as candidate to swap
            i--;
        if(i-1>=0){
            //swap the element on index i, with the largest element on the right
            for(int j=nums.size()-1;j>=i;j--){
                if(nums[j]>nums[i-1]){
                    swap(nums[j],nums[i-1]);
                    break;
                    
                }
            }
        }

        //reverse the right part
        int l=nums.size()-1, k= i;
        while(k<l){
            swap(nums[k],nums[l]);
            k++;
            l--;
        }
        

        //next_permutation(begin(nums),end(nums));
    }
};
