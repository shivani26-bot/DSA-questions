class Solution {
public:
// const int mod= 1e9+7;
#define mod 1000000007
    int sumSubarrayMins(vector<int>& arr) {
        // brute force tle
        // int n=arr.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int minm=INT_MAX;
        //     for(int j=i;j<n;j++){
        //         minm= min(minm,arr[j]);
        //         ans= (ans%mod+minm%mod)%mod;
        //     }
        // }
        // return ans;
        //find in how many subarrays, contribution of each element as minimum element 
        //for each index find nextsmaller element index and previous smaller elmement index

        // [71,55,82,55]
        int n=arr.size();
vector<int>nextSmaller(n);
stack<int>st;
st.push(0);
for(int i=1;i<n;i++){
    while(!st.empty() && arr[i]< arr[st.top()]){
        nextSmaller[st.top()]=i;
        st.pop();
    }
    st.push(i);
}
while(!st.empty()){
    nextSmaller[st.top()]=n;
     st.pop();
}
vector<int>previousSmallerEqual(n);
st.push(n-1);
for(int i=n-2;i>=0;i--){
    while(!st.empty() && arr[i]<= arr[st.top()]){
        previousSmallerEqual[st.top()]=i;
        st.pop();
    }
    st.push(i);
}
while(!st.empty()){
    previousSmallerEqual[st.top()]=-1;
    st.pop();
    }
 int ans=0;
for(int i=0;i<n;i++){
//this contribution will find out for every element as minimum element , in how many subarrays it's contributing as a minimum elmeent
  int eleContribution=((long long)((i-previousSmallerEqual[i])%mod  * (nextSmaller[i]-i)%mod)%mod  * arr[i]%mod)%mod;
  ans=  (ans%mod+eleContribution%mod)%mod;
}
return ans;
    }
};