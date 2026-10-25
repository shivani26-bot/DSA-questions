class Solution {
  
    public List<List<Integer>> fourSum(int[] nums, int target) {
           List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
int n=nums.length;
for(int i=0;i<n-3;i++){
    if(i>0 && nums[i]==nums[i-1]) continue;
    for(int j=i+1;j<n-2;j++){
         if(j>i+1 && nums[j]==nums[j-1]) continue;
         int n1=nums[i];
         int n2=nums[j];

    long t= (long)target-(n1+n2);
    // apply two sum in range, i+1 to n
    twoSum(nums, j+1, n-1, n1, n2, t,result);
    }
}
return result;
        
    }

      private void twoSum(int[] nums, int s, int e, int n1, int n2, long t,    List<List<Integer>> result){
        
        while(s<e){
            long currSum= (long) nums[s]+nums[e];
            if(currSum<t){
                s++;
            } else if(currSum>t){
                e--;
            }else{
                while(s<e && nums[s]==nums[s+1]){ //avoid duplicates
                    s++;
                }
                   while(s<e && nums[e]==nums[e-1]){ //avoid duplicates
                    e--;
                }
                result.add(Arrays.asList(n1,n2,nums[s],nums[e]));
                s++;
                e--;
            }

        }
    }
}