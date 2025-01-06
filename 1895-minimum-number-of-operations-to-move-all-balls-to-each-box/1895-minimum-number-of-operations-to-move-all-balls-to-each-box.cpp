class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        int ones= count(begin(boxes),end(boxes),'1');
        vector<int>ones_idx;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1') ones_idx.push_back(i);
        }
        int sz=ones_idx.size();
        vector<vector<int>>matrix(sz,vector<int>(n,0));
        for(int i=0;i<sz;i++){
            for(int j=0;j<n;j++){
                 matrix[i][j]=abs(ones_idx[i]-j);
            }
        }
        vector<int>ans;
      
        for(int j=0;j<n;j++){
                int sum=0;
            for(int i=0;i<sz;i++){
                sum+=matrix[i][j];
            }
            ans.push_back(sum);
        }
      return ans;
    }
};