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


// class Solution {
// public:
// // time complexity:o(n)
//     long long dividePlayers(vector<int>& skill) {
//         int n=skill.size();
//          long long int sum=0;
//         for(int i=0;i<n;i++){  //o(n)
//             sum+=skill[i];
//         }
//         int total_pairs=n/2;
//         if(total_pairs==1) return skill[0]*skill[1];
//         if(sum%total_pairs!=0) 
//         {
//             return -1;
//         }
//         int target= sum/total_pairs;
//         unordered_map<int,int>mp;
//         int countPairs=0;
// cout<<target<<endl;
//         long long int chemistry=0;
//         for(int i=0;i<n;i++){ //o(n)
//                int num=target-skill[i];
//                if(mp.find(num)!=mp.end()){ //o(1)
//                    chemistry+= (skill[i]*num);
//                     mp[num]--;
//                     countPairs++;
//                     if(mp[num]==0) mp.erase(num);
//                }
//                else
//                mp[skill[i]]++;
//         }

// if(countPairs!=total_pairs || chemistry==0 ) return -1;

// return chemistry;
//     }
// };