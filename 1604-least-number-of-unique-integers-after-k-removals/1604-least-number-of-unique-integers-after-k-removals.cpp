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
            break;
         }
        }
        return pq.size();

    }
};



// class Solution {
//     bool static cmp(pair<int,int>a,pair<int,int>b){
//         return a.second>b.second;
//     }
// public:
//     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//         int n=arr.size();
//         map<int,int>mp;
//         for(int i=0;i<n;i++) mp[arr[i]]++;
//         vector<pair<int,int>>p;
//         for(auto i: mp) p.push_back({i.first,i.second});
//         sort(p.begin(),p.end(),cmp);
//         // for(int i=0;i<p.size();i++)
//         // cout<<p[i].first<<" "<<p[i].second<<endl;
//         int i=p.size()-1;
//         while(k!=0){
//             if(p[i].second!=0){
//                 p[i].second--;
//                 k--;
//                 if(k==0 && p[i].second==0){
//                     p.pop_back();
//                 }
//             }
//             else if(p[i].second==0){
//                 p.pop_back();
//                 i--;
//             }
//             else i--;
//         }
//         return p.size();

//     }
// };