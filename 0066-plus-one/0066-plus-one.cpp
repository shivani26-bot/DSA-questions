class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
       for(int i=n-1;i>=0;i--){
        // if current digit is < 9 just increment the current digit and return the vector digits as it is ex: [1,2,3] -> [1,2,4] , [1,2,8]->[1,2,9]
        if(digits[i]<9){
            digits[i]++;
            return digits;
        }
        // but if current digit is 9 then replace with 0 
        digits[i]=0;
        // [1,2,9]=>[1,2,0]=>[1,3,0]
       }

    //    if all the digits are [9,9,9]=> we get [0,0,0] from above, we need to add 0 in front
    // If all digits were 9
    vector<int> result(n + 1, 0);
    result[0] = 1;
    return result;
    }
};