class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // int result=0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //       int currXor= nums1[i]^nums2[j];
        //       result^=currXor;
        //     }
        // }
        // return result;
        int result=0;
        int n=nums1.size();
        int m=nums2.size();
        if(n%2==1 && m%2==0){
            for(int i=0;i<m;i++){
                result^=nums2[i];
            }
        }
        else if(n%2==0 && m%2==1){
             for(int i=0;i<n;i++){
                result^=nums1[i];
            }
        }
        else if(n%2==1 && m%2==1){
             for(int i=0;i<n;i++){
                result^=nums1[i];
            }
             for(int i=0;i<m;i++){
                result^=nums2[i];
            }
        }
        else{
            return 0;
        }
        return result;
    }
};