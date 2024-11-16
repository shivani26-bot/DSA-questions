class Solution {
public:
// 0 1 2 3  4 5 6 7 
// 1,2,3,10,4,2,3,5
// i          j arr=1,2,3,5  delete=j-i+1=4, we can delete 4 elements to make it increasing array
// start from n-1, check if arr[j]>=arr[j-1] j--;
// in the above ex: we stop j at index 5 , it means all the
// elements from j till n are sorted
// 0 1 2 3  4 5 6 7 
// 1,2,3,10,4,2,3,5
//   i        j  delete=3 ,arr=1,2,2,3,4,5
// 1,2,3,10,4,2,3,5
//     i      j
// as soon we get arr[i]>arr[j], we now increase j to find the shortest subarray
// 1,2,3,10,4,2,3,5
//     i        j  delete =3  arr=1,2,3,3,5
// now increase i , and try to decrease size of subarray
// 1,2,3,10,4,2,3,5
//       i      j  still arr[i]>arr[j] increase j
// 1,2,3,10,4,2,3,5
//        i       j still arr[i]>arr[j] increase j
// 1,2,3,10,4,2,3,5
//       i         j now j is out of bound, arr of size=j-i+1
//     delete=4, arr=1,2,3,10 
//     now if we increase i, arr[i]>arr[i+1] which is terminating state

    int findLengthOfShortestSubarray(vector<int>& arr) {
       int n=arr.size();
       int i=0, j=n-1;

            while(j>0 && arr[j]>=arr[j-1]) {
                j--;
                }
                  if(j==0) return 0; //already in increasing order
int ans=j; //we are removing all elements left to index j because index j to n-1 are sorted
          
        // find correct i and j and find deleted elements j-i+1
       while(i<j && (i==0 || arr[i]>=arr[i-1])) {
          
            while(j<n &&  arr[i]>arr[j]) j++;
            // we have found jth element such that arr[i]<=arr[j]
            ans=min(ans, j-i-1);
            i++;
        }

         return ans;
    }
};

// edge cases: if array is already in increasing or decreasing order 
// 1,2,3
// j
// i
// 3,2,1
// i   j
// 3,2,1
// i    j delete= 3-0-1=2

// 5,2,1,3,4
// i       j
// 5,2,1,3,4
// i   j      we can also remove elements here delete=3, hence initialize ans=j
// 5,2,1,3,4
// i        j delete =4