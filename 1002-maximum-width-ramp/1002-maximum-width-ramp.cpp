class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
stack<int>st;

//build the decreasing stack from the begining of the array
for(int i=0;i<n;i++){
    if(st.empty() || nums[st.top()]>nums[i] ){
        st.push(i);
    }
}
int maxwidth=0;
    // traverse the array from end to find the max width 
    for(int j=n-1;j>=0;j--){
        while(!st.empty() && nums[st.top()]<=nums[j]){
            maxwidth=max(maxwidth, j-st.top());
            st.pop();
        }
    }
    return maxwidth;

    }
};