class Solution {
public:
 int m;
int binarySearch(vector<vector<int>>& items, int target){
    int low=0;
    int high=m-1;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(items[mid][0]>target) high=mid-1;
        else{
            ans=max(ans,items[mid][1]);
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>ans;
        int n=queries.size();
     m=items.size();
        sort(items.begin(),items.end());
        int maxBeautySoFar=items[0][1];
for(int i=1;i<m;i++){ 
    maxBeautySoFar= max(maxBeautySoFar, items[i][1]);
    items[i][1]=maxBeautySoFar;
}
        for(auto it:items){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        for(int i=0;i<n;i++){
                  int q=queries[i];
                 ans.push_back(binarySearch(items,q));
        }
        return ans;
    }
};