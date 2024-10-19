class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // brute force:
        // find every pair, and update the maximum index
        // i=0;i<n;i++
        //   j=i+1;j<n;j++
        //     if(nums[j]>=nums[i])
        //        max_i=max(max_i, j-i); 
        //TLE
        // o(n^2)
        // int n=nums.size();
        // int max_i=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[j]>=nums[i]){
        //             max_i=max(max_i, j-i);
        //         }
        //     }
        // }
        // return max_i;

        // time:o(n^2)
        //  int n=nums.size();
        // int max_i=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=n-1;j>i;j--){
        //         if(nums[j]>=nums[i]){
        //             max_i=max(max_i, j-i);
        //             break;
        //         }
        //     }
        // }
        // return max_i;


// total time: o(n)
// space: o(n)
        // store the max right element in an array for each element in an array
        // int n=nums.size();
        // vector<int>maxRightEl(n);
        // maxRightEl[n-1]=nums[n-1];
        // for(int i=n-2;i>=0;i--){ //o(n)
        //  maxRightEl[i]= max(nums[i],maxRightEl[i+1]);
        // }
        // for(int i=0;i<n;i++){
        //     cout<<maxRightEl[i]<< " ";
        // }
// [6,0,8,2,1,5]
//  8 8 8 5 5 5  ->maxRightEl
// [9,8,1,0,1,9,4,0,4,1]
//  9 9 9 9 9 9 4 4 4 1 ->maxRightEl
        // if max_el is smaller than that element at ith index then don't consider the ith index 
        // if max_el is greater than element at ith index then we can move the jth pointer in maxRightEl and find the max j-i, until maxRightEl[j]>= nums[i]
        // int i=0;
        // int j=0;
        // int ramp=0;
        // while(j<n){ //o(n)
 //Inner while(i < j && nums[i] > maxRightEl[j]) loop: Although it seems like a nested loop, it does not cause quadratic time complexity because each time i increments, it never decrements. Hence, both i and j pointers move only in one direction and increment at most n times each.
        // // while(nums[i]>maxRightEl[j]){
        // while(i<j && nums[i]>maxRightEl[j]){

        //     i++;
        // }
        // ramp= max(ramp,j-i);
        // j++;

        // }
        // return ramp;


        // monotonic stack 
        // build a monotonic decreasing stack which stores the index of element in decreasing order 
        stack<int>st;
        st.push(0);
         int n=nums.size();
        for(int i=1;i<n;i++){
          if(nums[st.top()]>=nums[i]){
            st.push(i);
          }
        }
        int maxWidth=0;
        for(int j=n-1;j>=0;j--){
            while(!st.empty()&& nums[st.top()]<=nums[j]){
                maxWidth=max(maxWidth, j-st.top());
                st.pop();
            }
        }
        return maxWidth;
    }
};