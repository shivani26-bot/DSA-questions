class Solution {
public:
    bool canChange(string start, string target) {
        // start->"L_"
        // target->"_L"
        // if start[i]=="L"
        // if(i<j) false;
        // start->"_R"
        // end->"R_"
        // start[i]=='R'
        // if(i>j) false;
        // if there is _ then ignore this 

        // start="_L"
        // end="LL"

        int n=start.length();

        int i=0,j=0;
        while(i<n || j<n){
            while(i<n && start[i]=='_') i++;
            while(j<n && target[j]=='_') j++;
               if(i==n || j==n) //both the string should end at same time
            return i==n && j==n;
            if(start[i]!=target[j]) return false;
         
    
            if(start[i]=='L' && i<j) return false;
            if(start[i]=='R' && i>j) return false;
          i++;
          j++;

        }
        return true;
    }
};