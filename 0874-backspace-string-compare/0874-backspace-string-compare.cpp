class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length(),m=t.length();
        int i=n-1;
        int j=m-1;
        string newT;
        string newS;
        int skip=0;
        int skip1=0;
        while(i>=0){
             if(s[i]=='#'){
               skip++;
             }
             else{
                if(skip>0){
                    skip--;
                }
                else{
                    newS=s[i]+newS;
                }
             }
           
            i--;
        }

    while(j>=0){
             if(t[j]=='#'){
               skip1++;
             }
             else{
                if(skip1>0){
                    skip1--;
                }
                else{
                    newT=t[j]+newT;
                }
             }
           
            j--;
        }
        cout<<newS<<endl;
        cout<<newT;
      return newS==newT;
    }
};

// ab#cde#f##xy