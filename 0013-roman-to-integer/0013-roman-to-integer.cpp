class Solution {
public:
    int romanToInt(string s) {
//         when a smaller value comes before a larger one,
// it means subtraction.
// Example:
// IV = 5 - 1 = 4
// IX = 10 - 1 = 9
// XL = 50 - 10 = 40
// XC = 100 - 10 = 90

// You process the Roman string left to right:
// Look at the current symbol and the next one.
// If current ≥ next, just add the current value.
// If current < next, then subtract the current value.

// Why?
// Because:
// A smaller value before a larger one means we’ve “looked ahead” to a subtractive pair (like IV or IX).
// A larger or equal value means we can safely add it (like VI or XI).
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++){
if(mp[s[i]]>=mp[s[i+1]]){
    // if current number >next number 
    sum+=mp[s[i]];
}
else{
    //if next number is greater than current number then subtract 
    sum-=mp[s[i]];
}
}
return sum;
        }
    
};