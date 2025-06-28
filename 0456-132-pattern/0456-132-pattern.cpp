class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // [3,5,0,3,4] important test case, do try dry run 
        // brute force:
// int n=nums.size();
// for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         if(nums[i]<nums[j]){
//             // then only find the nums of k
//             for(int k=j+1;k<n;k++){
//                 if(nums[i]<nums[k]  && nums[k]<nums[j] ){
//                     return true;
//                 }
//             }
//         }
//     }
// }
// return false;


// i      j   k
// num1 num2 num3
// num1 < num3 < num2
    //     3      3
    //     4      4 if we get 4 digit then 3 will be the ideal candidate for num3
    //            5 if we get 5 digit then 4 will be the ideal candidate for num3
    // if at any point current number < num3 then return true
// num2 will be largest element 
stack<int>st;

int n=nums.size();
int num3=INT_MIN;
for(int i=n-1;i>=0;i--){

if(nums[i]<num3) return true;
while(!st.empty() && nums[i]>st.top()){
    num3=st.top();
    st.pop();
}
    st.push(nums[i]);
}
return false;
    }
};




// class Solution {
// public:
//  bool find132pattern(vector<int>& nums) {
// stack<pair<int,int>>st;
// int lastMinimum= INT_MIN;
// for(int i=nums.size()-1;i>=0;i--){
// if(nums[i]<lastMinimum){
//     return true;
// }

// while(!st.empty() && nums[i]>st.top().second){
//     lastMinimum=st.top().second;
//     st.pop();
// }
// st.push({i,nums[i]});
// }
// return false;
// }


// // 1. We initialize an empty stack `st` to keep track of potential `132` patterns. The stack will store pairs `(index, value)` where `index` represents the index of the element in the `nums` array and `value` represents the value of the element.

// // 2. We also initialize a variable `s3` to keep track of the potential third element `s3` of the `132` pattern. We initialize it to the smallest possible value (`INT_MIN`) initially.

// // 3. We iterate through the `nums` array in reverse order (from right to left). This is because we are looking for patterns where the `3` comes before `1` and `2`.

// // 4. Inside the loop:
// //    - If the current element `nums[i]` is less than `s3`, it means we have found a valid `132` pattern, and we can return `true`.
// //    - We then check the stack. While the stack is not empty and the current element `nums[i]` is greater than the second element of the top pair in the stack (`st.top().second`), we update `s3` to be the value of the second element of the top pair, and then pop the top element from the stack. This is because the potential `132` pattern is being broken, so we need to update the potential `s3` value.
// //    - After updating the `s3` and popping elements from the stack, we push the current element `(i, nums[i])` onto the stack. This represents a potential `13` pair.

// // 5. After the loop completes, if we haven't found any valid `132` pattern, we return `false`.

// // In summary, the algorithm iterates through the `nums` array in reverse order and uses a stack to keep track of potential `13` pairs. It also maintains the potential `s3` value, which represents the third element of the `132` pattern. If a valid `132` pattern is found, the algorithm returns `true`, otherwise, it returns `false`.

// };