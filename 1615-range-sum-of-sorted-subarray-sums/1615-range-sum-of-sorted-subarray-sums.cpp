class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
    //     int sum;
    //    int totalSum=0;
    //     vector<int>arr;
    //    for(int i=0;i<nums.size();i++){
    //        sum=0;
    //     for(int j=i;j<nums.size();j++){
    //           sum+=nums[j];
    //         //   cout<<sum<<endl;
    //         arr.push_back(sum);
    //         //   if(sum>=left && sum<right){
    //         //     totalSum+=sum;
    //         //   }
    //         //   cout<<totalSum<<endl;
    //     }
    //    } 
    //    sort(arr.begin(),arr.end());
    //   const int mod = 1e9 + 7;
    //    for(int i=left-1;i<right;i++){
    //     totalSum= (totalSum+arr[i])%mod ;
    //    }
    //    return totalSum;

//we can use heap to find subarray sum of an array in increasing/decreasing order
// min-heap: increasing order
// max-heap: decreasing order

// each element in array is subarray in itself 

// typedef pair<int,int> P;
//  priority_queue<P,vector<P>,greater<P>>pq;
// space: at a time, n elements are there in pq o(n)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //n logn
for(int i=0;i<nums.size();i++){
    pq.push({nums[i],i});
}
const int mod=1e9+7;
int count=1;
int totalSum=0;
// right*logn: in worst case we can be asked for all the subarray sum, right can be n*(n+1)/2 ~n^2logn
for(int count=1;count<=right;count++){
    int index=pq.top().second;
    int sumSubArr=pq.top().first;
    pq.pop();//logn

  if(count>=left){
    totalSum=(totalSum+sumSubArr)%mod;
  }
  if(index+1<n)
  pq.push({sumSubArr+nums[index+1],index+1});//logn
}
  return totalSum;
    }
  
};

// in min heap we can store the pair of {sum of subarray, ending index of that subarray}, it will give us the sum in increasing order 

