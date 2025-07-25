class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0;
        int i=0,j=0;
        int n=arr.size();
        int sum=0;
        while(j<n){
            sum+=arr[j];

            if(j-i+1<k) j++;
            else if(j-i+1==k){
                double avg= sum/k;
                if(avg>=threshold) ans++;
                sum-=arr[i];
                i++;j++;
            }
        }
        return ans;
    }
};