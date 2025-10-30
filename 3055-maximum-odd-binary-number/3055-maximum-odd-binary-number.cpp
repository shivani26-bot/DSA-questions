class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // think greedily to make the maximum, start filling 1 from left hand side lsb, and to make odd , just put 1 at n-th bit, because all other are power of 2 ie even only 2^0 is 1 which can make number as odd
        int n=s.length();
    //   char ans[n];
    //    memset(ans, '0', sizeof(char) * n);
    vector<char>ans(n,'0');
    //    count number of 1's in string 
      int count1=0;
      for(int i=0;i<n;i++){
          if(s[i]=='1') count1++;
      }
cout<<count1<<endl;
// first fill the n-1 th position, because if only there is one 1 then to make odd the max odd binary will be 1 which we get by filling n-1th position, ie 2^0=1
      if(count1>=1) {
          ans[n-1]='1';
          count1--;
      }
      int i=0;
    //   start filling from left most side
      while(count1!=0&& i<n){
          ans[i]='1';
          count1--;
          i++;
      }
    //   for(int i=0;i<n;i++) cout<<ans[i]<<" ";
      string result;
    //   for(int i=n-1;i>=0;i--){
    //       result.push_back(ans[i]);
    //   }
     for(int i=0;i<n;i++){
          result.push_back(ans[i]);
      }
    //  reverse(result.begin(),result.end());
      return result;

    }
};