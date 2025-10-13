class Solution {
public:
    int countOdds(int low, int high) {
        // from 1 to high there are (high+1)/2 odd numbers
        // from 1 to low there are (low/2) odd numbers 
        // return (high+1)/2- (low/2);
        int result=(high-low)/2;
        if(low%2==0 && high%2==0){
            return result;
        
        }
        else result= result+1;

        return result;
        
    }
};