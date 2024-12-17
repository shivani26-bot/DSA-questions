class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>>maxheap;
unordered_map<char,int>mp;
        string ans;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:mp){
            maxheap.push({it.first,it.second});
        }
        while(!maxheap.empty()){
            // cout<<maxheap.top().first << maxheap.top().second<<" ";

            // auto [ch,chCount]=maxheap.top();
            int ch=maxheap.top().first;
            int chCount=maxheap.top().second;
             maxheap.pop();
           
            int toAppend= min( repeatLimit,chCount);
            
            ans+=string(toAppend,ch);
            // ans.append(toAppend,ch);
            chCount-=toAppend;
            if(chCount>0){
              if(maxheap.empty()) break;
              auto [nextCh, nextChCount]=maxheap.top(); 
              maxheap.pop();
              ans+=nextCh;
              nextChCount--;
              if(nextChCount>0) maxheap.push({nextCh,nextChCount});
              maxheap.push({ch,chCount});
            }
           
           
        }
        return ans;

    }
};