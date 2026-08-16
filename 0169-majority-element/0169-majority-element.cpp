class Solution {
public:
    int majorityElement(vector<int>& nums) {
//    o(n)
	// 	int n=nums.size();
    //     int count=1;
    //     int candidate=nums[0];
    //     for(int i=1;i<n;i++){
    //         if(nums[i]==candidate) count++;
    //         else{
    //             count--;
    //             if(count==0){
    //                 candidate=nums[i];
    //                 count=1;
    //             }
    //         }
    //     }
    // count=0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==candidate) count++;
    //     }
    //     if(count>n/2) return candidate;
    //     return -1;


// The "more than n/2 times" condition has a useful consequence. The majority element occupies more than half the array, so no other element can also appear more than n/2 times. The majority element is therefore unique.
int n= nums.size();
    sort(nums.begin(), nums.end());

    return nums[n/2];

		}
    
};