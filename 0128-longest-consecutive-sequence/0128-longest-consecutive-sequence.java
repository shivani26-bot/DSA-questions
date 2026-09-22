class Solution {
    public int longestConsecutive(int[] nums) {
                if(nums.length == 0) return 0;
        Set<Integer> st= new HashSet<>();

        for(int num: nums){
            st.add(num);
        }

        int longestSeq=0;

        for(int num: st){

//first element of the sequence;
            if(!st.contains(num-1)){
                int currNum= num;
                int currSeq= 1;

                while(st.contains(currNum+1)){
                    currNum++;
                    currSeq++;
                }

                longestSeq= Math.max(longestSeq, currSeq);

            }
        }
        return longestSeq;
    }
}