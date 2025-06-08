class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
//         int n=prices.size();
// vector<int>finalPrice(n);
// finalPrice[n-1]=prices[n-1];
// for(int i=0;i<n-1;i++){
//     for(int j=i+1;j<n;j++){
//         if(prices[j]<=prices[i]){
//             finalPrice[i]=prices[i]-prices[j];
//             break;
//         }
//         else{
//             finalPrice[i]=prices[i];
//         }
//     }
// }
// return finalPrice;

int n=prices.size();
vector<int>result=prices;//if in case we don't find the smallest element for a index the answer will be equal to element at that index only
stack<int>st;//it will store the index of the price array
for(int i=0;i<n;i++){
    while(!st.empty() && prices[st.top()]>=prices[i]){
        result[st.top()]=prices[st.top()]-prices[i];
        st.pop();

    }
    //push the index
    st.push(i);
}
return result;
    }
};