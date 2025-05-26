class Solution {
public:
int solve(int n, int k){
     if(n==1 && k==1) return 0; //base condition for 1st row 1st character
    int length=pow(2,n-1);
    int mid= length/2;
  
  if(k<=mid){
    return solve(n-1,k);//we will get the answer from previous row and at same kth character
  }
  else {
    return !solve(n-1, k-mid);//we will get the answer from previous row flip the kth character;
    //  return 1-solve(n-1, k-mid);//we can also find the complement like this
  }
  

}
    int kthGrammar(int n, int k) {
       return solve(n,k);
    }
};

// n=4, k=4
//                                 0
//                       0                  1
//                   0        1         1        0
//                0     1   1    0    1    0   0    1
// index:         1     2   3    4    5    6   7    8
// kth index 4: 0                     1    2   3    4 mid=4

// first half of the current row is exact copy of the previous row 
// second half of the current row is exact complement of the previous row 
// if there are n rows then noOfele: 2^(n-1) element will be there in last row 
// if asked k value is <=noOfele/2 then we can find out the answer from the previous row only
// if k value is >noOfele/2 then we can find out the answer by complement the previous row
// if mid =noOfele/2 if k>mid, mid-k
// brute force:
// take a 2d vector and build each row and for the last row return the kth element but this will give TLE , MLE

// for every current row we can findd the answer from previous row, hence we can use recursion 

// solve(n,k){
//     base case

//     recurrence relation

//     body  //here we can interchange recurrence relation with body
// }