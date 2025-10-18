class Solution {
public:
    bool isHappy(int n) {
//         take ex: 61
//         36+1=37
//         9+49=58
//         25+64=89
//         64+81=145
//         1+16+25=42
//         16+4=20
//         4+0=4
//         16+0=16
//         1+36=37
//         if we look closely we get the same number 37 again, it means it will be a forever loop return false;
//         similarly with 2, 4 will repeat twice, we need to stop here
//          4+0=4
//         16+0=16
//         1+36=37
//         9+49=58
//         25+64=89
//         64+81=145
//         1+16+25=42
//         16+4=20
//         4+0=4 
// use set to track whether we have encountered the number in past 

// find the sum of squares of the current number;
unordered_set<int>st;
while(true){
int sum=0;
while(n!=0){
    sum+= pow(n%10,2);
    n=n/10;
}

// if sum is 1 retrun true 
if(sum==1) return true;

// if not 1 then sum will be the new number
n=sum;
// now check whether this new number is present in set or not, if present then return false other wise add in set 
if(st.count(n)) return false;
st.insert(n);
}


    }
};