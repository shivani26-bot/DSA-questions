class Solution {
public:
//  Input: "ABC"
//  all non-empty permutations of the characters of lengths 1 to 3.
// Length 1:A,B,C
// Length 2:AB,AC,BA,BC,CA,CB
// Length 3:ABC,ACB,BAC,BCA,CAB,CBA

// use backtracking for total number of possible sequences/permutations/subsets
// subsets+permutation 
// find the subset, for each subset find its permutation as well 
// skip the duplicate once, only store the unique answers 
// start the i=0;i<n;i++ for each recursive call only take the index which are not already taken in that recursive call 
// int solve(string tiles, vector<bool>&used){
//     int count=0;
//     for(int i=0;i<tiles.size();i++){
//         if(used[i] || (i>0 && tiles[i]==tiles[i-1] && !used[i-1])) continue;
//         used[i]=true;
//         count+=1+solve(tiles,used);
//         used[i]=false;
//     }
//     return count;
// }
//     int numTilePossibilities(string tiles) {
//         sort(tiles.begin(),tiles.end());
//         vector<bool>used(tiles.size(),false);
//         return solve(tiles,used);
//     }

// we can also take unordered set instead of vector of string for result 
// o(n!)
// o(n*n-1*n-2)
// space: o(n*n!)
//  vector<string>result;
// void solve(string tiles, vector<bool>&used,string temp){
//    result.push_back(temp);
//     for(int i=0;i<tiles.size();i++){
//         if(used[i] || (i>0 && tiles[i]==tiles[i-1] && !used[i-1])) continue;
//           used[i]=true;
//         temp.push_back(tiles[i]);
//         solve(tiles,used, temp);
//         temp.pop_back();
//            used[i]=false;
//     }
   
// }
//     int numTilePossibilities(string tiles) {
//         sort(tiles.begin(),tiles.end());
       
//         vector<bool>used(tiles.size(),false);
        
//         solve(tiles,used,"");
//         // for(int i=0;i<result.size();i++){
//         //     cout<<result[i]<<endl;
//         // }
//        return result.size()-1;
//     }


//store all the characters with its count and explore using backtracking
int count;
void solve(vector<int>& vec){
  count++;
    for(int i=0;i<26;i++){
        if(vec[i]==0) continue;
          vec[i]--;//do
          solve(vec);//explore
          vec[i]++;//undo
    }
   
}
    int numTilePossibilities(string tiles) {
       vector<int>vec(26,0);
       count=0;
       for(int i=0;i<tiles.size();i++){
        vec[tiles[i]-'A']++;
       }
       solve(vec);
       return count-1;//exclude empty sequence
    }
};