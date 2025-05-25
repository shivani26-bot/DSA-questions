class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n==2) return skill[0]*skill[1];
        int numberOfPairs= n/2;
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=skill[i];
        }
        if(totalSum%numberOfPairs!=0) return -1;
        int eachPairSum= totalSum/numberOfPairs;
int i=0,j=n-1;
sort(skill.begin(),skill.end());
long long chemistry=0;
while(i<=j){
    if(skill[i]+skill[j]!=eachPairSum) return -1;
    chemistry+=(skill[i]*skill[j]);
    i++;
    j--;
}
        return chemistry;
    }
};