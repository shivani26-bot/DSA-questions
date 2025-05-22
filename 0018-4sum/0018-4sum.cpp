class Solution {
public:
vector<vector<int>>result;
void twoSum(vector<int>& nums,long long t,int s,int e,int n1, int n2){
     while(s<e){
        int currSum=nums[s]+nums[e];
        if(currSum>t){
            e--;
        }
        else if(currSum<t){
            s++;
        }
        else{
            while(s<e && nums[e]==nums[e-1]){
                e--;
            }
            while(s<e && nums[s]==nums[s+1]){
            s++;
            }
           result.push_back({n1,n2, nums[s],nums[e]});
            s++;
            e--;
        }
     }

}
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // vector<vector<int>>ans;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //      if(i>0 && nums[i]==nums[i-1]) continue;
        //     for(int j=i+1;j<nums.size();j++){
               
        //         if(j>i+1 && nums[j]==nums[j-1]) continue;
        //       else{ 
        //       long long fixed = static_cast<long long> (target) - (nums[i] + nums[j]);
        //         int p1=j+1,p2=nums.size()-1;
        //         while(p1<p2){
                    
        //             if(nums[p1]+nums[p2]<fixed) p1++;
        //             else if(nums[p1]+nums[p2]>fixed) p2--;
        //             else {
        //                 ans.push_back({nums[i],nums[j],nums[p1],nums[p2]});
        //                 if(nums[p1]==nums[p2]) break;
        //                 else{
        //                     int val1=nums[p1],val2=nums[p2];
        //                     while(p1<p2 && val1==nums[p1]) p1++;
        //                     while(p1<p2 && val2==nums[p2]) p2--;
        //                 }
        //             }
        //         }
        //       }
        //     }
        // }
        // return ans;


        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int n1=nums[i], n2=nums[j];
                long long t= static_cast<long long>(target)-(n1+n2);
                twoSum(nums,t, j+1, n-1, n1,n2);
            }
        }
        return result;
    }
};

// n1+n2+n3+n4=target
// n3+n4=target-(n1+n2)