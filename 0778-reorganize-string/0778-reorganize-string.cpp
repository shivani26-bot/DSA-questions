class Solution {
public:
// aaabbbcdd
// "vvvlo"
//"aaa" 
    string reorganizeString(string s) {
        //   the character whose frequency is higher that causes problem here, as we don't want them to be together
        // if any character occurs more than ceil value of (n+1)/2 it means we can't arrange the string
        // if there is only 1 type of letter in string pq will have size 1 we can't form a string
        int n=s.length();
      unordered_map<char,int>mp;
      for(auto &ch:s){
       mp[ch]++;
      }
    


    priority_queue<pair<int,char>>pq;//will store frequency and character

    for(auto &it:mp){
               if(it.second>ceil((n+1)/2)) return "";

        pq.push({it.second, it.first});
    }
    // if(pq.top().first>ceil((n+1)/2)) return "";
    string result;
    while(pq.size()>=2){
        // pop two elements at once it will help to avoid the case when same letter comes on top of the heap 
        auto [count,ele]=pq.top();
        pq.pop();
        auto [count1,ele1]=pq.top();
        pq.pop();
        
        result+=ele;
        result+=ele1;
        count--;
        count1--;
        if(count>0)
        pq.push({count,ele});
        if(count1>0){
            pq.push({count1,ele1});
        }
    }
    if(!pq.empty()){
        result+=pq.top().second;
    }
    return result;
    }
};