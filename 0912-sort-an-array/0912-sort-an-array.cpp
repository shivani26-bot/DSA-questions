class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    //     int maxm=*max_element(nums.begin(),nums.end());
    //     cout<<maxm<<endl;
    //   vector<int>freq(maxm+2,0);
    //   for(int i=0;i<nums.size();i++){
    //     freq[nums[i]]++;
    //   }  
    //        for(int i=0;i<nums.size();i++){
    //    cout<<freq[i];
    //   }  
    //   vector<int>result;
    //   for(int i=0;i<freq.size();i++){
    //     if(freq[i]==0) continue;
    //     while(freq[i]!=0){
    //         result.push_back(i);
    //         freq[i]--;
    //     }
    //   }
    //   return result;
    map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    vector<int>result;
    for(auto it:mp){
        int count=it.second;
        while(count!=0){
            result.push_back(it.first);
            count--;
        }
    }
    return result;
    }
};