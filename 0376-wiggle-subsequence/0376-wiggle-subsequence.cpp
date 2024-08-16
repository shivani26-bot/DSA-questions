class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)  return nums.size();

int prev=nums[1]-nums[0];
int count= prev!=0 ? 2:1;

        for(int i=2;i<nums.size();i++){
            int curr=nums[i]-nums[i-1];
            if(prev<=0 && curr>0){
                count++;
                prev=curr;
            }
            else if(prev>=0 && curr<0){
                count++;
                prev=curr;
            }
        }
        return count;
    }
};