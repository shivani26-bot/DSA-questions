class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // try xoring the elements with different sizes of array 
        // n-even m=odd, n=odd m=even, n=odd m=odd , n=even, m=even  you will get the answer
        int n=nums1.size();
        int m=nums2.size();
        int result=0;
        if(n%2==1 && m%2==0){
            // if n is odd and m is even it means each element in nums1 will have even times pair hence element in n will cancel out only m is remaining 
            // [2,1,3] [10,2,5,0]
            // 2^10 ^ 2^2 ^ 2^5 ^ 2^0 ^ 1^10 ^ 1^2 ^ 1^5 ^ 1^0 ^ 3^10 ^ 3^2 ^ 3^5 ^ 3^0
            for(int i=0;i<m;i++){
                result^=nums2[i];
            }
        }  else if(n%2==0 && m%2==1){
            for(int i=0;i<n;i++){
                result^=nums1[i];
            }
        } else if(n%2==1 && m%2==1){
            for(int i=0;i<n;i++){
                result^=nums1[i];
            }
            for(int i=0;i<m;i++){
                result^=nums2[i];
            }
        }
        else return 0;

        return result;
    }
};