class Solution {
public:
    int totalFruit(vector<int>& s) {
      int i=0,j=0;
      unordered_map<int,int>mp;
      int n=s.size();
      int maxwindow=INT_MIN;
      while(j<n){
          mp[s[j]]++;
          if(mp.size()>2){
              while(mp.size()>2)
              {
                  mp[s[i]]--;
                  if(mp[s[i]]==0) mp.erase(s[i]);
                  i++;
              }
              j++;
          }
          else if(mp.size()<=2){
              maxwindow= max(maxwindow,j-i+1);
              j++;
          }
        }
        return maxwindow;
    }
};