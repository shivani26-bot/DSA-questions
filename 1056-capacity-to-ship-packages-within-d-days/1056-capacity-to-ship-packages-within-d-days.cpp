class Solution {
public:
//  bool func(vector<int>& A, int N,int days, int mid){
//         int sum=0, count=1;
//         for(int i=0;i<N;i++){
//             if(sum+A[i]>mid) {
//                 count++;
//                 sum=A[i];
//             }
//             else{
//                 sum+=A[i];
//             }
//         }
//         return count<=days;
//     }
//     int shipWithinDays(vector<int>& A, int days) {
//         int N= A.size();
//          int low= *max_element(A.begin(),A.end());
//         int sum=0;
//         for(int i=0;i<N;i++){
//           sum+=A[i];
            
//         }
       
//         int high=sum;
//         while(low<=high){
//             int mid=(low+high)/2;
//             bool r = func(A,N,days,mid);
//             if(!r) low=mid+1;
//             else{
//                 bool r1= func(A,N,days,mid-1);
//                 if(!r1) return mid;
//                 else high=mid-1;
//             }
//         }
//    return low;
//     }

bool canShipAllPackages(vector<int>& weights, int days, int w){
int n= weights.size();
int sum=0; //sum of weight of packages
int actualDays=1;
for(int i=0;i<n;i++){
    if(sum+weights[i]>w){
        actualDays++;
        sum=weights[i];
    }
    else
    sum+=weights[i];
}
return actualDays<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
int total_weight=0;
for(int i=0;i<n;i++){
    total_weight+=weights[i];
}
int low=  *max_element(weights.begin(),weights.end());
int high= total_weight;
while(low<high){
    int mid=low+(high-low)/2; //possible weight
    if(canShipAllPackages(weights, days, mid)) high=mid;
    else low=mid+1;
}
return low;

    }
};