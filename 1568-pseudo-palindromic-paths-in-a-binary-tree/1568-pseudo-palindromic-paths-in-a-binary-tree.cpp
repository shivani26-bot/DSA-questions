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

void pallindromicPath(TreeNode* root,unordered_map<int,int> &umap, int &countPallindromicPath){
if(!root) return;
    umap[root->val]++;

if(!root->left && !root->right){
int countOddOccurences=0;
    for(const auto& i:umap){
      if(i.second%2!=0)  countOddOccurences++;
      }
    if(countOddOccurences<=1)  countPallindromicPath++;
}
    pallindromicPath(root->left,umap,countPallindromicPath);
    pallindromicPath(root->right,umap,countPallindromicPath);
    umap[root->val]--;
}

    int pseudoPalindromicPaths (TreeNode* root) {
       int countPallindromicPath=0;
       unordered_map<int,int>umap;
       pallindromicPath(root,umap,countPallindromicPath);
       return countPallindromicPath;
}

// int pseudoPalindromicPaths(TreeNode* root) {
//         unordered_map<int, int> freq;
//         int result = 0;
//         pathFinder(root, freq, result);
//         return result;
//     }

// private:
//     void pathFinder(TreeNode* root, unordered_map<int, int>& freq, int& result) {
//         if (root == nullptr) {
//             return;
//         }

//         freq[root->val]++;
//         // Check if it's a leaf node
//         if (root->left == nullptr && root->right == nullptr) {
//             if (isPseudoPalindromic(freq)) {
//                 result++;
//             }
//         }

//         pathFinder(root->left, freq, result);
//         pathFinder(root->right, freq, result);
//         freq[root->val]--; // Backtrack
//     }

//     bool isPseudoPalindromic(const unordered_map<int, int>& freq) {
//         int oddFreqCount = 0;
//         for (const auto& ele : freq) {
//             if (ele.second % 2 != 0) {
//                 oddFreqCount++;
//             }
//             if (oddFreqCount > 1) {
//                 return false;
//             }
//         }
//         return true;
//     }
};