class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // gives tle 
        // long long  nums=0;
        // vector<int>ans;
        // for(int i=0;i<num.size();i++) {
            // nums=nums*10L + num[i];

        // }
        // nums=nums+k;
        // while(nums){
        //     int digit=nums%10;
        //     ans.push_back(digit);
        //     nums=nums/10;
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;

        // 0 <= num[i] <= 9
        // In C++, arr.insert() is typically used with STL containers like std::vector, std::list, std::set, or std::map, not plain C-style arrays.
        // std::vector<int> arr = {1, 2, 5};
// arr.insert(arr.begin() + 2, 3);  // Inserts 3 at index 2
// std::vector<int> v = {1, 2, 4, 5};
// v.insert(v.begin() + 2, 3); // v becomes {1, 2, 3, 4, 5}
// v.insert(v.begin() + 1, 3, 9); // insert three 9s at position 1
// // v becomes {1, 9, 9, 9, 2, 3, 4, 5}

int n=num.size();
for(int i=n-1;i>=0;i--){
    num[i]+=k; //add the k to the current element
    // extract the k for further addition with elements 
    k=num[i]/10;
    num[i]=num[i]%10; //update the current element
}
while(k>0){
    num.insert(num.begin(),k%10);//insert the last digit one by one at begining of the array
    k=k/10; 
}
return num;
    }
};