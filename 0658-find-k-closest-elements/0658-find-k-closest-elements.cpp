class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //  You’ve got a sorted array, and you need to pick k numbers that are closest to x. If two numbers are equally close, pick the smaller one.
        // Start with the full window [i, j]. While the window size is bigger than k, compare arr[i] and arr[j] to x. Remove the one that's farther from x (or, if tied, remove the larger). Repeat until window size is k.
        // Since the array is sorted, arr[j] will always be greater than arr[i]. So, if both ends are equally far from x, we remove arr[j] to keep the smaller element.
        // int i=0;
        // int j=arr.size()-1;
        // while(j-i+1>k){
        //     if(arr[j]-x<x-arr[i])
        //     i++;
        //     else j--;
        // }
        // return vector<int>(arr.begin()+i,arr.begin()+j+1);

        //binary search
// Since the array is sorted, you can use binary search to find the left boundary of the window of size k, so that the k elements starting from that index are closest to x.
// You search for the smallest left such that arr[left + k] is farther from x than arr[left].
// For binary search here, low = 0 and high = n - k (where n is the array length). This is because the window of size k can start anywhere from index 0 to n-k.

// Why not let high go up to n-1? Because you need room for k elements after left.
int n =arr.size();
int l=0,h=n-k;
while(l<h){
    int m=l+(h-l)/2;
    if(x-arr[m]>arr[m+k]-x){
        l=m+1;
    }
    else{
        //take the smaller one, if equal or lesser distance
        h=m;
    }
}
vector<int>ans;
for(int i=0;i<k;i++){
    ans.push_back(arr[l+i]);
}
return ans;
    }
};