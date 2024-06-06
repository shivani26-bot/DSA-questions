class Solution {
public:
    int countTriplets(vector<int>& arr) {
      int n=arr.size();
      int count=0;
      for(int i=0;i<n;i++){
        int xorSum=0;
        for(int k=i;k<n;k++){
           xorSum^=arr[k];
       if(xorSum==0) count+=(k-i);
        }
      }
      return count;
    }
};

// if i to k is 0 it means that we got the subarray where a==b which means if be xor a^b it must give 0 and we can place j anywhere in between i to k;
//     0   1  2  3  4
// ex: a1 a2 a3 a4 a5 
//      i        k
//         j  j  j  we can place j any where hence possible triplets can be  k-i