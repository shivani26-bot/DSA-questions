class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
       int n=nums.size();
  
     map<int,int>mp;
      for(int i=0;i<n;i++){
        mp[nums[i]]++;
      }
      if(n%k!=0) return false;

 
     
    while(!mp.empty()){
        int currentCard=mp.begin()->first;
      cout<<currentCard;
        for(int j=0;j<k;j++){
            if(mp[j+currentCard]!=0){
                mp[j+currentCard]--;
                 if(mp[j+currentCard]==0) mp.erase(j+currentCard);
            }
            else {
                return false;
            }
        }
       
            }
      return true;
    }
};