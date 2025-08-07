class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //  You’ve got a sorted array, and you need to pick k numbers that are closest to x. If two numbers are equally close, pick the smaller one.
        // Start with the full window [i, j]. While the window size is bigger than k, compare arr[i] and arr[j] to x. Remove the one that's farther from x (or, if tied, remove the larger). Repeat until window size is k.
        // Since the array is sorted, arr[j] will always be greater than arr[i]. So, if both ends are equally far from x, we remove arr[j] to keep the smaller element.
        int i=0;
        int j=arr.size()-1;
        while(j-i+1>k){
            if(arr[j]-x<x-arr[i])
            i++;
            else j--;
        }
        return vector<int>(arr.begin()+i,arr.begin()+j+1);
    }
};