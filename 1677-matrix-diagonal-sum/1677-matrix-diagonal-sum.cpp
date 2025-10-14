class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
//         std::accumulate(begin, end, initial_value);
// or with a custom operation:
// std::accumulate(begin, end, initial_value, binary_op);
// vector<int> nums = {1, 2, 3, 4, 5};
//     int sum = accumulate(nums.begin(), nums.end(), 0);
//     int product = accumulate(nums.begin(), nums.end(), 1, [](int a, int b) {
//         return a * b;
//     });

// in 2d vector it will add row wise, starting from begin(mat) , here begin(mat) points to first row, that is vector hence we need to add all the elements inside that vector, for that we need lambda function
// lambda operator in accumulate take, initial sum, and a vector of elements which consists of row wise elements
// accumulate(begin(mat),end(mat),0,lambda)
// & this tells all the parameters are accessed via pass by reference 
// auto lambda=[&](int sum, vector<int>vec){
//     return sum+=accumulate(begin(vec),end(vec));
// }
// if row =i, then the opposite diagonal element in same row will be given by, vec[n-row-1]
// if vec[row]==vec[n-row-1] it means that is the common elmeent , only add once

int row=0;
auto lambda= [&](int sum,vector<int>vec){
    sum+=(vec[row]); //if both vec[row] and vec[n-row-1] are equal it means it's a common elmeent
    if(row!=vec.size()-row-1){
        sum+=(vec[vec.size()-row-1]);
    }
    row++;
    return sum;
};
int result= accumulate(begin(mat),end(mat),0,lambda);
return result;
    }
};