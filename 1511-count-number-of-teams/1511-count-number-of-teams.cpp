class Solution {
public:
    int numTeams(vector<int>& rating) {
int teams=0;
int n=rating.size();

for(int j=1;j<n-1;j++){
int i=0, countSmallerLeft=0, countLargerRight=0;
    while(i<j){
       if(rating[i]<rating[j]) countSmallerLeft++;
       i++;
    }
    int k=j+1;
    while(k<n){
        if(rating[j]<rating[k]) countLargerRight++;
        k++;
    }
    teams+=(countSmallerLeft*countLargerRight);
}

for(int j=1;j<n-1;j++){
int i=0, countLargerLeft=0, countSmallerRight=0;
    while(i<j){
       if(rating[i]>rating[j]) countLargerLeft++;
       i++;
    }
    int k=j+1;
    while(k<n){
        if(rating[j]>rating[k]) countSmallerRight++;
        k++;
    }
    teams+=(countLargerLeft*countSmallerRight);
}
return teams;
    }
};


// 1,2,                 3,7,4,5
// 2 smaller elements   j 3 larger elements 
// for any given j, find number of smaller elements than arr[j] ie n
// find number of larger element than arr[j] ie m and total possible elements that will
// follow arr[i]<arr[j]<arr[k] will be n*m
// follow the similar pattern for strictly decreasing element
// arr[i]>arr[j]>arr[k]