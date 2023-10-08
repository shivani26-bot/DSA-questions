vector<int>arr1;
vector<int>arr2;
struct comp {
    bool operator()(pair<int,int>&p1,pair<int,int>&p2){
        return arr1[p1.first]+arr2[p1.second] > arr1[p2.first]+arr2[p2.second];
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        arr1=nums1;
        arr2=nums2;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        pq.push({0,0});
        vector<vector<int>>result;

        map<pair<int,int>,bool>mp;
        int n=nums1.size();
        int m=nums2.size();

        while(k>0  && !pq.empty() ){
            pair<int,int>p=pq.top();
            pq.pop();
            vector<int>ans;
            ans.push_back(nums1[p.first]);
            ans.push_back(nums2[p.second]);
            result.push_back(ans);
            if(p.second +1 <nums2.size()&& mp.find({p.first,p.second+1})==mp.end()){
                pq.push({p.first,p.second+1});
                mp[{p.first,p.second+1}]=true;
            }
            if(p.first +1 <nums1.size()&& mp.find({p.first+1,p.second})==mp.end()){
                pq.push({p.first+1,p.second});
                mp[{p.first+1,p.second}]=true;
            }  
            k--;
        }
        return result;
        //  arr1=nums1;
        // arr2=nums2;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        // pq.push({0,0});
        // vector<vector<int>>result;

        
        // while(k--){
        //     pair<int,int>p=pq.top();
        //     pq.pop();
        //     vector<int>ans;
        //     ans.push_back(nums1[p.first]);
        //     ans.push_back(nums2[p.second]);
        //     result.push_back(ans);
        //     if(p.second +1 <nums2.size()){
        //         pq.push({p.first,p.second+1});
       
        //     }
        //     if(p.first +1 <nums1.size()){
        //         pq.push({p.first+1,p.second});
        
        //     }  
        // }
        // return result;
    }
};