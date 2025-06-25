class Solution {
public:
// total tc: o(n^2*n)
// space: o(n)
//o(n)
int solve(int j, int k,vector<int>& arr,unordered_map<int,int>&mp ){
    int target=arr[k]-arr[j];
    if(mp.count(target) && mp[target]<j){
        int i=mp[target];
        return solve(i,j,arr,mp)+1;//1 is for kth element that will be included in ans
    }
    return 2; // 2 because if in case we don't have further elements i,j,k since k has already been counted, this is for i,j
}

//o(n^2)
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
    //    elements are in strictly increasing order, and unique we can store element->index in map, we will use map to find the index of 3rd element in the sequence
    // also length>=3 only then its a valid sub-sequence
    // i<j<k
    // 3 5 8
    // a+b=c=> c-b=a
    // mp=> a->0, b->1,c->2 
//     0  1  2
//    {a, b, c}
//     i  j  k

// 1+ solve(j,k)=> 1+2=3
//    c-b=a 0<1


// solve(i,j) =>this will return 2 as there is no z a and b are last element
// b-a=z
unordered_map<int,int>mp;
for(int i=0;i<n;i++){
    mp[arr[i]]=i;
}

int result=0;
for(int j=1;j<n;j++){
    for(int k=j+1;k<n;k++){
       int length=solve(j,k,arr,mp);
if(length>=3){
    result=max(result,length);
}
    }
}
return result;//will give max length fibonacci subsequence
    }
};