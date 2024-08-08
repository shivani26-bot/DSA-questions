class Solution {
public:
    int minimumPushes(string word) {
        // character with highest frequency must occupy the first location
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
             mp[word[i]]++;
        } 
   
        vector<int>vec;
        for(auto it:mp){
            vec.push_back(it.second);
        }
        // for 26 letters
        // 8 + 8+ 8+2
        // 8 16 24 26
        
        sort(vec.begin(),vec.end(),greater<int>());
        int sum=0, count=0;
        for(auto it: vec){
            count++;
            if(count<=8){
                sum+=(1*it);
            }
            else if(count<=16){
                sum+=(2*it);
            }
            else if(count<=24){
                sum+=(3*it);
            }
            else{
                sum+=(4*it);
            }
        }
        return sum;
    }
};