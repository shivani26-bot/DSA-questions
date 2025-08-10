class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int odd=0,count=0,countSubArray=0;
        while(j<n){
            if(nums[j]%2){ odd++;count=0;}
if(odd==k){
    while(odd==k){
        count+=1;
        if(nums[i]%2) odd--;
        i++;
    }
}
countSubArray+=count;
j++;
            
        }
        return countSubArray;
    }
};