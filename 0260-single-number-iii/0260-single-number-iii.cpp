class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    int n=nums.size();
    int totalXor=0;
    for(int i=0;i<n;i++){
//find the total xor of entire array, final xor will give the xor of 2 different elements present in array
totalXor^=nums[i];
    }

    // now find the first bit in totalXor where the bit in 2 different elements differs, if bit is 1 in totalXor it means bits in 2 elements at that position was different ie 0 or 1
long mask=1;
// left shift the mask by 1 position if current bit is 0 which means same bits in 2 different element 
while(!(mask & totalXor)) mask<<=1;

// to find the first different element and the entire array with mask if same bit in nums[i] and mask gives 1 it means it can be the answer xor the nums[i] with val1 , if that element is present it will cancel out later other wise it will be the answer 
int val1=0;
for(int i=0;i<n;i++){
    if(nums[i] & mask) val1^=nums[i];

}
int val2= totalXor^val1;
vector<int>ans(2,0);
ans[0]=val1;
ans[1]=val2;
return ans;
    }
};