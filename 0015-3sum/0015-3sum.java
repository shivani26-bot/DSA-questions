class Solution {
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> threeSum(int[] nums) {

Arrays.sort(nums);
int n=nums.length;

// num[i]+nums[j]+nums[k]=0
// num[i]+nums[j]=-nums[k]
for(int i=0;i<n-2;i++){
    if(i>0 && nums[i]==nums[i-1]) continue;

    int target= -nums[i];
    // apply two sum in range, i+1 to n
    twoSum(nums, i+1, n-1, target);
}
return result;

    }

    private void twoSum(int[] nums, int s, int e, int target){

        while(s<e){
            int currSum= nums[s]+nums[e];
            if(currSum<target){
                s++;
            } else if(currSum>target){
                e--;
            }else{
                while(s<e && nums[s]==nums[s+1]){ //avoid duplicates
                    s++;
                }
                   while(s<e && nums[e]==nums[e-1]){ //avoid duplicates
                    e--;
                }
                result.add(Arrays.asList(nums[s],nums[e],-target));
                s++;
                e--;
            }

        }
    }
}