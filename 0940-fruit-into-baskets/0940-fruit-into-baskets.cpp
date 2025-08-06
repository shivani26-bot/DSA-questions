class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0,j=0;
        unordered_map<int,int>mp;
        int maxWin=INT_MIN;
        while(j<n){
            mp[fruits[j]]++;
            // sum+=fruits[j];
while(mp.size()>2){
    mp[fruits[i]]--;
if(mp[fruits[i]]==0) mp.erase(fruits[i]);
i++;
   
}

 maxWin=max(maxWin, j-i+1);
    j++;
        }
        return maxWin;
    }
};