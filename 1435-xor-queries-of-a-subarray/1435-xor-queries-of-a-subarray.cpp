class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prefixXor(n,0);
        prefixXor[0]=arr[0];
        for(int i=1;i<arr.size();i++){
prefixXor[i]=prefixXor[i-1]^arr[i];
        }
        for(int i=0;i<prefixXor.size();i++){
            cout<<prefixXor[i]<<" ";
        }
        vector<int>ans;
        for(auto& q:queries){
            int s=q[0];
            int e=q[1];
            if(s==0) ans.push_back(prefixXor[e]);
         
            else //when s>0
            ans.push_back(prefixXor[e]^prefixXor[s-1]);
        }
        return ans;
    }
};