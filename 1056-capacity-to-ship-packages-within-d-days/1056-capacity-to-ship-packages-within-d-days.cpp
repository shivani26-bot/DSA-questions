class Solution {
public:
 bool func(vector<int>& A, int N,int days, int mid){
        int sum=0, count=1;
        for(int i=0;i<N;i++){
            if(sum+A[i]>mid) {
                count++;
                sum=A[i];
            }
            else{
                sum+=A[i];
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& A, int days) {
        int N= A.size();
         int low= *max_element(A.begin(),A.end());
        int sum=0;
        for(int i=0;i<N;i++){
          sum+=A[i];
            
        }
       
        int high=sum;
        //  while(low<high){
        while(low<high){
            int mid=(low+high)/2;
            bool r = func(A,N,days,mid);
            if(!r) low=mid+1;
            else{
                // bool r1= func(A,N,days,mid-1);
                // if(!r1) return mid;
                // else high=mid-1;
                high=mid;
            }
        }
   return low;
    }
};