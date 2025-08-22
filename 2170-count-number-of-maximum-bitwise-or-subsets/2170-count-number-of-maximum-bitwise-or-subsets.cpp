class Solution {
public:
int n;
int solve(vector<int>&nums, int idx,int currOr,int targetOr){
if(idx==n){
    return currOr==targetOr?1:0;
}

int take=solve(nums,idx+1,currOr|nums[idx],targetOr);
int notTake=solve(nums,idx+1,currOr, targetOr);
return take+notTake;
}
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int maxOr=0;
        for(int num:nums){
            maxOr|=num;
        }
        return solve(nums,0,0,maxOr);
    }
};


// class Solution {
// public:
// // n*2^n
//     int countMaxOrSubsets(vector<int>& nums) {
//             int n=nums.size();
		    
// int subsets=(1<<n) ;///2^n subsets
// int x=0;
// int max_or=INT_MIN;
// vector<int>maxm_or;
// unordered_map<int,int>mp;
// 		    for(int num=1;num<(1<<n);num++){ //o(2^n-1)
// 		  x=0;
// 		        for(int i=0;i<n;i++){ //o(n)
                  
// 		            if(num&(1<<i))
// 		            x|=nums[i];
		            
// 		        }
// 		        cout<<x<<endl;
//                 if(x>max_or){ //o(1)
//                     max_or=x;
//                     // cout<<max_or<<endl;
//                     maxm_or.push_back(max_or);
//                 }
//                 // max_or=max(max_or, x);
//                 // mp[max_or]++;
//                 mp[x]++; //o(1)
//                 // cout<<max_or<<endl;
// 		    }
//             //o(n)
//             int maxm=*max_element(maxm_or.begin(),maxm_or.end());
//         // cout<<maxm<<endl;
// 	      return mp[maxm]; //o(1)
// 		    // return 0;
//     }
// };

// //Acceptable Time Complexities
// //O(n!)
// //O(2^n) or \U0001d442(3^\U0001d45b) are acceptable since 
// // 2^16=65536and 3^16≈43×10^6 which are feasible for typical competitive programming limits.
// // O(n^2),O(nlogn), O(n)