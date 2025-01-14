class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        // int n=words.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //     string str1=words[i];
        //     string str2=words[j];
        //     if(str2.find(str1)==0 && str2.rfind(str1)==str2.length()-str1.length())
        //                count+=1;
        //     }
        // }
        // return count;

        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            int m=words[i].size();
            string str1=words[i];
            for(int j=i+1;j<n;j++){
                
                string str2=words[j];
                int k=words[j].size();
                 if (m <= k) {
                string prefix=str2.substr(0,m);
                string suffix=str2.substr(k-m,m);
                if(prefix==str1 && suffix==str1) count+=1;
                 }
            }
        }
        return count;
    }
};