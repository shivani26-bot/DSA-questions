class Solution {
public:
    // int subsetXORSum(vector<int>& nums) {
    //    int n=nums.size();
    //    int totalSum=0;
    //    for(int i=0;i<=(1<<n);i++){
    //     int subsetXor=0;
    //     for(int j=0;j<n;j++){
    //         int mask=(1<<j);
    //         if(i&mask) subsetXor^=nums[j];
    //     }
    //     totalSum+=subsetXor;
    //    }
    //    return totalSum;
    // }


    //backtracking
    int n;
    void generateSubsets(vector<int>& nums,int i, vector<int>subset,vector<vector<int>>&subsets){
if(i>=n){
    subsets.push_back(subset);
    return;
}

        subset.push_back(nums[i]);//push the element
        generateSubsets(nums,i+1, subset,subsets);//move to next index
        // once reached the end index pop back the element from end 
        subset.pop_back();
        //subset without current element
        generateSubsets(nums,i+1,subset,subsets);//pop back the element and move forward without taking the current element nums[i];


    }
     int subsetXORSum(vector<int>& nums) {
        n=nums.size();
       vector<vector<int>>subsets;
      //generate all the subsets
      generateSubsets(nums,0,{},subsets);
      int result=0;
      for(auto& subset: subsets){
        int totalSubsetXOR=0;
        for(int num:subset){
            totalSubsetXOR^=num;
        }
        result+=totalSubsetXOR;
      }
      return result;
    }
};