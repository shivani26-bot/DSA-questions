class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // using set:
        // find all the prefixes of arr1 and keep it in set
       //123
       //st: 123,12,1
       //12345
       //12345, 1234,123(already present)
        unordered_set<int>st;
        for(int i=0;i<arr1.size();i++){
               int val=arr1[i];
               //prefix should not be present
               while(!st.count(val) && val>0){
                st.insert(val);
          val=val/10; //ex: 1000, insert 1000,100,10
               }
        }
        int result=0;//longest common prefix
        // go through all the elements in arr2, find out all the prefix of a element, until we don't get the 
        // prefix in the set keep on finding the prefix of the element

        for(auto num:arr2){
            while(!st.count(num) && num>0){
                num=num/10;
            }
            //if we find the element in the set 
            if(num>0){
                result=max(result,static_cast<int>(log10(num)+1));
            }
        }
        return result;
    }
};