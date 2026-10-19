class Solution {
    public int removeElement(int[] nums, int val) {
           int n=nums.length;
 
if(n==1 && nums[0]==val) return 0;
if(n==1 && nums[0]!=val) return 1;
if(n<1) return 0;

    int i=0,j=1;
    while(j<n){
        if(nums[i]!=val){
            i++;
            j++;
        }
        else if(nums[j]==val){
            j++;
        }
        else if(nums[j]!=val){
            int temp= nums[j];
            nums[j]=nums[i];
            nums[i]=temp;
            i++;
            j++;
        }
    }

    return nums[n-1]!= val? n: i;
    }
}