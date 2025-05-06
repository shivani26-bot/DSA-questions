class Solution {
public:
int n;
bool isPossibleDivisor(vector<int>& nums, int threshold,int m){
int requiredSum=0;
for(int i=0;i<n;i++){
    int dividend=ceil(static_cast<double>(nums[i])/m);
    requiredSum+= dividend;
}
return requiredSum<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        n=nums.size();
         int l=1,h=*max_element(nums.begin(),nums.end());
         int result=0;
         while(l<=h){
            int m=l+(h-l)/2;
            if(isPossibleDivisor(nums,threshold,m)){
                result=m;
                h=m-1;
            }
            else l=m+1;
         }
         return result;
    }
};