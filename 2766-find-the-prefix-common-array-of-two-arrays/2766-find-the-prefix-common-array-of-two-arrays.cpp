class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>result(n,0);
        set<int>st;
         if(A[0]==B[0]){
                result[0]=1;
            }
        st.insert(A[0]);
            st.insert(B[0]);
        for(int i=1;i<n;i++){
            if(st.count(A[i])){
                   result[i]++;
            }
           if(st.count(B[i])){
                   result[i]++;
            }
          if(A[i]==B[i]){
                result[i]++;
            }
            result[i]+=result[i-1];
            st.insert(A[i]);
            st.insert(B[i]);
        }
        return result;
    }
};