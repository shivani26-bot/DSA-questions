/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// void solve(TreeNode* root, vector<int>&freq, int& countPaths){
// if(!root) return;
//     freq[root->val]++;
// if(!root->left && !root->right){
//     //when we are at leaf node, just iterate through the freq array, and find out how many elements has occured odd times, 
//     // if only one or less element has occured odd times it means its a palindromic path 
//     int countOddOccurence=0;
//     for(int i=0;i<10;i++){
//         if(freq[i]%2==1) countOddOccurence++;
//     }
//     if(countOddOccurence<=1) countPaths++;
// }
//     solve(root->left,freq,countPaths);
//     solve(root->right,freq,countPaths);
//     freq[root->val]--;

// }
//     int pseudoPalindromicPaths (TreeNode* root) {
//         // maintain a frequency array, as only 1 to 9 elements are present in the tree, 
//         vector<int>freq(10,0);
//         // traverse through each path, for each node value in the path increase the frequency,of that element, each index in the frequency array represents the possible node values in the tree 
//         int countPaths=0;
//  solve(root,freq,countPaths);
//     return countPaths;
//     }


//we can also use unordered map to keep account of how many times a element occured in a path
//     void pallindromicPath(TreeNode* root,unordered_map<int,int> &umap, int &countPallindromicPath){
// if(!root) return;
//     umap[root->val]++;

// if(!root->left && !root->right){
// int countOddOccurences=0;
//     for(const auto& i:umap){
//       if(i.second%2!=0)  countOddOccurences++;
//       }
//     if(countOddOccurences<=1)  countPallindromicPath++;
// }
//     pallindromicPath(root->left,umap,countPallindromicPath);
//     pallindromicPath(root->right,umap,countPallindromicPath);
//     umap[root->val]--;
// }

//     int pseudoPalindromicPaths (TreeNode* root) {
//        int countPallindromicPath=0;
//        unordered_map<int,int>umap;
//        pallindromicPath(root,umap,countPallindromicPath);
//        return countPallindromicPath;
// }


// using bit manipulation 
int countPaths=0;
void solve(TreeNode* root,int count){
if(!root) return;

    // in order to find the odd occurence
    // for every node in the path, (1<<root->val), and xor the final count, agr koi element even time aayega toh woh cancel ho jayega, end mei sirf ekk ya zero element ka bit set hoga , that means, uss path mei sirf ekk hi element odd times aaya hai, count yha pass by value hai toh hrr recursion step pe count ki apni calculated value hogi 
    count= count^(1<<root->val);
    // for ex: agr ekk path mei, 3 , do baar aaya hai toh, 1<<3, bit position 3 pe 1 do baar set hoga aur uska zero 0 aayega mtlb wo cancel out ho jayega
    // 0 0 0 1 0 0 0 ->3 (1<<3)
    // 0 0 0 1 0 0 0 ->3 (1<<3)
    // 0 0 0 0 0 0 0 xor
    // 0 0 0 0 1 0 0 ->2 (1<<2)
    // 0 0 0 0 1 0 0 xor
    // agr ekk bit hi set hai wo check krna hai toh
    // val&val-1==0, also tells ki power of two hai ya nhi 

    if(!root->left && !root->right){
//agr leaf node pe hai toh check krenge ki final count ki value mei sirf ekk bit set hai ya nhi, agr sirf ekk bit hi set hai it means ki sirf ekk element hi uss path mei odd times aaya hai
if((count & (count-1)) ==0) {
    countPaths++;
}
    }

    solve(root->left,count);
    solve(root->right,count);
}
    int pseudoPalindromicPaths (TreeNode* root) {
solve(root,0);
return countPaths;
    }
};