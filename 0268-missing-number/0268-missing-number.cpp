class Solution {
public:
      int missingNumber(vector<int>& arr) {
    
// method1
// sort(arr.begin(),arr.end());
// for(int i=0;i<arr.size();i++){
//     if(arr[i]>i){
// return i;
// break;

//     } 
    
// }
// return arr.size();
// method2
// int n=arr.size();
// int totalsum=n*(n+1)/2;
// int arrsum=0;
// for(int i=0;i<n;i++){
//    arrsum+=arr[i];
// }
// int ans=(totalsum-arrsum);
// return ans;

// method3
// int i=0;
// while(i<arr.size()){
//     int currentIndex=arr[i];
//     while(arr[i]!=arr[currentIndex] && arr[i]<arr.size()){
//         swap(arr[i],arr[currentIndex]);
//         if(i>=arr.size()-1) {
             
//           break;
//         }
//     }
//      i++;
// }
// for(int i=0;i<arr.size();i++){
//     if(arr[i]!=i) return i;
// }
// return arr.size();

// method4
   int result=arr.size();
   
   for(int i=0;i<arr.size();i++){
  result^=arr[i];
  result^=i;
   }
   return result;
    }
};