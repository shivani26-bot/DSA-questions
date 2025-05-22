class Solution {
public:
vector<vector<int>>result;
void twoSum(vector<int>& nums,int target,int s,int e){
     while(s<e){
        int currSum=nums[s]+nums[e];
        if(currSum>target){
            e--;
        }
        else if(currSum<target){
            s++;
        }
        else{
            while(s<e && nums[e]==nums[e-1]){
                e--;
            }
            while(s<e && nums[s]==nums[s+1]){
            s++;
            }
           result.push_back({-target, nums[s],nums[e]});
            s++;
            e--;

        }
     }
  
}
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>> ans;
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(i>0 && nums[i]==nums[i-1]) continue;
        //     else{
        //         int fixed= -1*(nums[i]);
        //         int p1=i+1,p2=nums.size()-1;
        //         while(p1<p2){
        //             if(nums[p1]+nums[p2]<fixed) p1++;
        //             else if(nums[p1]+nums[p2]>fixed) p2--;
        //             else{
        //                 ans.push_back({nums[i],nums[p1],nums[p2]});
        //                 if(nums[p1]==nums[p2]) break;
        //                 else{
        //                     int val1=nums[p1],val2=nums[p2];
        //                     while(p1<p2 && nums[p1]==val1) p1++;
        //                     while(p1<p2 && nums[p2]==val2) p2--;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return ans;

        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int n1=nums[i];
            int target=-n1;
            twoSum(nums,target,i+1,n-1);
           
        }
         return result;
    }
};


// n1+n2+n3=0
// n2+n3=-n1
// sort the array
// [-1,0,0,1,2,2]
// fix index=0 as n1 and in the remaining array from index =1 to5 apply 2 sum to find 
// two elements whose sum is = -(n1)
// follow the same steps for every index 

// target=-n1