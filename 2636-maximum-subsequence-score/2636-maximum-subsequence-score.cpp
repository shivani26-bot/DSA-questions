class Solution {
public:
//gives tle
// int n;
// int K;
// int solve(int i,vector<int>& nums1, vector<int>& nums2,int sum, int count,int K, int minm ){
// if(count==K) return sum*minm;
// if(i>=n) return 0;
// //we can also use minheap to find minimum element
//     int take=solve(i+1,nums1,nums2,sum+nums1[i],count+1,K,min(minm, nums2[i]));
//     int notTake= solve(i+1,nums1,nums2,sum,count,K,minm);

//     return max(take,notTake);
// }
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

// // we can use recursion, as we have options, we will try to pick k different subsequence
// // and compute the answer
// n=nums1.size();
// K=k;
// return solve(0,nums1,nums2,0,0,K,INT_MAX);
//     }
 
 //gives tle
// int n;
// int K;
// priority_queue<int,vector<int>,greater<int>>pq;
// void removeFromPq(int num){
//     vector<int>temp;
//     while(!pq.empty()){
//         int x=pq.top();
//         pq.pop();
//         if(x==num) break;
//         temp.push_back(x);
//     }
//     for(int &x: temp){
//         pq.push(x);
//     }
// }
// int solve(int i,vector<int>& nums1, vector<int>& nums2,int sum, int count,int K, int minm ){
// if(count==K) return sum*minm;
// if(i>=n) return 0;
// //we can also use minheap to find minimum element
// // if we decide to take a element push in heap
// pq.push(nums2[i]);
//     int take=solve(i+1,nums1,nums2,sum+nums1[i],count+1,K,pq.top());
//     removeFromPq(nums2[i]);
//     int notTake= solve(i+1,nums1,nums2,sum,count,K,minm);

//     return max(take,notTake);
// }
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

// // we can use recursion, as we have options, we will try to pick k different subsequence
// // and compute the answer
// n=nums1.size();
// K=k;
// return solve(0,nums1,nums2,0,0,K,INT_MAX);
//     }




    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
// to get the max answer we should maximize the minimum element
// sort the nums2 in descending order , and also sort the elements in
// nums1 corresponding to nums2
// nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
// nums1= 2 3 1 3 -> sorted corresponding to nums2
// nums2= 4 3 2 1 -> sorted in descending order
// if we choose 4 as min element then we can't choose any other element
// if we choose 3 as min element we can only choose 4 and 3 and corresponding elements in nums1
// if we choose 2 as min elemnt (hence we should start from k-1th element then only we can pick k elements) 
//  (2+3+1) * 2=12
// if we choose 1 as min element
// we would like to remove smallest element in (2+3+1) and will place 3 in nums1 corresponding to 1 in nums2
// (2+3+3) * 1=8
// use min heap to keep track of smallest element in nums1 which will be replaced by element in nums1 which is corresponding to current nums2
// we want to maximize both the sum and minm
// to maximize min start from k-th element
// to maximize sum always remove the smallest element from current element
vector<pair<int,int>>vec; //maps nums1 to nums2
int n=nums1.size();
for(int i=0;i<n;i++){
    vec.push_back({nums1[i],nums2[i]});
}
auto comp =[&](auto &p1, auto &p2){
return p1.second > p2.second;
};
sort(vec.begin(),vec.end(), comp);//sort in descending order based on nums2
priority_queue<int,vector<int>,greater<int>>pq;//min heap
// start from k-1th element, take minimum from k-1 element then only we will get k element to sum up and find minimum
long long kSum=0;
for(int i=0;i<k;i++){ //sum till k-1 element
    kSum+=vec[i].first;
    pq.push(vec[i].first);//will give the minimum element till the current index
}
long long result= kSum * vec[k-1].second;
for(int i=k;i<n;i++){
 //if nums2[i] is the minimum element , we will need nums1[i] in the sum and have to remove the smallest element in previous sum
 kSum+=vec[i].first- pq.top();
 pq.pop();
 pq.push(vec[i].first);
 result= max(result,kSum*vec[i].second);
}
return result;
    }
};