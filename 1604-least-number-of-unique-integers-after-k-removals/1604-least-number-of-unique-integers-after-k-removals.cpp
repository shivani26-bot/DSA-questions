class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto &it: mp){
            cout<<it.second<<" "<<it.first<<endl;
            pq.push({it.second, it.first});
        }
        while(!pq.empty() && k>0){
         int occurence=pq.top().first;
         int element=pq.top().second;
         cout<<"occurence"<<endl;
         cout<<occurence<< " "<<element<<endl;
         if(k>=occurence){
            k-=occurence;
            pq.pop();
         }
         else{
            occurence= occurence-k;
            // pq.push({occurence, element});
            break;
         }
        }
        return pq.size();

    }
};