class Solution {
public:
bool check(string word , int mask){
 int maskWord=0;
        for(char c:word){

          maskWord|=  1<<(c-'a');
        }
return (maskWord & ~mask) ==0;

}
    int countConsistentStrings(string allowed, vector<string>& words) {
        // set<char>st(allowed.begin(),allowed.end());
        // int count=0;
        // for(int i=0;i<words.size();i++){
        //     int j;
        //     for(j=0;j<words[i].size();j++){
        //         if(st.count(words[i][j])) continue;
        //         else break;
        //     }
        //     if(j>=words[i].size())
        //    count++;
        // }
        // return count;
        // bit manipulation
        // make a mask for allowed 
        int mask=0;
        for(char c:allowed){
          mask|=  1<<(c-'a');
        }
        cout<<mask;
        int count=0;
        for(auto it:words){
        if(check(it,mask)) count++;
        }
        return count;
    }
};


