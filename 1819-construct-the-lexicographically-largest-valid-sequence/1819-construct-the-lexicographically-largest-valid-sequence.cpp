class Solution {
public:

bool solve(vector<int>&result,vector<bool>&used,int idx,int n){
      
if(idx>=result.size()) return true;//guranteed answer, we are filling largest numbers  first
if(result[idx]!=-1) return solve(result,used,idx+1,n);//skip the number
      for(int num=n;num>=1;num--){
        if(used[num]==true) continue;
        //try to find the answer by placing the current number
        used[num]=true;
        result[idx]=num;

        //explore
        if(num==1){
            //place only once
            if(solve(result,used,idx+1,n)==true) return true;
        }
        else{
            // place twice 
            int j=idx+result[idx];
            //result[j] must not contain any number
            if(j<result.size() && result[j]==-1){
                result[j]=num;
                if(solve(result, used, idx+1,n)==true) return true;
                // if by placing that num at result[j] we don't get the answer then backtrack and place -1 
                result[j]=-1;
            }
        }
        //undo
        used[num]=false;
        result[idx]=-1;
        
      }
      return false;
}
    vector<int> constructDistancedSequence(int n) {
//         total size of array will be :2*n-1
//         becase all the numbers from 2 to n  occurs twice and only 1 occurs once
//         only numbers from 1 to n will occur in our sequence
//         first position ie index=0 will be taken by largest element as we need to find the lexicographically largest, corresponding we can find position for the same number twice
// n=3
// 3 _ _ _ _
// 3 _ _ 3 _
// 3 2 _ 3 _ we can't keep 2 as next index has 3
// 3 1 _ 3 _
// 3 1 2 3 2
// we can keep a used set or array to keep track of number used at current state 
// next index j for current element (2to n) will always be , j=i+nums[i]
// for any index i will try to put largest element first, if not possible move to second largest and so on, we have to explore different options
// if nums[i] is already populated then skip it

// n=4 size=2*4-1=7
// 4 _ _ _ _ _ _
// 4 _ _ _ 4 _ _
// 4 3 _ _ 4 _ _  not possible
// 4 2 _ 2 4 _ _
// 4 2 3 2 4 3 _
// 4 2 3 2 4 3 1

// we can return false if a path doesn't return a valid answer
// we are trying to generate all the sequences
// for every index we have n, n-1, n-2...1 possibilities
// n*n-1*n-2*..1 , o(n!)
// space:o(n+sizeof(used array)) depth of recursion tree
vector<int>result(2*n-1,-1);
vector<bool>used(n+1,false);
solve(result,used,0,n);
return result;
    }
};