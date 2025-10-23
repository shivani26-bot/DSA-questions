class Solution {
public:

// s="1296"
// "1"   "12"  "129"  "1296"
bool check(int i,int currsum,string s, int num){
    // once we reach end of the string s, just return true if currsum == original num
if(i==s.length()){
    return currsum==num;
}
if(currsum>num){
    return false;
}
bool possible=false;
for(int j=i;j<s.length();j++){
    //find the substring first start from i, and j-i+1 length
    string sub=s.substr(i,j-i+1);
    int val=stoi(sub);//convert into integer
    // now check from j+1
    possible=possible || check(j+1,currsum+val,s,num);

    if(possible) return true;
}

return possible;
}
    int punishmentNumber(int n) {
        
int punish=0;
        // run a for loop from 1 to n, for each number find the square first then convert it to string
        // and then check all possible substring of that string that whether sum of possible substring result in the original num itself or not,
        for(int num=1;num<=n;num++){
            int sq=num*num;
            string s= to_string(sq);
            // check using recursion 
            if(check(0,0,s,num)){
                punish+=sq; //add the sq number if condition is true
            }
        }
        return punish;
        
    }
};