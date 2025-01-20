class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>rowCount(m,0);
        vector<int>colCount(n,0);
        map<int,pair<int,int>>mp; //ele, {x,y}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ele=mat[i][j];
                mp[ele]={i,j};
            }
        }
        for(int i=0;i<m*n;i++){
        
                int x=mp[arr[i]].first;
                  int y=mp[arr[i]].second;
                rowCount[x]++;
                colCount[y]++;
                if(rowCount[x]==n || colCount[y]==m) return i;
            
        }
        return -1;
    }
};
